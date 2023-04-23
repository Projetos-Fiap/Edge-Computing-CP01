// CP01 de Edge Computing - Arduino
// Case Vinícula - Entrega: 04/04/2023
// Grupo: Alessandra, André, Bryan, Lucas e Vitor


// Definição dos pinos utilizados
const int ldrPin = 0;   // Pino analógico utilizado para leitura do LDR
const int greenLedPin = 11;   // Pino digital para o LED verde
const int yellowLedPin = 12;   // Pino digital para o LED amarelo
const int redLedPin = 13;   // Pino digital para o LED vermelho
const int buzzerPin = 10;   // Pino digital para o buzzer

// Definição dos limites para os níveis de luminosidade
const int okLevel = 900;   // Nível de luminosidade considerado OK
const int alertLevel = 950;   // Nível de luminosidade considerado de alerta

// Variáveis para armazenar os valores lidos do LDR
int ldrValue = 0;

// Variável para controle do tempo de acionamento do buzzer
unsigned long buzzerStartTime = 0;

void setup() {
  // Configuração dos pinos utilizados
  pinMode(ldrPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Desativa todos os LEDs e o buzzer
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  noTone(buzzerPin);
}

void loop() {
  // Leitura do valor do LDR
  ldrValue = analogRead(ldrPin);
  //ldrValue = 1000;
  
  // Verificação dos limites de luminosidade
  if (ldrValue <= okLevel) {
    // Luminosidade OK - aciona LED verde
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    
    // Desativa o buzzer
    noTone(buzzerPin);
  }
  else if (ldrValue <= alertLevel) {
    // Luminosidade em nível de alerta - aciona LED amarelo
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    
    noTone(buzzerPin);
  }
  else {
    // Luminosidade fora do limite - aciona LED vermelho
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);

    //digitalWrite(buzzerPin, HIGH);
    tone(buzzerPin, 1000); // liga o buzzer (1000 é o valor do tom)
   // delay(3000); // toca por 3 segundos
    //noTone(buzzerPin); // desliga o buzzer
   // delay(2000); // pausa por 2 segundos
  }
}