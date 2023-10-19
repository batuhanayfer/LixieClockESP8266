#include "classes.h"

#define colorSaturation 255 // 0-255 (0 = off, 255 = full brightness)

NeoPixelBus<NeoGrbFeature, NeoWs2812xMethod> strip(PixelCount);

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslWhite(white);
HslColor hslBlack(black);

// put variable declarations here:
Digit digit1(0);
Digit digit2(1);
Digit digit3(2);
Digit digit4(3);

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ; // wait for serial attach

  Serial.println();
  Serial.println("Initializing...");
  Serial.flush();

  // this resets all the neopixels to an off state
  strip.Begin();
  strip.Show();

  Serial.println();
  Serial.println("Running...");
}

void loop()
{
  Serial.println("Setting Digits");

  RgbColor colors[] = {red, green, blue};
  int numColors = sizeof(colors) / sizeof(colors[0]);
  int colorIndex = 0;

  for (int i = 0; i < 10; i++)
  {
    digit4.setColor(colors[colorIndex]);
    colorIndex = (colorIndex + 1) % numColors;
    digit4.setNumber(i);
    strip.Show();
    delay(200);
    digit4.setColor(black);
    digit4.setNumber(i);
    strip.Show();
    delay(200);
  }
  delay(2000);
}
