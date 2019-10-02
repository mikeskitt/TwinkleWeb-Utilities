#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
const char* ssid = "TP-LINK_C9701C"; 
const char* password = "6c4a61bbbd"; 
const char* host[] = {"http://192.168.1.252",
                      "http://192.168.1.251",
                      "http://192.168.1.250"}; //edit the host adress, ip address etc. 
String url = "/led"; 

void setup() 
{ 
Serial.begin(115200); 
delay(10); // We start by connecting to a WiFi network 
Serial.println(); 
Serial.println(); Serial.print("Connecting to "); 
Serial.println(ssid); 
/* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default, would try to act as both a client and an access-point and could cause network-issues with your other WiFi-devices on your WiFi-network. */ 
WiFi.mode(WIFI_STA); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) 
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println(""); 
Serial.println("WiFi connected"); 
Serial.println("IP address: "); 
Serial.println(WiFi.localIP()); } 
int value = 0; 

void loop() 
{ 
delay(10000); 
for(int n=0;n<=2;n++){
Serial.print("connecting to "); 
Serial.println(host[n]); // Use WiFiClient class to create TCP connections 
WiFiClient client; 
const int httpPort = 80; 
if (!client.connect(host[n], httpPort)) 
{ 
Serial.println("connection failed"); 
return; 
} 
Serial.print("Requesting URL: "); 
Serial.println(url); //Post Data 
String postData = "effet=8";
String address = host[n] + url; 
HTTPClient http; 
http.begin(address); 
http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
auto httpCode = http.POST(postData); 
Serial.println(httpCode); //Print HTTP return code 
String payload = http.getString(); 
Serial.println(payload); //Print request response payload 
http.end(); //Close connection Serial.println(); 
Serial.println("closing connection"); 
}
delay(40000);
} 
