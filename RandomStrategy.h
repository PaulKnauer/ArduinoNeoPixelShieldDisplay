#ifndef RandomStrategy_h
#define RandomStrategy_h

#include <LinkedList.h>
#include "NeoPixel.h"
#include "NeoPixelStrategy.h"

class RandomStrategy : public NeoPixelStrategy {
  public:
    RandomStrategy();
    virtual void execute();
    virtual void setPixelList(LinkedList<NeoPixel*> *pixelList);
  private:
    int16_t _hue;
    LinkedList<NeoPixel*> *_pixelList;
};

#endif
