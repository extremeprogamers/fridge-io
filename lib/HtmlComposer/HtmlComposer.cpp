#include "HtmlComposerImpl.h"

const char *HtmlComposerImpl::composeSite() {
    string t = "<!DOCTYPE html>\n"
               "<html>\n"
                 "<meta name=\"viewport\" content=\"width=device-width\">\n"
                 "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                 "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/materialize/1.0.0/css/materialize.min.css\">\n"
                 "<body>\n"
                   "<div class=\"container\">\n"
                     "<h3>Notes</h3>\n"
                       "<table>\n"
                         "<thead>\n"
                           "<tr>\n"
                             "<th>Note</th>\n"
                             "<th>Actions</th>\n"
                           "</tr>\n"
                         "</thead>\n";
    string t2 = composeGetMessages();
    string t3 = "</table>\n"
                "<br> <br> \n"
                "<form action=\"/\" method=\"post\">\n"
                "  <b>New note:</b> <input type=\"text\" name=\"note\">\n"
                "  <input class=\"waves-light btn green\" type=\"submit\" value=\"Add note\">\n"
                "</form>\n"
                "</div>\n"
                "</body>\n"
                "</html>";
    string out = t + t2 + t3;
    return out.c_str();
};

const char *HtmlComposerImpl::composeGetMessages() {
   return "";
 };

string HtmlComposerImpl::composeMessage(string msg) {
    return "<tbody>\n"
             "<tr>\n"
               "<td>"+ msg +"</td>\n"
               "<td><a href=\"/delete/"+ msg +"\" class=\"waves-effect waves-light btn red\">DELETE</a></td>\n"
             "</tr>\n"
           "</tbody>";
};

const char *HtmlComposerImpl::composeAdd(string msg, bool added) {
  return "";
};

const char *HtmlComposerImpl::composeRemoved(string msg, bool removed) {
  return "";
};
