class HtmlComposer {
    public:
    virtual const char* composeSite();
    virtual const char* composeGetMessages();
    virtual const char* composeMessage(string msg);
    virtual const char* composeAdd(string msg, bool added);
    virtual const char* composeRemoved(string msg, bool removed);
};