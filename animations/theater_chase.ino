void theaterChase(CRGB color, int wait) {
  for (int q = 0; q < 3; q++) {
    for (int i = 0; i < NUM_LEDS; i = i + 3) {
      leds[i + q] = color;
    }
    FastLED.show();
    delay(wait);
    for (int i = 0; i < NUM_LEDS; i = i + 3) {
      leds[i + q] = CRGB::Black;
    }
  }
}

void loop() {
  theaterChase(CRGB::White, 50); // White theater chase
}
