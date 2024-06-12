#define GRAVITY -9.81
#define h0 1
#define NUM_BALLS 3

float h[NUM_BALLS] = {h0, h0, h0}; // Heights
float vImpact0 = sqrt(-2 * GRAVITY * h0);
float vImpact[NUM_BALLS] = {vImpact0, vImpact0, vImpact0};
float tCycle[NUM_BALLS] = {0, 0, 0};
int pos[NUM_BALLS] = {0, 0, 0};
long tLast[NUM_BALLS] = {0, 0, 0};
float COR[NUM_BALLS] = {0.90, 0.85, 0.80}; // Coefficient of Restitution

void loop() {
  for (int i = 0; i < NUM_BALLS; i++) {
    float tElapsed = millis() - tLast[i];
    tLast[i] = millis();
    tCycle[i] += tElapsed;

    h[i] = 0.5 * GRAVITY * pow(tCycle[i] / 1000, 2.0) + vImpact[i] * tCycle[i] / 1000;

    if (h[i] < 0) {
      h[i] = 0;
      vImpact[i] = COR[i] * vImpact[i];
      tCycle[i] = 0;

      if (vImpact[i] < 0.01) vImpact[i] = vImpact0;
    }
    pos[i] = round(h[i] * (NUM_LEDS - 1) / h0);
  }

  for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;

  for (int i = 0; i < NUM_BALLS; i++) leds[pos[i]] = CRGB::Red;
  
  FastLED.show();
  delay(20);
}
