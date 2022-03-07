extern CRGB leds[];
extern uint16_t TOTAL_LEDS;

class directControl{
   public:
    int a1Val;
    int cursorPos;

   void SetAllTo(CRGB color){
    for(uint16_t i=0; i < TOTAL_LEDS; i++){
      leds[i] = color;
    }

    return;
  }

  void SetRangeTo(int startLed, int endLed, CRGB color){
    for(uint16_t i=startLed; i < endLed; i++){
      leds[i] = color;
    }

    return;
  }

  void SetRangeSeconds(int startLed, int endLed, CRGB color){
    for(uint16_t i=startLed; i < endLed; i++){
      if(i%2 == 0){
        leds[i] = color;
      }else{
        //leds[i] = CRGB::Black;
      }
      
    }
    return;
  }
  
  void SetSingleTo(int index, CRGB color){
    leds[index] = color;
    return;
  }

  uint16_t segCount;
  uint16_t segLength;

  void SetSpanSpacedBy(uint16_t spanLength, uint16_t spanSpacing, uint16_t offset, CRGB color){
  segCount = (TOTAL_LEDS/(spanLength+spanSpacing));
  segLength = spanLength+spanSpacing;
      for(uint16_t i=0; i < segCount; i++){
        for(uint8_t j=0; j < segLength; j++){
          uint16_t x = (i*segLength)+j+offset;
          if(x <= TOTAL_LEDS && x >= 0){
            if(j<spanLength){
              leds[x] = color;
            }else{
              leds[x] = CRGB::Black;
            }
          }
        }
      }
    FastLED.show();
  }

  void ShowCursor(CRGB color){
    a1Val = analogRead(A1);
    cursorPos = map(a1Val, 0, 1024, 1, TOTAL_LEDS);
    Serial.print("Cursor position: ");
    Serial.println(cursorPos);
    
    SetRangeTo(cursorPos, cursorPos+5, color);
  }
};

directControl directControl;
