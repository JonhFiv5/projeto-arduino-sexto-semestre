# Projeto Arduino | Sexto Semestre - UNINOVE
Projeto que consiste em automatizar um ventilador através da temperatura recuperada de uma API utilizando o ESP-01

## Configurando a IDE
Antes de tudo é preciso fazer com que a IDE do arduíno possa reconhecer e gravar em placas ESP8266. Para isso você precisa acessar <b>Arquivo > Preferências</b> e no campo <b>URLs adicionais para Gerenciadores de Placas</b> adicionar a URL: <a>https://arduino.esp8266.com/stable/package_esp8266com_index.json</a>
<br>Assim:
<a href="https://imgur.com/t43sUXu"><img src="https://i.imgur.com/t43sUXu.png" title="source: imgur.com" /></a>

## Fazendo o download das bibliotecas
Aqui estão as bibliotecas externas que foram utilizadas no projeto: <br>
* ArduinoJson (para leitura de JSON): 
  * https://github.com/bblanchon/ArduinoJson
* LiquidCrystal_I2C (para o módulo I2C, obtida no canal [Brincando com Ideias](https://www.youtube.com/watch?v=5OSPk5oHhVM)):
  * https://drive.google.com/file/d/1bSa5tyCN3MOfJj4zkT1RD-bnLCxr6tFv/view
