#include <Adafruit_Si7021.h>
// From https://github.com/adafruit/adafruit_si7021
Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("All the sensors, all the time!");
  sensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = sensor.readTemperature();
  double humid = sensor.readHumidity();
  Serial.println("Current temp: " + String(temp));
  Serial.println("Current humid: " + String(humid));
  delay(3000);
}
