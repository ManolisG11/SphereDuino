void chasingPattern(CRGB color, int delayTime) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    if (i > 0) leds[i - 1] = CRGB::Black;
    FastLED.show();
    delay(delayTime);
  }
  leds[NUM_LEDS - 1] = CRGB::Black; // Turn off the last LED
}

void loop() {
  chasingPattern(CRGB::Yellow, 100);
}
