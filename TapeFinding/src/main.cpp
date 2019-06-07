#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "FreeMono12pt7b.h"
#include "Wire.h"

#define INpin PA0
#define THRESHPIN PA1
int THRESHVOLTAGE = 0;
int irVoltage = 0;
int i = 0;

#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);

void print(int, int);

void setup() {
  //pinMode(INpin, INPUT);
  //pinMode(THRESHPIN, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  THRESHVOLTAGE = analogRead(THRESHPIN);
  irVoltage = analogRead(INpin);
  print(THRESHVOLTAGE, irVoltage);
  i++;
}

void print(int thresh, int volt) {

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextSize(1.5);
  if (volt>thresh) display.println("Si senior");
  else display.println("No dice cowboy");
  display.setTextSize(0.75);
  //display.setFont(&FreeMono12pt7b);
  display.setCursor(4,30);
  display.print("threshold: ");
  display.println(thresh);
  display.setCursor(4,40);
  display.print("voltage:   ");
  display.println(volt);
  display.display();
  
}

