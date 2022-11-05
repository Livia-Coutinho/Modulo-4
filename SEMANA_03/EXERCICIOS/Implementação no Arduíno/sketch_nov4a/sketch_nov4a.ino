#include <Arduino.h>

#define red_led 1 //#define - nomear um valor constante
#define green_led 42
#define yellow_led 39
#define blue_led 36 //white
#define ldr_sensor 14
#define buzzer 8


#define first_button 4//(green)
#define second_button 5 //(red)

int vetor[4]; //variável global
int valores[100]; //valores que serão salvos (stocked vetor) - armazenamento
int posAtual = 0; //posição atual
 
//Funções dos microcontroladores - setup e loop

void setup() {
  Serial.begin(115200); //para iniciar o serial monitor (tipo de comunicação)
  
  pinMode(red_led, OUTPUT); //pinMode - configurar como entrada ou saída
  pinMode (green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(blue_led, OUTPUT);

  //pinMode(1, OUTPUT); //pinMode - configurar como entrada ou saída
  //pinMode (42, OUTPUT);
  //pinMode(39, OUTPUT);
  //pinMode(36, OUTPUT);
  
  pinMode(first_button, INPUT_PULLUP);
  pinMode(second_button, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  pinMode(ldr_sensor, INPUT);
}

void convert_binary(int number){ //função para converter decimal em binário em C++
  for(int i = 0; i < 4; i++){ //(inicialização, condição, efeito)
    vetor[i] = number % 2; //dividir pegando o resto
    number = number / 2; //novo resultado
  }
}

void read(int number) {

  int leds[4] = {1, 42, 39, 36};
  convert_binary(number);

  /*
  for (int i =0; i < 4; i++) {
    if (vetor[i]==1){
      digitalWrite(leds[i], HIGH);
    } else if (vetor[i] == 0) {
      digitalWrite(leds[i], LOW);
    }
  }
  */
    
    if (vetor[1]==1){
      digitalWrite(leds[1], HIGH);
    } else if (vetor[1]==0) {
      digitalWrite(leds[1], LOW);
    }

    if (vetor[42]==1){
      digitalWrite(leds[42], HIGH);
    } else if (vetor[42]==0) {
      digitalWrite(leds[42], LOW);
    }

    if (vetor[39]==1){
      digitalWrite(leds[39], HIGH);
    } else if (vetor[39]==0) {
      digitalWrite(leds[39], LOW);
    }

    if (vetor[36]==1){
      digitalWrite(leds[36], HIGH);
    } else if (vetor[36]==0) {
      digitalWrite(leds[36], LOW);
    }
    
}


int stockVetor (int number, int position){
  valores[position] = number;
  read(number);
  buzz(number);
  return position + 1;
}

void buzz(int number){
  tone(8, 100*number, 100); //(pino, frequência, tempo em milissegundos)
}


void loop() { 
  int ldr_variable = analogRead(14); //(2)porta em localiza-se o LDR
  //Serial.println(ldr_variable);
  int ldr_value = (ldr_variable/270); //(escala - 4063-->32) 4063:15= 270,8
 // Serial.println(ldr_value); //verificação da divisão acima

  
  if (digitalRead(4)==LOW){ //porta do botão
    //Serial.println("Livia Coutinho"); //para testar o botão 
    posAtual = stockVetor(ldr_value, posAtual);
    while (digitalRead(4) == LOW) {}
  }

  
  if(digitalRead(5)==LOW){ //porta do botão
    Serial.println("Lendo");
    for(int index=0; index < posAtual; index++) {
      //read(valores[index]);
      buzz(valores[index]);

      delay(1000);
    }
    
  }

  //digitalWrite(1, HIGH); //digitalWrite(porta, intensidade)
  //delay(1000); 
  //digitalWrite(42, HIGH);
  //digitalWrite(39, HIGH);
  //digitalWrite(36, HIGH); //as linhas acima foram apenas para testar os leds antes de fazer, de fato, as funções
  delay(500); //equivale a meio segundo
}