#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "FreeMono12pt7b.h"
#include "Wire.h"

#define DIR1 PA_0
#define DIR2 PA_3
#define ReadPIN PA1
#define PWM_TIME 5000

#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);

int speed;
int readVoltage;

void print(int);

int updateSpeed(int ReadVoltage){
  speed = ReadVoltage - 1024/2;
  if(speed>0){
    pwm_start(DIR2, (int) 1e5, PWM_TIME, 0, 0); //Turn off dir2 if speed>0 
    pwm_start(DIR1, (int) 1e5, PWM_TIME, speed*2, 0); //Set dir1 to speed
  }
  else {
    pwm_start(DIR1, (int) 1e5, PWM_TIME, 0, 0); //Turn off dir 1 if speed<0
    pwm_start(DIR2, (int) 1e5, PWM_TIME,-2*speed, 0);
  }
  return speed;
}

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pwm_start(DIR1, (int) 1e6, PWM_TIME, 0, 1 );
  pwm_start(DIR2, (int) 1e6, PWM_TIME, 0, 1);
  display.clearDisplay();
  display.display();
}

void loop() {
 readVoltage = analogRead(ReadPIN);
 speed = updateSpeed(readVoltage);
 print(speed);
}


void print(int speed){
   display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.setTextSize(1.5);
  display.print( "speed: ");
  display.print(speed);
  display.display();
}
