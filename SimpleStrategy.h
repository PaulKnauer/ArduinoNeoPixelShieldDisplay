#ifndef SimpleStrategy_h
#define SimpleStrategy_h

#include "NeoPixelStrategy.h"

class SimpleStrategy : public NeoPixelStrategy {
  public:
    SimpleStrategy();
    virtual void execute();
    virtual void setPixelList(LinkedList<NeoPixel*> *pixelList);
  private:
    uint8_t _hue, _amplitude;
    LinkedList<NeoPixel*> *_pixelList;
    double hueToRadians(uint8_t hue);
    double factor(double factor, double amplitude);
    double getCos(uint8_t value, uint8_t offset);
};

#endif
