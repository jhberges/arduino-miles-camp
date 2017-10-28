int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledPin, random(255));
  delay(random(500));
//  analogWrite(ledPin, 0);
//  delay(random(500));
}
