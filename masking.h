class masking{
  public:
  void Mask(int zoneNum){
    zones.SetZoneFull(zoneNum, CRGB::Black);
  }
};

masking masking;
