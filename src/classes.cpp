#include "classes.h"

Digit::Digit(int digit)
{
    _digit = digit;
}

void Digit::setNumber(int number)
{
    _number = number;

    switch (_number)
    {
    case (0):
        strip.SetPixelColor(6 + (_digit * 20), _color);
        strip.SetPixelColor(16 + (_digit * 20), _color);
        break;
    case (1):
        strip.SetPixelColor(5 + (_digit * 20), _color);
        strip.SetPixelColor(15 + (_digit * 20), _color);
        break;
    case (2):
        strip.SetPixelColor(7 + (_digit * 20), _color);
        strip.SetPixelColor(17 + (_digit * 20), _color);
        break;
    case (3):
        strip.SetPixelColor(9 + (_digit * 20), _color);
        strip.SetPixelColor(19 + (_digit * 20), _color);
        break;
    case (4):
        strip.SetPixelColor(1 + (_digit * 20), _color);
        strip.SetPixelColor(11 + (_digit * 20), _color);
        break;
    case (5):
        strip.SetPixelColor(3 + (_digit * 20), _color);
        strip.SetPixelColor(13 + (_digit * 20), _color);
        break;
    case (6):
        strip.SetPixelColor(4 + (_digit * 20), _color);
        strip.SetPixelColor(14 + (_digit * 20), _color);
        break;
    case (7):
        strip.SetPixelColor(2 + (_digit * 20), _color);
        strip.SetPixelColor(12 + (_digit * 20), _color);
        break;
    case (8):
        strip.SetPixelColor(0 + (_digit * 20), _color);
        strip.SetPixelColor(10 + (_digit * 20), _color);
        break;
    case (9):
        strip.SetPixelColor(8 + (_digit * 20), _color);
        strip.SetPixelColor(18 + (_digit * 20), _color);
        break;

    default:
        // Do Nothing
        break;
    }
}

void Digit::setColor(RgbColor color)
{
    _color = color;
}

int Digit::getNumber()
{
    return _number;
}

RgbColor Digit::getColor()
{
    return _color;
}