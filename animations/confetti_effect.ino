void confetti() {
  fadeToBlackBy(leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV(random8(), 200, 255);
  FastLED.show();
  delay(20);
}

void loop() {
  confetti(); // Confetti effect
}
