/*
  MAX7219_A_Display.ino

  Hardware:
  - Seeed XIAO RP2040
  - 4-in-1 MAX7219 FC-16 LED Matrix

  Wiring:
  D10 -> DIN
  D8  -> CLK
  D7  -> CS

  Library required:
  LedControl
*/

#include <LedControl.h>

// DIN, CLK, CS, number of MAX7219 modules
LedControl lc = LedControl(D10, D8, D7, 4);

// Custom letter A bitmap
byte letterA[8] =
{
  B01111110, // Row 1
  B01100110, // Row 2
  B01100110, // Row 3
  B11100111, // Row 4 (updated)
  B01100110, // Row 5
  B11111111, // Row 6
  B11000011, // Row 7
  B11000011  // Row 8
};

void setup()
{
  // Initialise all four MAX7219 drivers
  for (int module = 0; module < 4; module++)
  {
    lc.shutdown(module, false);  // Wake device
    lc.setIntensity(module, 4);  // Brightness (0-15)
    lc.clearDisplay(module);
  }

  // Draw letter A on Module 0
  for (int row = 0; row < 8; row++)
  {
    lc.setRow(0, row, letterA[row]);
  }
}

void loop()
{
  // Nothing to do
}