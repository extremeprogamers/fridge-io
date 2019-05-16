#pragma once

#include "HtmlComposer.h"

class HtmlComposerImpl : public HtmlComposer
{

private:
    Database *db;

public:
    const char *composeSite();
    const char *composeGetMessages();
    string composeMessage(string msg);
    const char *composeAdd(string msg, bool added);
    const char *composeRemoved(string msg, bool removed);
    ~HtmlComposerImpl() {}
};