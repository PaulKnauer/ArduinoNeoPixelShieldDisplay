#include "NeoPixelShield.h"

NeoPixelShield::NeoPixelShield(Adafruit_NeoPixel *pixels) {
  _pixels = pixels;
  _pixelList = new LinkedList<NeoPixel*>();
  for (int i = 0; i < NUM_PIXELS; i++) {
    _pixelList->add(new NeoPixel(i, _pixels));
  }
  _pixels->begin();
}

void NeoPixelShield::setStrategy(NeoPixelStrategy *strategy) {
  _strategy = strategy;
  _strategy->setPixelList(_pixelList);
}

void NeoPixelShield::executeStrategy() {
  if (_strategy) {
    _strategy->execute();
  }
}

void NeoPixelShield::showPixels() {
  _pixels->show();
}
