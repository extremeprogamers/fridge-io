#ifndef FRIDGE1_ENDPOINT_DISPATCHER_H
#define FRIDGE1_ENDPOINT_DISPATCHER_H

#include <string>
#include <list>
#include "database.h"
#include "HtmlComposer.h"

using namespace std;

class EndpointDispatcher
{
private:
    Database *database;
    HtmlComposer *htmlComposer;

public:
    EndpointDispatcher()
    {
        database = new Database();
        htmlComposer = new HtmlComposer();
    }
    const char *getMsgs();
    const char *postMsg(string msg, bool isValid);
    const char *deleteMsg(string msg, bool isValid);
};

#endif