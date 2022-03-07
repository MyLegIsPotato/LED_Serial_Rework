class analyzerFunc{
  public:
  //visualiser config:
  uint8_t maxBPM = 120;
  elapsedMillis sinceBass = 0;
  int newSample = 0;


  int bassFor = 0;
  bool wasBass = false;
  uint8_t bassTimer = 0;
  bool playAnimation = false;
  int pauseFor = 0;
  bool isPause = 0;
  uint16_t minBeatInterval = 0;
  
  void PrintArray(int arr[], int slots){
    for(int i = 0; i < slots; i++){
      Serial.print(arr[i]);
      Serial.print(',');
      if(i == slots-1){
        Serial.println("");
      }
    }
  }
  
  void AddAndOffset(int (&arr)[64], int newInt){
    for(int i = 63; i > 0; i--){
      arr[i]=arr[i-1];
    }
    arr[0] = newInt;
  }

// 
//  int16_t avgBass(int sampleCount){
//      int result = 0;
//      for(int i=0; i<sampleCount; i++){
//        result += bassFrames[i];
//      }
//      result = result/sampleCount;
//      return result;
//  }

};

analyzerFunc analyzerFunc;
