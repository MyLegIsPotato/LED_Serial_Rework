class drukuj{
  public:
  void ab(String text, uint16_t integer){
    Serial.print(text+" ");
    Serial.println(integer);
  }
};

drukuj druk;
