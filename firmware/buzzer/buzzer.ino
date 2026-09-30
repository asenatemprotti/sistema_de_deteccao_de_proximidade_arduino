#define BUZZER 8

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  tone(BUZZER, 1000);
  delay(500);

  noTone(BUZZER);
  delay(500);
}