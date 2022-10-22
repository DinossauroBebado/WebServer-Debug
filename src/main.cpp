/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-async-web-server-espasyncwebserver-library/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <Arduino.h>
#include <html.h>

int ver = 0;
// Replace with your network credentials
const char* ssid = "CHERNOBYL_2G";
const char* password = "guithafer520";

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "state";

String outputState(int output){
  
  
    return String(output);
  
}
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);



// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h4>Output - GPIO 2\n" + outputState(ver) + "</h4>";
    buttons += "<h4>Output - GPIO 1\n" + outputState(3) + "</h4>";
    buttons += "<h4>Output - GPIO 3\n" + outputState(5) + "</h4>";
    return buttons;
  }
  return String();
}


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);


  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });


  

  // Start server
  server.begin();
}

void loop() {

  ver = ver+1; 
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  delay(100);

}