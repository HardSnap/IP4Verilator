#ifndef NET_H
#define NET_H

#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

class Net {
private:
  uint32_t port;

  struct sockaddr_in serv_addr;

  struct sockaddr_in cli_addr;

  uint32_t client_socket;

  uint32_t server_socket;

public:
  Net(uint32_t _port) { port = _port; }

  bool init() {}

  bool init_socket() {
    socklen_t clilen;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
      spdlog::error("Unable to create socket...");
      return false;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
  }

  bool init_sock_option() {

    int yes = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes,
                   sizeof(int)) == -1) {
      // perror("setsockopt");
      spdlog::error("Failed to set setsockopt");
      return false;
    }
  }

  bool bind_socket() {

    if (bind(server_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <
        0) {
      spdlog::error("Could not bind socket");
      return false;
    }

    listen(server_socket, 5);
  }

  bool wait_client() {
    clilen = sizeof(cli_addr);

    spdlog::info("Server is waiting for new client...");

    client = accept(server_socket, (struct sockaddr *)&cli_addr, &clilen);
    if (client < 0) {
      spdlog::info("Could not accept client connexion");
      close(server_socket);
      return false;
    }

    spdlog::info("Client connection accepted...");
  }

  Message *get_pending_message() {

    // address = *((uint32_t *)&buffer[4]);
    // data_in = *((uint32_t *)&buffer[8]);
    // action = buffer[0];

    Message *message = new Message();

    return message;
  }
};

#endif
