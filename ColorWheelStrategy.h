#ifndef ColorWheelStrategy_h
#define ColorWheelStrategy_h

#include <LinkedList.h>
#include "NeoPixel.h"
#include "NeoPixelStrategy.h"

class ColorWheelStrategy : public NeoPixelStrategy {
  public:
    ColorWheelStrategy();
    virtual void execute();
    virtual void setPixelList(LinkedList<NeoPixel*> *pixelList);
  private:
    LinkedList<NeoPixel*> *_pixelList;
    uint8_t _hue;
};

#endif
