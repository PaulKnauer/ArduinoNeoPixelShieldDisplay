#include "ColorWheelStrategy.h"

ColorWheelStrategy::ColorWheelStrategy() {}

void ColorWheelStrategy::setPixelList(LinkedList<NeoPixel*> *pixelList) {
  _pixelList = pixelList;
  _hue = 0;
}

void ColorWheelStrategy::execute() {
  NeoPixel *pixel;
  for (int i = 0; i < _pixelList->size(); i++) {
    pixel = _pixelList->get(i);
    switch (_hue) {
      case 0:
        pixel->setColor(255, 0, 0); // red
        break;
      case 1:
        pixel->setColor(255, 255, 0); // yellow
        break;
      case 2:
        pixel->setColor(0, 255, 0); // green
        break;
      case 3:
        pixel->setColor(0, 255, 255); // cyan
        break;
      case 4:
        pixel->setColor(0, 0, 255); // blue
        break;
      case 5:
        pixel->setColor(255, 0, 255); // magenta
        break;
    }
    pixel->setBrightness(255);
    pixel->updatePixel();
  }
  _hue++;
  if (_hue > 5) {
    _hue = 0;
  }
}
