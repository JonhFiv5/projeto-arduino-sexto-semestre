#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// ADICIONE AS INFORMAÇÕES CORRESPONDENTES À SUA REDE
const char* ssid = "SEU_SSID"; //VARIÁVEL QUE ARMAZENA O NOME DA REDE SEM FIO
const char* password = "SEU_PASSWORD";//VARIÁVEL QUE ARMAZENA A SENHA DA REDE SEM FIO
String payload;

// ADICIONE SUA CHAVE NO PARAMETRO 'APPID'
// ALTERE O PARAMETRO 'ID' PELO ID DA CIDADE DESEJADA (ATUAL: SÃO PAULO)
const String endpoint = "https://api.openweathermap.org/data/2.5/weather?id=3448439&units=metric&APPID=SUA_CHAVE_DE_API";

WiFiClientSecure wifiClient;


void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  WiFi.begin(ssid, password);

  if (WiFi.status() == WL_NO_SHIELD) {
    //Serial.println("WiFi shield not present");
    // NÃO CONTINUA A EXECUÇÃO
    while (true);
  }

  // TENTA CONECTAR AO WIFI
  while (WiFi.status() != WL_CONNECTED) {
    // Serial.println("Conectando...");
    delay(1000);
  }
  
  // Serial.println("Conectado!");
}


void loop() {
  if ((WiFi.status() == WL_CONNECTED)) {
    // PERMITE UMA CONEXÃO INSEGURA COM A API HTTPS
    wifiClient.setInsecure();
    wifiClient.connect(endpoint, 80);
    
    HTTPClient http;
    http.begin(wifiClient, endpoint);
    int httpCode = http.GET();
    if (httpCode > 0) {
      // TESTE PARA VER SE HÁ RESPOSTA
      //payload = http.getString();
      //Serial.println(payload);

      // EXTRAINDO A TEMPERATURA DA RESPOSTA DA API
      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, http.getString());

      JsonObject main = doc["main"];
      int main_temp = main["temp"];
      Serial.print(main_temp);

    }
    http.end();
    // Serial.println("closed...");
  }
  delay(120000);
}
