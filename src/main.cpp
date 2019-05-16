// //
// // A simple server implementation showing how to:
// //  * serve static messages
// //  * read GET and POST parameters
// //  * handle missing pages / 404s
// //

// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <Hash.h>
// #include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include "EndpointDispatcher.h"

// const char *PARAM_MESSAGE = "message";

// AsyncWebServer server(80);

// const char *ssid = "YOUR_SSID";
// const char *password = "YOUR_PASSWORD";

// Database *db = new Database();
// HtmlComposerImpl *composer = new HtmlComposerImpl();
// EndpointDispatcher *dispatcher = new EndpointDispatcher(db, composer);

// void notFound(AsyncWebServerRequest *request)
// {
//     request->send(404, "text/plain", "Not found");
// }

// void setup()
// {

//     Serial.begin(115200);
//     WiFi.mode(WIFI_STA);
//     WiFi.begin(ssid, password);
//     if (WiFi.waitForConnectResult() != WL_CONNECTED)
//     {
//         Serial.printf("WiFi Failed!\n");
//         return;
//     }

//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());
//     Serial.print("Hostname: ");
//     Serial.println(WiFi.hostname());

//     server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request) {
//         request->send(200, "text/plain", dispatcher->getMsgs());
//     });

//     // Send a POST request to <IP>/post with a form field message set to <message>
//     server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request) {
//         if (request->hasParam(PARAM_MESSAGE, true))
//         {
//             String message = request->getParam(PARAM_MESSAGE, true)->value();
//             request->send(200, "text/plain", dispatcher->postMsg(message.c_str(), true));
//         }
//         else
//         {
//             request->send(200, "text/plain", dispatcher->postMsg("", false));
//         }
//     });

//     server.on("/delete", HTTP_DELETE, [](AsyncWebServerRequest *request) {
//         if (request->hasParam(PARAM_MESSAGE, true))
//         {
//             String message = request->getParam(PARAM_MESSAGE, true)->value();
//             request->send(200, "text/plain", dispatcher->deleteMsg(message.c_str(), true));
//         }
//         else
//         {
//             request->send(200, "text/plain", dispatcher->deleteMsg("", false));
//         }
//     });

//     server.onNotFound(notFound);

//     server.begin();
// }

// void loop()
// {
// }