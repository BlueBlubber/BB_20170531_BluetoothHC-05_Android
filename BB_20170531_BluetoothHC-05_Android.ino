/*
 * Beispielcode von alexbloggt.de; man muss die Kabel nach seiner Abbildung verbinden, und den Code auch so verwenden, obwohl
 * bei ihm RXD und TXD dann nicht mit rxPin und txPin übereinstimmen.
 */

#include <SoftwareSerial.h>

#define ledPin 13
#define rxPin 1 // RXD des Sensors ist mit TX am Uno verbunden
#define txPin 0 // TXD des Sensors ist mit RX am Uno verbunden

SoftwareSerial btSerial(rxPin, txPin);
String btData;
String btData1;

void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
  btSerial.println("bluetooth available");
  Serial.println("bluetooth available");
  pinMode(ledPin, OUTPUT);
}
void loop() {
  if (btSerial.available() || Serial.available()) {
    btData1 = Serial.readString();
    btData = btSerial.readString();
    if (btData == "on" || btData1 == "on") {
      digitalWrite(ledPin, 1);
      btSerial.println("LED on Pin 13 is on_Bluetooth");
      Serial.println("LED on Pin 13 is on_Serial");
    }
    if (btData == "off" || btData1 == "off") {
      digitalWrite(ledPin, 0);
      btSerial.println("LED on Pin 13 is off_Bluetooth");
      Serial.println("LED on Pin 13 is off_Serial");
    }
  }
  delay(100);
}
