#include <stdlib.h>
#include <AudioAnalyzer.h>
#include <EEPROM.h>

///Protocol:
// > BASS > MID > TREBLE <
// ex. ">200>30>124<"


bool useVisualizer = true;

uint_ frame[3];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  Serial.write('a');

  
//  //All visualizer code goes here:
//  if(useVisualizer){
//    int newSample = 0;
//
//    currentAnimation = 7;
//    //selectedColor = Lerp(0, 20, 30, 900, sensorValue);
//    //sensor1Lerped = Lerp(0,2,30,900,sensor1Value);
//    menuPos = selectedColor;
//    //Serial.println(sensor1Lerped);
//
//    Audio.ReadFreq(FreqVal);
//
//    newSample = max((FreqVal[0]), 0);
//    AddAndOffset(bassFrames, newSample);
//    DetectPause(bassFrames, 4);
//    DetectBass(bassFrames, 1);
//    PrintArray(bassFrames);
//
//    newSample = max((FreqVal[3]-830), 0);
//    AddAndOffset(midFrames, newSample);
//    DetectMid(midFrames, 7);
//
//    newSample = max((FreqVal[5]-500), 0);
//    AddAndOffset(trebleFrames, newSample);
//    DetectTreble(trebleFrames, 2);
//  }

}
