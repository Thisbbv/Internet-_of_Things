#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;

Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";
const int SENSOR_LUZ = 7;
const int SENSOR_LUX = 6;

void setup() {
  Serial.begin(9600);

  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //Inicialização do display com a biblioteca e endereço de hardware do display;
  pinMode(SENSOR_LUZ, INPUT);
  pinMode(SENSOR_LUX, INPUT);
}

void loop() {

  int proximidade = digitalRead(SENSOR_LUZ);
  int proximilux = digitalRead (SENSOR_LUX);

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od
  display.setCursor(35, 10); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("Campo"); //Texto a ser escrito;
  display.setCursor(30, 25);
  display.print("Luminoso"); //Texto a ser escrito;


 if (proximidade == HIGH){
  display.setFont(&FreeMono9pt7b);
  display.setCursor(50, 40);
  display.print("Preto");
  Serial.println("Preto ou nada");
  display.display();
 }
  else
 if (proximidade == LOW){
  display.setFont(&FreeMono9pt7b);
  display.setCursor(15, 50);
  display.print("Branco");
  Serial.println("Branco");
 }

  Serial.println(proximidade);
  display.display();
}

