#include "SimpleStrategy.h"

SimpleStrategy::SimpleStrategy() {
  _hue = 0;
  _amplitude = 127;
}

void SimpleStrategy::setPixelList(LinkedList<NeoPixel*> *pixelList) {
  _pixelList = pixelList;
}

void SimpleStrategy::execute() {
  NeoPixel *pixel;
  for (int i = 0; i < _pixelList->size(); i++) {
    pixel = _pixelList->get(i);
    pixel->setColor(getCos(_hue, 0), getCos(_hue, 85), getCos(_hue, 170));
    pixel->setBrightness(255);
    pixel->updatePixel();
  }
  _hue += 1;
  if (_hue > 255) {
    _hue = 0;
  }
}

double SimpleStrategy::hueToRadians(uint8_t hue) {
  return ((2 * M_PI) / 256) * hue;
}

double SimpleStrategy::factor(double factor, double amplitude) {
  return (0.5 + factor) * amplitude;
}

double SimpleStrategy::getCos(uint8_t value, uint8_t offset) {
  return constrain(factor(cos(hueToRadians(value + offset)), 256.0), 0, 255);
}
