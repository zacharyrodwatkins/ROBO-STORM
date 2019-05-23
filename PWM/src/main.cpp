#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "FreeMono12pt7b.h"
#include "Wire.h"

#define PWMpin PA_0
#define ReadPIN PA1
#define PWM_TIME 500
#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);

int ReadValue = 0; 
int PrevRead = 0;

void print(int);

void setup() {
  pwm_start(PWMpin, (int) 1e6, PWM_TIME, 0, 1 );
  PrevRead = analogRead(ReadPIN);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  ReadValue = analogRead(ReadPIN);
  if (ReadValue != PrevRead)
    pwm_start(PWMpin, (int) 1e6, PWM_TIME, PWM_TIME * (1.0*ReadValue/1023) , 0);
  print(ReadValue);
}

void print(int value) {

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextSize(1.5);
  display.print( "ON Value: ");
  display.print(ReadValue);
  display.display();
}

