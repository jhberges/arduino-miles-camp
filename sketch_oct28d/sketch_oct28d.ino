#include <SPI.h>
#include <WiFi101.h>


#include <Adafruit_Si7021.h>
// From https://github.com/adafruit/adafruit_si7021

char ssid[] = "Sola Strand Hotel";
//char ssid[] = "jhb";
//char pass[] = "bhjbhjbhj";
int status = WL_IDLE_STATUS;
char server[] = "skarboviktestfunc01.azurewebsites.net";    
WiFiClient client;

Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  WiFi.setPins(8,7,4);

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid);//, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();
  Serial.println("All the sensors, all the time!");
  sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = sensor.readTemperature();
  double humid = sensor.readHumidity();
  Serial.println("Current temp: " + String(temp));
  Serial.println("Current humid: " + String(humid));
  
  if (client.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET http://skarboviktestfunc01.azurewebsites.net/api/HttpToDB?temp=" + String(temp) + "&humidity=" + String(humid) + "&boxid=17&code=30aY9M4my7/DF0xED0rZOD5Nug4utCwq3MAf2VhymwW2ZPxGbHzOJw== HTTP/1.1");
    client.println("Host: skarboviktestfunc01.azurewebsites.net");
    client.println("Connection: close");
    client.println();
    client.stop();
  } else {
    Serial.println("No connect?");
  }
  delay(3000);
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}



