#ifndef NeoPixelStrategy_h
#define NeoPixelStrategy_h

#include <LinkedList.h>
#include "NeoPixel.h"

class NeoPixelStrategy {
  public:
    virtual void execute() = 0;
    virtual void setPixelList(LinkedList<NeoPixel*> *pixelList) = 0;
};

#endif
