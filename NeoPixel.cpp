#include "NeoPixel.h"

NeoPixel::NeoPixel(uint8_t pixel, Adafruit_NeoPixel *pixels) {
  _pixel = pixel;
  _pixels = pixels;
}

void NeoPixel::updatePixel() {
  _pixels->setPixelColor(_pixel,
                         pgm_read_byte(&gamma8[_red]),
                         pgm_read_byte(&gamma8[_green]),
                         pgm_read_byte(&gamma8[_blue]));
}

void NeoPixel::setBrightness(uint8_t brightness) {
  if (brightness > 0) {
    _red = (_red * brightness) >> 8;
    _green = (_green * brightness) >> 8;
    _blue = (_blue * brightness) >> 8;
  }
}

void NeoPixel::setColor(uint8_t red, uint8_t green, uint8_t blue) {
  _red = red;
  _green = green;
  _blue = blue;
}

uint8_t NeoPixel::getPixelNumber() {
  return _pixel;
}

uint8_t NeoPixel::getPixelRow() {
  return _pixel / 8;
}

uint8_t NeoPixel::getPixelColumn() {
  return _pixel % 8;
}

