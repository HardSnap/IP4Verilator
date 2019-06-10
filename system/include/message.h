#ifndef MESSAGE_H

class Message {
public:
  unsigned int address;

  unsigned int data;

  unsigned char type;

  Message(unsigned int _address, unsigned int _data, unsigned char _type)
      : address(_address), data(_data), type(_type){};
};

#endif
