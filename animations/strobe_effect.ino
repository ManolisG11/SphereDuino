void strobe(CRGB color, int strobeCount, int flashDelay, int endPause) {
  for (int i = 0; i < strobeCount; i++) {
    fill_solid(leds, NUM_LEDS, color);
    FastLED.show();
    delay(flashDelay);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(flashDelay);
  }
  delay(endPause);
}

void loop() {
  strobe(CRGB::White, 10, 50, 1000); // White strobe effect
}
