#include <string>
#include <list>
#include "EndpointDispatcher.h"

using namespace std;

EndpointDispatcher::EndpointDispatcher()
{
    database = new Database();
}

list<string> EndpointDispatcher::getMessages()
{
    return database->getAll();
}

void EndpointDispatcher::addMessage(string message)
{
    database->add(message);
}

void EndpointDispatcher::deleteMessage(string message)
{
    database->remove(message);
}