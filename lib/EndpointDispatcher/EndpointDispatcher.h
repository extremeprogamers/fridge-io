#ifndef FRIDGE1_ENDPOINT_DISPATCHER_H
#define FRIDGE1_ENDPOINT_DISPATCHER_H

#include <string>
#include <list>
#include "database.h"

using namespace std;

class EndpointDispatcher
{
private:
    Database *database;

public:
    EndpointDispatcher()
    {
        database = new Database();
    }
    const char *getMsgs();
    const char *postMsg(string msg, bool isValid);
    const char *deleteMsg(string msg, bool isValid);
};

#endif