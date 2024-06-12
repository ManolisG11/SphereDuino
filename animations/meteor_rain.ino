void meteorRain(CRGB color, int meteorSize, int meteorTrailDecay, boolean meteorRandomDecay) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);

  for (int i = 0; i < NUM_LEDS + NUM_LEDS; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      if ((!meteorRandomDecay) || (random(10) > 5)) {
        leds[j].fadeToBlackBy(meteorTrailDecay);
      }
    }

    for (int j = 0; j < meteorSize; j++) {
      if ((i - j < NUM_LEDS) && (i - j >= 0)) {
        leds[i - j] = color;
      }
    }

    FastLED.show();
    delay(30);
  }
}

void loop() {
  meteorRain(CRGB::Blue, 10, 64, true); // Blue meteor rain
}
