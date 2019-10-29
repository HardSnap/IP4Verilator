#ifndef MKFIFO_NET_NET
#define MKFIFO_NET_NET

#include "abstract_net.h"
#include "stdint.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

class Message;

/*
 * This is an abstract class to simplify the support of new comm. interface
 */
class MKFifo : public AbstractNet {
public:
  bool init();

  bool shutdown();

  void send(uint32_t data);

  void irq();

  Message *receive();

private:
  unsigned char *sync_mem_ptr;

  int cmd_fifo;

  int data_fifo;
};
#endif
