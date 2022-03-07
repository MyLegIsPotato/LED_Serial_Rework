//#define FASTLED_ALLOW_INTERRUPTS 1
#define USE_OCTOWS2811
#include "def.h"
#include <OctoWS2811.h>
#include <FastLED.h>
#include <stdlib.h>
#include <AudioAnalyzer.h>
#include <EEPROM.h>
#include "drukuj.h"
#include "genPals.h"
#include "directControl.h"
#include "animatedModes.h"
#include "microphoneBeatDetector.h"
#include "presets.h"
#include "zones.h"
#include "masking.h"
#include "serialCom.h"
#include "analyzerFunc.h"

#define NUM_LEDS_PER_STRIP 458
//#define NUM_LEDS_PER_STRIP 60
#define NUM_STRIPS 4

uint16_t TOTAL_LEDS = NUM_STRIPS * NUM_LEDS_PER_STRIP;
uint8_t BRIGHTNESS =185;

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];
CRGBPalette16 currentPalette;

Analyzer Audio = Analyzer(3, 4, 5); //Strobe pin ->3  RST pin ->4 Analog Pin ->5
int FreqVal[7];
int bassFrames[64];

uint8_t animNum = 4;
uint8_t animFrame = 0;
uint8_t maskNum = 1;



void setup() {
  delay(500);
  //Start

  Serial.println("Starting...");
  FastLED.addLeds<OCTOWS2811>(leds, NUM_LEDS_PER_STRIP);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxRefreshRate(500);
  
  directControl.SetAllTo(CRGB::Black);
  Serial.println("Start complete. Moving to animations...");

  Audio.Init(); //Init module
  FastLED.delay(10);
}

void loop() {

  Audio.ReadFreq(FreqVal);
  analyzerFunc.AddAndOffset(bassFrames, max(FreqVal[0]-100, 0));
  analyzerFunc.PrintArray(bassFrames, 16);
  
  animatedModes.HUERoll(10);

  if(Average(bassFrames, 4) > 250){
    FastLED.setBrightness(map(Average(bassFrames, 4), 50, 900, 0, BRIGHTNESS));
  }else{
    FastLED.setBrightness(0);
  }
 
  FastLED.show();
  
  delay(1);
}

double Average(int arr[], int count){
  double result = 0;
  double selected = 0;
  for (int i = 0; i < count; i++){
    selected += arr[i];
  }
  result = selected/count;
  return result;
}
