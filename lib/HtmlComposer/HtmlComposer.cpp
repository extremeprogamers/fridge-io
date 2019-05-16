#include "HtmlComposerImpl.h"

const char *HtmlComposerImpl::composeSite() { return ""; };
const char *HtmlComposerImpl::composeGetMessages()
{
    vector<string> msgs = db->getAll();
    
    return "";
};
const char *HtmlComposerImpl::composeMessage(string msg) { return ""; };
const char *HtmlComposerImpl::composeAdd(string msg, bool added) { return ""; };
const char *HtmlComposerImpl::composeRemoved(string msg, bool removed) { return ""; };