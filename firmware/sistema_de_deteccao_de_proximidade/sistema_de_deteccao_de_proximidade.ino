#define TRIG 9
#define ECHO 10
#define BUZZER 8

long duracao;
float distancia;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracao = pulseIn(ECHO, HIGH);

  distancia = duracao * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia > 100) {
    noTone(BUZZER);
  }
  else if (distancia > 60) {
    tone(BUZZER, 1000);
    delay(500);
    noTone(BUZZER);
    delay(500);
  }
  else if (distancia > 30) {
    tone(BUZZER, 1000);
    delay(150);
    noTone(BUZZER);
    delay(150);
  }
  else {
    tone(BUZZER, 1000);
  }

  delay(50);
}