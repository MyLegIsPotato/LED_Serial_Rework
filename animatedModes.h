extern CRGB leds[];
extern uint16_t TOTAL_LEDS;
extern uint8_t BRIGHTNESS;

class animatedModes{
  int currentHue = 0;
  uint16_t currentOffset; 
  bool reverseAnimation = false;

  private:
    void AnimateBiDir(){
      if(currentOffset == 0){
        reverseAnimation = false;
      }else if(currentOffset == 256){
        reverseAnimation = true;
      }
     
      if(reverseAnimation == true){
        currentOffset--;
      }else{
        currentOffset++;
      }

      //drukuj.ab("offset: ", currentOffset);
    }

  public:
    void PoliceStrobe(int delayMS){
      directControl.SetAllTo(CRGB::Red);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Black);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Blue);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Black);
      delay(delayMS); 
    }

    void PoliceStrobeDirect(int delayMS){
      directControl.SetAllTo(CRGB::Red);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Blue);
      delay(delayMS);
    }

    void Strobe(int delayMS){
      directControl.SetAllTo(CRGB::White);
      delay(10);
      directControl.SetAllTo(CRGB::Black);
      delay(delayMS);
    }

    void RGBSwitch(int delayMS){
      directControl.SetAllTo(CRGB::Red);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Green);
      delay(delayMS);
      directControl.SetAllTo(CRGB::Blue);
      delay(delayMS);
    }

    void HUERoll(int cycleDelay){
      EVERY_N_MILLIS(cycleDelay) currentHue = currentHue+1;
      CHSV newCol = CHSV(currentHue, 230, BRIGHTNESS);
      directControl.SetAllTo(newCol);
    }
    
    void MovingSegments(){
      directControl.SetSpanSpacedBy(8, 16, currentOffset, CRGB::Orange);
      delay(20);
      AnimateBiDir();
    }

    void FlashOnce(CRGB color, uint8_t bri){
      directControl.SetAllTo(CRGB::Black);
      for(int i=1; i<=5; i++){
        //directControl.SetAllTo(color * bri);
        directControl.SetAllTo((color/5)*i);
      }
    }
};

animatedModes animatedModes;
