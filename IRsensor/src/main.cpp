#include <Arduino.h>
#include <stdlib.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SPITFT.h"
#include "gfxfont.h"
#include "Adafruit_SSD1306.h"

#define SAMPLE_SIZE 500
#define AINP PA15
#define THRESHPIN PA4

double signal[SAMPLE_SIZE];
double ONEK[SAMPLE_SIZE];
double TENK[SAMPLE_SIZE];
double sample[SAMPLE_SIZE];
double conv[2]; //To hold 1K and 10K convolution values in 0, 1

//build an interupt for changing thresh
double volatile THRESH = 42069;

/*
* Update the threshold for detection by reading the THRESHOLDPIN voltage
* Setup as an interupt
*/
void updateThresh(void){
  THRESH = analogRead(THRESHPIN);
}

void getSample(void);

void convolve(double[]);

void setup() {

//Configer Pins and such
pinMode(AINP, INPUT);
pinMode(THRESHPIN, INPUT);
attachInterrupt(THRESHPIN, updateThresh, CHANGE);

}

void loop() {
  getSample();
  convolve(sample);
  if (conv[0]>THRESH){ 
    if(conv[1]>THRESH) {/*both detected*/ }

    else {/* Only 1K detected*/}
    }
  else if (conv[1]>THRESH){
    //just 10k detected
  }
}

/*
* Do the convolution with the 1K and 10K signals
* Params: sig[], signal array
* Modifes conv array, placing the convolutions of the signal into the 0th and 1st indicies respectively
*/
void convolve(double sig[]) {}
