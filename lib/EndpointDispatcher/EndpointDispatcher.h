#pragma once

#ifndef FRIDGE1_ENDPOINT_DISPATCHER_H
#define FRIDGE1_ENDPOINT_DISPATCHER_H

#include <string>
#include <list>
#include "database.h"
#include "HtmlComposerImpl.h"

using namespace std;

class EndpointDispatcher
{
private:
    AbstractDatabase *database;
    HtmlComposer *htmlComposer;

public:
    EndpointDispatcher(AbstractDatabase* db, HtmlComposer* comp)
    {
        this->database = db;
        this->htmlComposer = comp;
    }
    const char *getMsgs();
    const char *postMsg(string msg, bool isValid);
    const char *deleteMsg(string msg, bool isValid);
    void setDatabase(AbstractDatabase& new_database) {
        *database = new_database;
    }
    void setHtmlComposer(HtmlComposer& new_composer) {
        *htmlComposer = new_composer;
    }
};

#endif