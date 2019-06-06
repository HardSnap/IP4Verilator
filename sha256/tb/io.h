#ifndef EXTERNAL_INTERFACE_H
#define EXTERNAL_INTERFACE_H

#include "simulator.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>

class IO {
public:

  IO(Simulator* _master) {
    master = _master;
    running = true;
  }

  ~IO() { stop(); };

  void input(uint32_t data, uint32_t address) {
    master->input(data, address);
  }

  uint32_t output(uint32_t address) {
    return master->output(address);
  }

  void run() {
    start();

    #define TEST_MODE 1
    #ifdef TEST_MODE
    input(0, 0xABABABAB);
    input(4, 0xABABABAB);
    input(8, 0xABABABAB);

    output(4);

    for(int k=0; k<100000; k++) {
      asm("nop");
    }
    return;
    #endif

    sync_mem_ptr[0] = 0;
    sync_mem_ptr[1] = 0;
    sync_mem_ptr[2] = 0;

    while(running) {
      // PACKETS : R/W[0], ADDRESS[1:4], DATA[5:8]
      unsigned char buffer[12] = {0};
      int n = 0;

      // if ((n = recv(client, buffer, sizeof buffer, 0)) < 0) {
      //   std::cout << "[Simulator::net] Unable to receive command" << std::endl;
      // }

      // std::cout << "[Simulator::net] Waiting for data on cmd_fifo" << std::endl;

      while (read(cmd_fifo, buffer, sizeof(buffer)) == 0);
      std::cout << "[Simulator::net] done" << std::endl;

      sync_mem_ptr[0] = 0;

      // if(n!= 12) {
      //   if(n>0)
      //     std::cout << "[Simulator::net] Bad packet of size " << n << std::endl;
      //   continue;
      // }
      // std::cout << "[Simulator::net] Good packet of size " << n << std::endl;

      uint32_t address  = *((uint32_t*)&buffer[4]);
      uint32_t data_in  = *((uint32_t*)&buffer[8]);
      uint32_t data_out = 0;

      for (unsigned int i = 0; i < n; i++) {
          printf("%d - ",buffer[i]);
      }
      printf("\n");

      switch(buffer[0]) {
        case 'W': {
          input(data_in, address);
        }
        break;
        case 'R': {
          data_out = output(address);

          char* res = new char[5];
          res[0] = data_out >> 24;
          res[1] = data_out >> 16;
          res[2] = data_out >> 8;
          res[3] = data_out & 0xFF;
          res[4] = 0;

          while(sync_mem_ptr[1] == 1);
          sync_mem_ptr[1] = 1;

          // std::cout << "[Simulator::net] Writing data on data_fifo" << std::endl;
          while( write(data_fifo, res, 5) == 0);
          // std::cout << "[Simulator::net] done" << std::endl;

          // if(send(client, res, 5, 0) == -1)
          // {
          //   std::cout << "[Simulator::net] Unable to send info to client" << std::endl;
          // }
        }
        break;
	default: {
           std::cout << "Bad packet ..." << std::endl;
        }
        break;
      }
    }
  }

  void stop() {
    // close(sockfd);
    // close(client);
  }

  bool running;

private:
  Simulator* master;

  // int sockfd;
  //
  // int client;
  //
  // int portno;

  int cmd_fifo;

  int data_fifo;

  void start() {

    return;
    const char* cmd_fifo_path = "/home/nasm/cmd_fifo";

    const char* data_fifo_path = "/home/nasm/data_fifo";

    if( mkfifo(cmd_fifo_path, 0666) != 0) {
      std::cout << "[Simulator::net] Failed to create cmd_fifo" << std::endl;
      exit(-1);
    }

    if( mkfifo(data_fifo_path, 0666) != 0) {
      std::cout << "[Simulator::net] Failed to create data_fifo" << std::endl;
      exit(-1);
    }

    cmd_fifo = open(cmd_fifo_path, O_RDONLY);

    data_fifo = open(data_fifo_path, O_WRONLY);

    std::cout << "[Simulator::net] Ready" << std::endl;
  }

  // void start() {
  //   portno = 2017;
  //
  //   socklen_t clilen;
  //
  //   struct sockaddr_in serv_addr, cli_addr;
  //
  //   sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //   if (sockfd < 0)
  //     std::cout << "[Simulator::net] ERROR opening socket" << std::endl;
  //
  //   bzero((char *)&serv_addr, sizeof(serv_addr));
  //
  //   serv_addr.sin_family = AF_INET;
  //   serv_addr.sin_addr.s_addr = INADDR_ANY;
  //   serv_addr.sin_port = htons(portno);
  //
  //   int yes = 1;
  //   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
  //     perror("setsockopt");
  //     exit(1);
  //   }
  //
  //   if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
  //     std::cout << "[Simulator::net] ERROR on binding socket" << std::endl;
  //     exit(1);
  //   }
  //
  //   listen(sockfd, 5);
  //
  //   clilen = sizeof(cli_addr);
  //
  //   std::cout << "[Simulator::net] Simulator is waiting for client connection" << std::endl;
  //
  //   client = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  //   if (client < 0) {
  //     std::cout << "[Simulator::net] ERROR on accept client" << std::endl;
  //     close(sockfd);
  //     exit(1);
  //   }
  //
  //   std::cout << "[Simulator::net] Ready" << std::endl;
  // }

};

#endif
