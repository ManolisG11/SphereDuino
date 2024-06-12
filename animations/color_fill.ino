void singleColor(CRGB color) {
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
}

void loop() {
  singleColor(CRGB::Red); // Example: fill with red
  delay(1000);
  singleColor(CRGB::Blue); // Example: fill with blue
  delay(1000);
}
