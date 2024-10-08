#include <SPI.h> //sensor
#include <MFRC522.h> //sensor

#define SS_PIN 10 //sensor
#define RST_PIN 9 //sensor

int sensorState = 0;
int buzzer = 3;

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{
  pinMode(7, OUTPUT); // LED
  pinMode(2, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop()
{
  sensorState = digitalRead (2);
  if (sensorState == HIGH) {
    digitalWrite(7, HIGH);
    tone(buzzer, 300, 1000);
    Serial.println("Sensor Ligado");
  } 
   // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= ""; 

  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  
  content.toUpperCase();
  if (content.substring(1) == "C6 66 A1 AC" ){
    digitalWrite (7, LOW); 
    noTone(buzzer);
    Serial.println("Sensor Desligado");
  }
  
  /*else {
    digitalWrite (7, LOW); 
    noTone(buzzer);
    Serial.println("Sensor Desligado");
  }*/
  delay(500);
}