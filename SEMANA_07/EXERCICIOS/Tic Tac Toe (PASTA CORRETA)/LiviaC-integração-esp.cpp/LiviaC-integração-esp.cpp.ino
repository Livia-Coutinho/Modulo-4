//Importação das bibliotecas
#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>  //Instalei o Arduino Json by Benoit Blanchon aqui na IDE mesmo
#include <WiFi.h>

#define green_led 6     //luz verde na porta 6
#define blue_led 15  //luz azul na porta 15

const char* SSID = "SHARE-RESIDENTE"; //Conexão à rede wi-fi que utilizo aonde moro (sim, meu computador está conectado a mesma rede wi-fi)
const char* PWD = "Share@residente";          //Como a internet aqui estava ruim, acabei trocando para o roteador do meu celular //Depois voltei para a do prédio

//Abaixo a função que capta as informações do servidor (app.js)
String getDataFromServer() {

  HTTPClient http;  //Instanciando o http

  http.begin("http://10.254.17.83:3000/esp/ganhador");  //Iniciação da rota que será buscada pela função
  http.addHeader("Content-Type", "application/json");

  StaticJsonDocument<200> res; 
  //Acima a criação da a váriavel do tipo "StaticJsonDocument" que suportará o formato JSON

  int httpResponseCode = http.GET();  //Verificação do código HTTP recebido

  
  if (httpResponseCode > 0) { //Funcionando, haverá um código HTTP que é maior que 0

    String response = http.getString();

    Serial.println(httpResponseCode);
    Serial.println(response);
    deserializeJson(res, response);


    String ganhador = res["ganhador"];
    Serial.println(ganhador);
    return ganhador; 
  }
}

void setup() {
  Serial.begin(115200);

  //Abaixo a configuração dos leds
  pinMode(6, OUTPUT);   //led vermelho, fio laranja
  pinMode(15, OUTPUT);  //led verde, fio branco

  //Conectando ao WIFI
  WiFi.begin(SSID, PWD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Tentando novamente!");
    delay(500);
  }

  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP()); 
}

void loop() {

  
  String ganhador = getDataFromServer();  //Para guardar em uma variável o retorno da função // String ganhador = getDataFromServer();

  //Parte em que checa a resposta e executa a ação (acender, ou não, os leds)
  if (ganhador == "X") {
    digitalWrite(6, HIGH);  //LED VERDE para o ganhador x
    digitalWrite (15, LOW);
  } else if (ganhador == "O") {
    digitalWrite(15, HIGH);   // digitalWrite(6, HIGH); 
    digitalWrite (6, LOW);
  } else if (ganhador == "EMPATE") {
    digitalWrite(15, HIGH);  //Ambas as luzes para empate!!!!!!!!!
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(15, LOW);
    digitalWrite(6, LOW);
  }
}