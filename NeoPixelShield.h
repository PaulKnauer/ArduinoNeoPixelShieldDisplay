#ifndef NeoPixelShield_h
#define NeoPixelShield_h

#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>
#include "NeoPixel.h"
#include "NeoPixelStrategy.h"

#define NUM_PIXELS 40
#define PIN 6

class NeoPixelShield {
  public:
    NeoPixelShield(Adafruit_NeoPixel *pixels);
    void setStrategy(NeoPixelStrategy *strategy);
    void executeStrategy();
    void showPixels();
  private:
    Adafruit_NeoPixel *_pixels;
    LinkedList<NeoPixel*> *_pixelList;
    NeoPixelStrategy *_strategy;
};

#endif
