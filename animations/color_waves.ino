void colorWaves(CRGBPalette16 palette) {
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;

  uint8_t brightDepth = beatsin88( 396, 96, 224 );
  uint16_t brightThetaInc = beatsin88( 203, 20, 60 );
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;
  uint16_t hueinc16 = beatsin88( 113, 300, 1500 );

  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis;
  sLastMillis = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5, 9 );
  uint16_t brightnessthetainc16 = brightThetaInc + (brightThetaInc * deltams / 65536);

  for ( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;
    uint16_t h16_128 = hue16 >> 7;
    uint8_t hue128 = h16_128 >> 8;
    uint8_t sat8 = qadd8( h16_128, beatsin88( 196, 80, 120));
    uint8_t bright8 = brightDepth;
    if (hue128 & 0x80) {
      bright8 = qsub8( bright8, (brightDepth / 3));
    }
    bright8 = qadd8( bright8, (brightDepth / 4));

    CRGB newcolor = ColorFromPalette( palette, hue8, bright8, LINEARBLEND);
    uint16_t pixelnumber = (NUM_LEDS-1) - i;
    nblend( leds[pixelnumber], newcolor, 64);
  }
  FastLED.show();
}

void loop() {
  colorWaves(RainbowColors_p); // Rainbow color waves
}
