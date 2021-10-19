#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


// INFORMAÇÕES DO DISPLAY
#define ENDERECO 0x27
#define COLS 16
#define ROWS 2

#define POTENCIOMETRO A0
#define RELE 8

LiquidCrystal_I2C lcd(ENDERECO, COLS, ROWS);
SoftwareSerial ESP_Serial(7, 6); //TX, RX

int tempAtivacao, tempAtivacaoOld, tempAtual, tempAtualOld;
bool tempAtualDefinida;


void atualizarDisplay();


void setup() {
  ESP_Serial.begin(9600);
  Serial.begin(9600);
  pinMode(RELE, OUTPUT);

  tempAtualDefinida = false;
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  lcd.setCursor(0, 0);
}


void loop() {
  // REGISTRANDO A TEMPERATURA DE ATIVAÇÃO ATRAVÉS DO POTENCIOMETRO
  tempAtivacaoOld = tempAtivacao;
  tempAtivacao = map(analogRead(POTENCIOMETRO), 0, 1023, 18, 40);


  // RECUPERANDO A TEMPERATURA ATUAL
  if (ESP_Serial.available() > 0) {
    tempAtualOld = tempAtual;
    tempAtual = ESP_Serial.readString().toInt();
    tempAtualDefinida = true;
  }

  // ATUALIZANDO O DISPLAY EM CASO DE NOVOS DADOS
  if ((tempAtivacao != tempAtivacaoOld) || (tempAtual != tempAtualOld)) {
    atualizarDisplay(tempAtivacao, tempAtual);
  }

  // CONTROLE DO RELE
  if ((tempAtualDefinida) && (tempAtual >= tempAtivacao)) {
    digitalWrite(RELE, HIGH);
  } else {
    digitalWrite(RELE, LOW);
  }

  delay(500);
}


void atualizarDisplay(int temperaturaAtivacao, int temperaturaAtual) {
  Serial.println("Display atualizado");
  lcd.clear();
  
  // EXIBINDO TEMEPERATURA DEFINIDA PELO POTENCIOMETRO
  lcd.setCursor(0, 0);
  lcd.print("Liga em: ");
  lcd.print(temperaturaAtivacao);
  lcd.print(" C");

  // EXIBINDO TEMPERATURA RECUPERADA PELA API
  lcd.setCursor(0, 1);
  lcd.print("Atual: ");
  if (tempAtualDefinida) {
    lcd.print(temperaturaAtual);
    lcd.print(" C");
  } else {
    lcd.print("loading...");
  }
}
