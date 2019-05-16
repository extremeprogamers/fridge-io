#pragma once

#include "HtmlComposer.h"

class HtmlComposerImpl: public HtmlComposer {
    public:
    const char* composeSite();
    const char* composeGetMessages();
    const char* composeMessage(string msg);
    const char* composeAdd(string msg, bool added);
    const char* composeRemoved(string msg, bool removed);
    ~HtmlComposerImpl() {}
};