# Projeto Arduíno | Sexto Semestre - UNINOVE
Projeto que consiste em automatizar um ventilador através da temperatura, que está sendo recuperada de uma API utilizando o ESP-01
<br>
<a href="https://www.youtube.com/watch?v=bhNj7T8SkS8" target="_blank">Clique aqui para assistir uma demonstração do projeto.</a>

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

## API Utilizada
Nesse projeto está sendo utilizada a API gratuita disponibilizada pela OpenWeather. Para conseguir sua chave e conseguir usar a API, basta acessar o endereço https://openweathermap.org/ e criar sua conta, depois sua chave será enviada para o e-mail informado no cadastro. <br>
A cidade utilizada nesse exemplo foi São Paulo, que possui o código 3448439. Para buscar dados de uma cidade de sua escolha você poderá buscar pelo ID da cidade no arquivo JSON disponibilizado pela OpenWeather e acessível a partir do link http://bulk.openweathermap.org/sample/.

## Construção do Projeto
### Componentes Necessários
A lista de componentes utilizados no projeto são:
* 1 Arduíno Uno
* 1 protoboard
* 1 ESP-01
* 1 Adaptador 3.3V / 5V ESP-01
* 1 Relê
* 1 Display LCD 16x2
* 1 Módulo Serial I2C
* 1 Potenciômetro
* 1 LED
* 1 Resistor 220R
* Jumpers
<br>
<em>Nota: Nesse projeto o ventilador foi simulado utilizando o LED, do contrário não seria necessário o LED e o resistor.</em>

### Diagrama do projeto
<a href="https://imgur.com/9KHQv8P"><img src="https://i.imgur.com/9KHQv8P.png" title="source: imgur.com" /></a>

## Observações
### Programação do ESP-01
Para carregar e testar o código no ESP-01 foi utilizado o adaptador USB Serial para ESP-01, que aparece na imagem abaixo.
<br>
<a href="https://imgur.com/8Z9mYac"><img src="https://i.imgur.com/8Z9mYac.png" title="source: imgur.com" style="width: auto; height: 300px;"/></a>
<br>
Porém, o ESP-01 possui uma peculiaridade. Se simplesmente for encaixado no adaptador e colocado em uma porta USB ele irá começar a executar o código que já possui, assim como um arduíno quando conectado a uma fonte de alimentação. Para carregar um programa no ESP-01 é necessário que no momento em que for conectado à USB, o pino GND esteja conectado com o pino GPIO0. Uma forma simples de resolver isso é soldando um botão na parte traseira do adaptador ligando esses dois pinos, assim, ao encaixar o adaptador à USB, se estivermos pressionando o botão o ESP-01 irá iniciar em modo de gravação, se conectarmos sem pressionar o botão, irá entrar em modo de execução. O botão deve ser soldado da seguinte forma:<br>
<a href="https://imgur.com/jaJj2q9"><img src="https://i.imgur.com/jaJj2q9.png" title="source: imgur.com" style="width: auto; height: 300px;"/></a>

### Alterações no Código do ESP-01
Para que o código possa funcionar você deverar personalizar algumas linhas de código do arquivo do esp-01, que são as linhas 7, 8 e 13. Você precisará adicionar o SSID e PASSWORD da sua rede WiFi e também adicionar sua chave no link para a API. O ID da cidade é uma alteração opcional.

### Obtendo Parâmetros Diferentes da API
Sinta-se livre para utilizar o conhecimento disponibilizado aqui para consumir a API que deseja utilizando o ESP-01, esse componente tão legalzinho que aumenta bastante o poder do Arduíno 😄.<br>
As linhas de código utilizadas nesse projeto para recuperar os dados de temperatura a partir da resposta da API são:<br>
```
StaticJsonDocument<1024> doc;
DeserializationError error = deserializeJson(doc, http.getString());

JsonObject main = doc["main"];
int main_temp = main["temp"];
```
Esse código foi gerado pelo assistente da biblioteca ArduinoJson, que pode ser acessado no link https://arduinojson.org/v6/assistant/.
Seguindo o passo a passo no site, você deverá conseguir o código para resgatar quais dados desejar de uma API de sua escolha.
