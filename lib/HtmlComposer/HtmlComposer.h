#pragma once

#include <string>
#include "database.h";

using namespace std;

class HtmlComposer
{
public:
    virtual const char *composeSite() = 0;
    virtual const char *composeGetMessages() = 0;
    virtual const char *composeMessage(string msg) = 0;
    virtual const char *composeAdd(string msg, bool added) = 0;
    virtual const char *composeRemoved(string msg, bool removed) = 0;
    virtual ~HtmlComposer() {}
};