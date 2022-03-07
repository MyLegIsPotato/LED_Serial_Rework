extern uint8_t animNum;

class microphoneBeatDetector{
  private:
  uint16_t msBetweenDetections = 10;
  uint32_t lastMillis = 0;
  bool check = true;
  
  public:
    void CheckForBeat(){
//      if(millis() > (lastMillis+msBetweenDetections)){
//        lastMillis = millis();
//        check = true;
//      }else{
//        check = false;
//      }
//
//      if(check){
//        if(digitalRead(23) == 0){
//          animNum++;
//          if(animNum == 7){
//            animNum = 0;
//          }
//        }
//      }
      if(digitalRead(23)==0){
        animatedModes.HUERoll(0);
      }else{
        directControl.SetAllTo(CRGB::Black);
      }
      

    }
};

microphoneBeatDetector mic;
