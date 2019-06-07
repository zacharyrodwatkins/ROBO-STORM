#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "FreeMono12pt7b.h"
#include "Wire.h"

#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
}



