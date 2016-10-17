#ifndef HueStrategy_h
#define HueStrategy_h

#include <LinkedList.h>
#include "NeoPixel.h"
#include "NeoPixelStrategy.h"

class HueStrategy : public NeoPixelStrategy {
  public:
    HueStrategy();
    virtual void execute();
    virtual void setPixelList(LinkedList<NeoPixel*> *pixelList);
  private:
    int16_t _hue;
    LinkedList<NeoPixel*> *_pixelList;
};

#endif
