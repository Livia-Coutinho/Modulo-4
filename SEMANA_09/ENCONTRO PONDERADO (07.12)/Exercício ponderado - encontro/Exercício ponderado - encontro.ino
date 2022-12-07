//EXERCÍCIO - ENCONTRO PONDERADO - SEMANA 9 (07 DE DEZEMBRO DO ANO 2022)
//LIVIA COUTINHO - TURMA 1 

#include <Arduino.h> //apoio para a função Main
#include <ArduinoJson.h> //baixei a lib ArduinoJSon by Benoit Blanchon
#include <HTTPClient.h> //execução das solicitações HTTP
#include <WiFi.h> //para a comunicação com a internet

#include <stdio.h> //
#include <String> //para concatenação 

const char* SSIDS = "Sou lindo"; //Vetores com nomes de rede e senhas dos Access Points
const char* PWD = "vitorteamo"; //Usando o Mobile Hotspot de um colega por falhas na conexão Inteli-COLLEGE

char * mensagem; //mensagem!!!

char converter(char ch, int chave) {
  if (!isalpha(ch)) return ch; //exclamação - negativo  //isalpha checa se trata-se de alfabeto, ou não
  char offset = isupper(ch) ? 'A' : 'a'; //isupper - verificação de letras maiúsculas
  return (char)((((ch + chave) - offset) % 26) + offset); 
}

String criptografar(String entrada, int chave) {
  String saida = "";
  size_t len = entrada.length();
  for (size_t i = 0; i < len; i++)
    saida += converter(entrada[i], chave);
  return saida;
}


void postDataToServer() {                      //UTILIZAÇÃO DO MÉTODO POST
 
  Serial.println("Posting JSON data to server...");         
  HTTPClient http;   

  String mensagem_cripto = criptografar("Ansiosa por minhas mini férias", 22);
     
    http.begin("https://ur524n-3000.preview.csb.app/teobaldo");  //link enviado pelo professor no Slack
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc;
 
    doc["nome"] = "Livia Coutinho";
    doc["turma"] = 1;
    doc["grupo"] = 2;
    doc["mensagem_de_texto"] = "Ansiosa por minhas mini férias";
    doc["mensagem_de_cripto"] = mensagem_cripto; //(char declarada acima) //a mensagem deve sair conforme código

    JsonArray data = doc.createNestedArray("data");   // Add an array.    
     
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpResponseCode = http.POST(requestBody);
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
     
    }

}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); 
  WiFi.begin(SSIDS, PWD); //inicialização do #include <WiFi.h>
}

void loop() {
  postDataToServer();
  delay(8000);
}

