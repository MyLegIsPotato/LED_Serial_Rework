//Serial control buffers:
uint8_t input;
char inputChar;
bool readyForSignal = true;
String readBuffer;

class serialCom{
  public:
  void ReadUSB(){
   if (Serial.available() > 0) {
    input = Serial.read();
    inputChar = input;

    animatedModes.FlashOnce(CRGB::Blue, BRIGHTNESS);
    ClearBuffer();
    
    Serial.write(input);
   }
  }

//  void ReadUART(){
//   if(readyForSignal == true){
//      readyForSignal = false;
//       for (int i=0; i<Serial1.available(); i++) {
//        input = Serial1.read();
//        inputChar = input;
//    
//        //animatedModes.FlashOnce(CRGB::Red, BRIGHTNESS);
//        Serial.write(input);
//        if(inputChar == '<'){
//          Serial.println(' ');
//          readyForSignal = true;
//      }
//     }
//   }else{
//    if(Serial.available() > 0){
//      input = Serial1.read();
//    }
//   }
//  }

  void ReadUART(){
    if(Serial1.available() > 0){
      for(int i=0; i<32; i++){
        
        if(Serial1.read() == '>'){
           Serial.println("start");
           while(Serial1.read() != '<'){
             Serial.write(Serial1.read());
           }
          Serial.println("end");
        
        }
      }
    }
    Serial1.flush();
    Serial.println(Serial1.available());
    Serial1.flush();
  }

  void ClearBuffer() {
    for (int i; i < 64; i++) {
      int trash = Serial.read();
    }
  }
};

serialCom serialCom;
