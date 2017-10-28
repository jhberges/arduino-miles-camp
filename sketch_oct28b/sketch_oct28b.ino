
void setup() {
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("I am An Arghuino! Tremble before me!");
}


void loop() {
  int i = 0;
  while (i<1000) {
    i++;
    Serial.println(" --> " + String(i));
    delay(1000);
  }
}

