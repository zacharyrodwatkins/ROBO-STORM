#include <Arduino.h>
#include "Adafruit_SSD1306.h"
#include "FreeMono12pt7b.h"
#include "Wire.h"

#define OLED_RESET -1  // Not used
Adafruit_SSD1306 display(OLED_RESET);
#define Music PA3

#define BEAT 60000.0

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.println("ROD");
  display.display();
}

void quarter(int Freq, int BPM){
  tone(Music, Freq, BEAT/(2*BPM));
  delay(BEAT/(2*BPM));
}

void half(int Freq, int BPM){
  tone(Music, Freq, BEAT/BPM);
  delay(BEAT/BPM);
}

void whole(int Freq, int BPM){
  tone(Music, Freq, 2*BEAT/BPM);
  delay(2*BEAT/BPM);
}

void wholerest(int BPM){
  delay(4*BEAT/BPM);
}

void bar(int Freq, int BPM){
  double quater = 60.0/BPM*0.3*1000;
  double pause = 60.0/BPM*0.7*1000;
  tone(Music, Freq , quater);
  delay(pause);
  tone(Music , Freq, 2*quater+pause);
  delay(pause);
  tone(Music, Freq, quater);
  delay(pause);
}

#define BLOW 247
#define C 262
#define D 294
#define E 330
#define G 392
#define GSHARP 415
#define A 440
#define BHIGH 494

void loop() {
  //display.display("");
  int tempo = 150  ;
  quarter(BHIGH, tempo);
  quarter(A, tempo);
  half(G, tempo);
  quarter(G, tempo);
  quarter(A, tempo);
  quarter(G, tempo);
  quarter(D, tempo);
  quarter(BLOW, tempo);
  quarter(C, tempo);
  quarter(D, tempo);
  quarter(E, tempo);
  quarter(D, tempo);
  quarter(BLOW, tempo);
  half(D, tempo);
  quarter(G, tempo);
  quarter(A, tempo);
  half(BHIGH, tempo);
  half(BHIGH, tempo);
  half(BHIGH, tempo);
  quarter(G, tempo);
  quarter(A, tempo);
  quarter(BHIGH, tempo);
  quarter(A, tempo);
  quarter(A, tempo);
  quarter(GSHARP, tempo);
  half(A, tempo);
  quarter(BHIGH, tempo);
  quarter(A, tempo);
  half(G, tempo);
  quarter(G, tempo);
  quarter(A, tempo);
  quarter(G, tempo);
  quarter(D, tempo);
  quarter(BLOW, tempo);
  quarter(C, tempo);
  quarter(D, tempo);
  quarter(E, tempo);
  quarter(D, tempo);
  quarter(BLOW, tempo);
  half(D, tempo);
  quarter(G, tempo);
  quarter(A, tempo);
  whole(BHIGH, tempo);
  whole(A, tempo);
  whole(G, tempo);
  wholerest(tempo);

}



