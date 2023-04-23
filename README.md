# Edge-Computing-CP01

<h3>Check Point 01: Monitorador de Luminosidade</h3>

<p>Aqui é apresentada a simuação de um circuito monitorador de luminosidade integrado a um indicador e a um alarme.
<br>
<br>O circuito utiliza o Arduino Uno R3.
<br>
<br>O código da lógica se encontra no arquivo alarmeDeNivelLuminoso.ino.
<br>
<br>O esquema do circuito pode ser encontrado o arquivo CP 01 - Edge.png.
<br>
<br>Este projeto foi desenvolvido no Tinkercad.<p>

<h4>Integrantes:</h4> 

<li>Alessandra Vaiano RM551497</li>  

<li>André Lambert RM99148</li>  

<li>Bryan Willian RM551305</li>

<li>Lucas Feijó RM99727</li>
  
<li>Vitor Maia RM99658</li>

<h4>Vídeo explicativo:</h4>
https://www.youtube.com/watch?v=op-k5Y6VHtw&classId=8eef2966-bc30-4054-8c2f-130df0861af8&assignmentId=a80202fe-ac06-425d-91a4-dbf58a4b3d8f&submissionId=dd441e90-30d8-917b-6f3f-e49a44078415

<br><b>Materiais utilizados:</b>
<li>1 Arduino Uno R3</li>
<li>1 Protoboard</li>
<li>1 Resistor 10 kΩ</li>
<li>1 LED Vermelho</li>
<li>1 LED Amarelo</li>
<li>1 LED Verde</li>
<li>1 Piezo</li>
<li>1 Fotorresistor</li>
<li>Jumper Cables</li>

<br><b>Imagem:</b>

![CP 01 - Edge](https://user-images.githubusercontent.com/126624520/233856907-0710e787-5803-4717-baf5-7c602ec11e2c.png)

<b>Indicador:</b>

O indicador é composto por 3 LEDs que são acesos conforme o nível de luminosidade lido pelo sensor.

<b>Alarme:</b>

O alarme é composto por uma buzina (buzzer) que apita quando o nível de luminosidade for crítico.

<b>Funcionamento:</b>

Enquanto o nível de luminosidade estiver aceitável apenas o LED verde se acenderá; enquanto o nível de luminosidade estiver alarmante apenas o LED amarelo se acenderá; enquanto o nível de luminosidade estiver crítico o LED vermelho se acenderá e a buzina apitará por 3 segundos antes de checar novamente o valor da luminosidade. Os valores de luminosidade a serem considerados como aceitável, alarmante e crítico são arbitrários e devem ser alterados coforme a necessidade.

<b>Reproduzir o projeto no Tinkercard</b>
<br>https://www.tinkercad.com/things/cg0zTIgJ4Aw-copy-of-cp01-edge-final/editel?tenant=circuits&classId=8eef2966-bc30-4054-8c2f-130df0861af8&assignmentId=a80202fe-ac06-425d-91a4-dbf58a4b3d8f&submissionId=dd441e90-30d8-917b-6f3f-e49a44078415</h4> 

Acesse ou crie uma conta no Tinkercad e acesse o link e copiar a simulação.

Abra a cópia da simulação e no canto superior direito clique em "Iniciar simulação".

Para variar o nivel de luinosidade basta clicar no LDR e alterar conforme desejar no medidor.

Os valores limites de luminosidade aceitável e luminosidade alarmante poder ser editados nas linhas 14 e 15, respectivamente.

Serão considerados críticos os valores maiores que o valor limite de luminosidade alarmante (linha 15).

<b>Código:</b>

const int ldrPin = A0;
<br>const int greenLedPin = 2;
<br>const int yellowLedPin = 1;
<br>const int redLedPin = 0;
<br>const int buzzerPin = 4;
<br>
const int okLevel = 900;
<br>const int alertLevel = 950;

int ldrValue = 0;

unsigned long buzzerStartTime = 0;

void setup() {
<br>  pinMode(ldrPin, INPUT);
<br>  pinMode(greenLedPin, OUTPUT);
<br>  pinMode(yellowLedPin, OUTPUT);
<br>  pinMode(redLedPin, OUTPUT);
<br>  pinMode(buzzerPin, OUTPUT);

  digitalWrite(greenLedPin, LOW);
<br>  digitalWrite(yellowLedPin, LOW);
<br>  digitalWrite(redLedPin, LOW);
<br>  noTone(buzzerPin);
<br>}

void loop() {
<br>  ldrValue = analogRead(ldrPin);
<br>  if (ldrValue <= okLevel) {
<br>    digitalWrite(greenLedPin, HIGH);
<br>    digitalWrite(yellowLedPin, LOW);
<br>    digitalWrite(redLedPin, LOW);
  
<br>    noTone(buzzerPin);
<br>  }
<br>  else if (ldrValue <= alertLevel) {
<br>    digitalWrite(greenLedPin, LOW);
<br>    digitalWrite(yellowLedPin, HIGH);
<br>    digitalWrite(redLedPin, LOW);
  
<br>    noTone(buzzerPin);
<br>  }
<br>  else {
<br>    digitalWrite(greenLedPin, LOW);
<br>    digitalWrite(yellowLedPin, LOW);
<br>    digitalWrite(redLedPin, HIGH);
   
<br>    tone(buzzerPin, 1000);
<br>    delay(3000);
<br>    noTone(buzzerPin);
<br>    //delay(2000);
<br>  }
<br>}
