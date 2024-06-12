void fadeInOut(CRGB color, int fadeDelay) {
  for (int brightness = 0; brightness < 255; brightness++) {
    fill_solid(leds, NUM_LEDS, color.nscale8(brightness));
    FastLED.show();
    delay(fadeDelay);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    fill_solid(leds, NUM_LEDS, color.nscale8(brightness));
    FastLED.show();
    delay(fadeDelay);
  }
}

void loop() {
  fadeInOut(CRGB::Purple, 5); // Example: fade in and out with purple color
}
