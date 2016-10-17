#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>
#include "NeoPixelShield.h"
#include "HueStrategy.h"
#include "ColorWheelStrategy.h"
#include "SimpleStrategy.h"
#include "RandomStrategy.h"

Adafruit_NeoPixel *pixels = new Adafruit_NeoPixel(40, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel *pixels = new Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);
NeoPixelShield *shield = new NeoPixelShield(pixels);
HueStrategy *strategy = new HueStrategy();
//SimpleStrategy *strategy = new SimpleStrategy();
//ColorWheelStrategy *strategy = new ColorWheelStrategy();
//RandomStrategy *strategy = new RandomStrategy();

void setup() {
  shield->setStrategy(strategy);
}

void loop() {
  shield->executeStrategy();
  shield->showPixels();
  delay(10);
}
