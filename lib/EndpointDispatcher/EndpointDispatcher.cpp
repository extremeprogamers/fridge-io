#include <string>
#include <list>
#include "EndpointDispatcher.h"

using namespace std;

const char *EndpointDispatcher::getMsgs()
{
    return database->getAll()[0].c_str();
}

const char *EndpointDispatcher::postMsg(string msg, bool isValid)
{
    if (isValid)
    {
        database->add(msg);
        return "Work";
    }
    else
    {
        return "Fail";
    }
}

const char *EndpointDispatcher::deleteMsg(string msg, bool isValid)
{

    if (isValid)
    {
        database->remove(msg);
        return "Work";
    }
    else
    {
        return "Fail";
    }
}