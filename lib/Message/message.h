#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message {
  public:
    const int id;
    std::string message;

    Message(std::string m) : 
        id(maxId++),
        message(m)
    {}

  private:
    static int maxId;
};
#endif