#ifndef FRIDGE1_ENDPOINT_DISPATCHER_H
#define FRIDGE1_ENDPOINT_DISPATCHER_H

#include <string>
#include <list>
#include "database.h"

using namespace std;

class EndpointDispatcher
{
private:
    Database* database;

public:
    EndpointDispatcher::EndpointDispatcher();
    list<string> getMessages();
    void addMessage(string message);
    void deleteMessage(string message);
};

#endif