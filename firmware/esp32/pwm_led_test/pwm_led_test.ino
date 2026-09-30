const int LED_PIN = 2;

void setup() {
  // PWM is configured automatically when we use analogWrite()
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 25% brightness
  analogWrite(LED_PIN, 64);
  delay(1000);

  // 50% brightness
  analogWrite(LED_PIN, 128);
  delay(1000);

  // 75% brightness
  analogWrite(LED_PIN, 191);
  delay(1000);

  // 100% brightness
  analogWrite(LED_PIN, 255);
  delay(1000);

  // Back down
  analogWrite(LED_PIN, 191);
  delay(1000);

  analogWrite(LED_PIN, 128);
  delay(1000);

  analogWrite(LED_PIN, 64);
  delay(1000);

  // OFF
  analogWrite(LED_PIN, 0);
  delay(1000);
}