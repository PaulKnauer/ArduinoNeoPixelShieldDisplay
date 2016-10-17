#import "HueStrategy.h"

HueStrategy::HueStrategy() {
  _hue = 0;
}

void HueStrategy::setPixelList(LinkedList<NeoPixel*> *pixelList) {
  _pixelList = pixelList;
}

void HueStrategy::execute() {
  NeoPixel *pixel;
  int hue;
  uint8_t i, a;
  for (hue = _hue, i = 0; i < _pixelList->size(); i++, hue += 4) {
    a = hue;
    pixel = _pixelList->get(i);
    switch ((hue >> 8) % 6) {
      case 0: //Reddish
        pixel->setColor(255, a, 0);
        break;
      case 1: //Orangeish
        pixel->setColor(~a, 255, 0);
        break;
      case 2: //Geenish
        pixel->setColor(0, 255, a);
        break;
      case 3: //Turquoisish
        pixel->setColor(0, ~a, 255);
        break;
      case 4: //Blueish
        pixel->setColor(a, 0, 255);
        break;
      case 5: //Purpleish
        pixel->setColor(255, 0, ~a);
        break;
    }
    pixel->setBrightness(255);
    pixel->updatePixel();
  }
  _hue += 8;
  if (_hue >= 1536) _hue = 0;
}
