void twinkleEffect(int twinkleCount, int twinkleDuration) {
  for (int i = 0; i < twinkleCount; i++) {
    int pos = random(NUM_LEDS);
    leds[pos] = CRGB::White;
    FastLED.show();
    delay(twinkleDuration);
    leds[pos] = CRGB::Black;
  }
}

void loop() {
  twinkleEffect(5, 100); // Twinkle 5 LEDs with 100ms duration
}
