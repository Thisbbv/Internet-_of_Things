#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  
  // CARRO
  pinMode(8, OUTPUT); // VERMELHO CARRO
  pinMode(9, OUTPUT); // AMARELO CARRO
  pinMode(10, OUTPUT); // VERDE CARRO
  // PEDESTRE
  pinMode(12, OUTPUT); // VERMELHO PEDESTRE
  pinMode(11, OUTPUT); // VERDE PEDESTRE
  
  // TESTE DE SETUP
  //lcd.begin(16, 2);
  //Serial.begin(9600);
  //lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  //lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  //lcd.clear(); // LIMPA O DISPLAY

  //lcd.print("- Ola, Mundo! -");
  //delay(5000); // DELAY DE 5 SEGUNDOS
  //lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  //lcd.print("Fim do Setup ()");
  //delay(5000); // DELAY DE 5 SEGUNDOS
  
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  //delay(2000); // DELAY DE 2 SEGUNDOS
  //lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  //delay(2000); // DELAY DE 2 SEGUNDOS
  
  //lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
}

void loop() {

// LIGANDO O DISPLAY
lcd.init();
lcd.backlight();
 
// LIGA VERMELHO CARRO E VERDE PEDESTRE
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("VERMELHO CARRO");
lcd.setCursor(0, 1);
lcd.println("E VERDE PEDESTRE");
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
delay(2000);
  
// LIGA VERDE CARRO E VERMELHO PEDESTRE
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("VERDE CARRO");
lcd.setCursor(0, 1);
lcd.println("E VERMELHO PEDESTRE");
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
digitalWrite(11, LOW);
digitalWrite(12, HIGH);
delay(3000);

// LIGA AMARELO CARRO E VERMELHO PEDESTRE
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("AMARELO CARRO");
lcd.setCursor(0, 1);
lcd.println("E VERMELHO PEDESTRE");
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
digitalWrite(11, HIGH);
digitalWrite(12, LOW);
delay(1000);
}
