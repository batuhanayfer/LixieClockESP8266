#ifndef CLASSES_H
#define CLASSES_H

#include <Arduino.h>
#include <NeoPixelBus.h>

const uint16_t PixelCount = 80; // this example assumes 4 pixels, making it smaller will cause a failure
extern NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip;

class Digit
{
private:
    //? ESP8266 uses GPIO3 due to DMA hardware use !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int _digit;
    RgbColor _color = RgbColor(0, 0, 0);
    int _number = 0;

public:
    Digit(int digit);
    void setNumber(int number);
    void setColor(RgbColor color);
    int getNumber();
    RgbColor getColor();
};

#endif