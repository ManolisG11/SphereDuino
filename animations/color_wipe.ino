void colorWipe(CRGB color, int delayTime) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
    FastLED.show();
    delay(delayTime);
  }
}

void loop() {
  colorWipe(CRGB::Green, 50); // Example: green wipe with 50ms delay
}
