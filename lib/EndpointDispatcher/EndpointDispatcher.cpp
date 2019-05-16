#include <string>
#include <list>
#include <iostream>
#include "EndpointDispatcher.h"

using namespace std;

const char *EndpointDispatcher::getMsgs()
{
    return this->htmlComposer->composeGetMessages();
}

const char *EndpointDispatcher::postMsg(string msg, bool isValid)
{
    if (isValid)
    {
        database->add(msg);
        return htmlComposer->composeAdd(msg, true);
    }
    else
    {
        return htmlComposer->composeAdd(msg, false);
    }
}

const char *EndpointDispatcher::deleteMsg(string msg, bool isValid)
{

    if (isValid)
    {
        database->remove(msg);
        return htmlComposer->composeRemoved(msg, true);
    }
    else
    {
        return htmlComposer->composeRemoved(msg, false);
    }
}