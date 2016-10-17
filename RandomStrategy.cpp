#import "RandomStrategy.h"

RandomStrategy::RandomStrategy() {
  _hue = 0;
}

void RandomStrategy::setPixelList(LinkedList<NeoPixel*> *pixelList) {
  _pixelList = pixelList;
}

void RandomStrategy::execute() {
  NeoPixel *pixel;
  uint8_t i, r, g, b;
  for (i = 0; i < _pixelList->size(); i++) {
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
    
    pixel = _pixelList->get(i);
    pixel->setColor(r, g, b);
    
    pixel->setBrightness(random(0, 255));
    pixel->updatePixel();
  }
}
