#ifndef ABTRACT_NET
#define ABSTRACT_NET

#include "stdint.h"

class Message;

/*
 * This is an abstract class to simplify the support of new comm. interface
 */
class AbstractNet {
public:
  virtual bool init() = 0;

  virtual bool shutdown() = 0;

  virtual void send(uint32_t data) = 0;

  virtual Message *receive() = 0;
};
#endif
