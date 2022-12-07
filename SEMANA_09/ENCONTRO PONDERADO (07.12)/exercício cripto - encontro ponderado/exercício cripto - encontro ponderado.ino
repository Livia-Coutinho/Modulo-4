//EXERCÍCIO - ENCONTRO PONDERADO - SEMANA 9 (07 DE DEZEMBRO DO ANO 2022)
//LIVIA COUTINHO - TURMA 1 

#include <Arduino.h> //apoio para a função Main
#include <ArduinoJson.h> //baixei a lib ArduinoJSon by Benoit Blanchon
#include <HTTPClient.h> //execução das solicitações HTTP
#include <WiFi.h> //para a comunicação com a internet

#include <stdio.h>
#include <>

#define SERVIDOR_ENVIO "https://ur524n-3000.preview.csb.app/teobaldo"

const char* SSIDS = "Inteli-COLLEGE"; //Vetores com nomes de rede e senhas dos Access Points
const char* PWD = "QazWsx@123";

const char*
void postDataToServer() {
 
  Serial.println("Posting JSON data to server...");         // Block until we are able to connect to the WiFi access point
  HTTPClient http;   
     
    http.begin("https://1n0rn2-3000.preview.csb.app/teobaldo");  
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc;
 
    doc["nome"] = "Livia Coutinho";
    doc["turma"] = 1;
    doc["grupo"] = 2;
    doc["mensagem_de_texto"] = "Ansiosa por minhas mini férias";
    doc["mensagem_de_cripto"] = 

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


void getDataFromServer() {
 
  Serial.println("Pegando dados do Servidor...");

  HTTPClient http;     // Block until we are able to connect to the WiFi access point
     
    http.begin("https://1n0rn2-3000.preview.csb.app/teobaldo");  
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc;
     
    int httpResponseCode = http.GET();
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
      deserializeJson(doc, response);
      int action = doc["action"];
      String sensor = doc["sensor"];
      String status1 = doc["status"];
      //Exemplo no caso de vetores/arrays no JSON
      //double latitude = doc["data"][0];
      //double longitude = doc["data"][1];
      Serial.println(action);
      Serial.println(sensor);
      Serial.println(status1);
    }
     
}

void EnviarDados(int rede)     //Utilizado na função CONECTAR, para continuar mostrando os dados da conexão enquanto permanecer conectado
{
  WiFi.begin(SSIDS,PWD);
      while (WiFi.status() != WL_CONNECTED) {
        Serial.print("Tentando novamente!");
        delay(500); 
      }

     Serial.println("WiFi connected");
  
    postDataToServer();    //DadosConexao();    
    
}

// void ReceberDados(int rede)
// {
//   Serial.println("Conectando na rede: ");

//   WiFi.begin(SSIDS,PWD);
//       while (WiFi.status() != WL_CONNECTED) {
//         Serial.print("Tentando novamente!");
//         delay(500);
//       }
//         Serial.println("WiFi connected");
//         //DadosConexao();
//         getDataFromServer();  
      
// }

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); 
}

void loop() {

  Serial.println("Enviando: ");
  EnviarDados(0);
  delay(8000);
}
