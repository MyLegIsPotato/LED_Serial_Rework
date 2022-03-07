extern uint8_t animFrame;
extern uint8_t animNum;
extern uint8_t BRIGHTNESS;

class presets{
   public:

  void Preset1(){
    switch (animNum) {
      case 0:
        paletteControl.SetupXAndYStripedPalette(CRGB::Cyan, CRGB::Yellow);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 1:
        paletteControl.SetupXAndYStripedPalette(CRGB::Blue, CRGB::White);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 2:
        paletteControl.SetupXAndYStripedPalette(CRGB::Green, CRGB::Lime);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 3:
        paletteControl.SetupXAndYStripedPalette(CRGB::Pink, CRGB::Purple);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 4:
        paletteControl.SetupTotallyRandomPaletteFor(5);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
    }
    ChangeAnimEvery_N_Seconds(10);
  }

    void Preset2(){
    switch (animNum) {
      case 0:
        paletteControl.SetupXAndYStripedPalette(CRGB::Yellow, CRGB::Yellow);
        paletteControl.FillLEDsFromPaletteColors(--animFrame);
        break;
      case 1:
        paletteControl.SetupXAndYStripedPalette(CRGB::Red, CRGB::Red);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 2:
        paletteControl.SetupXAndYStripedPalette(CRGB::Gold, CRGB::Gold);
        paletteControl.FillLEDsFromPaletteColors(--animFrame);
        break;
      case 3:
        paletteControl.SetupXAndYStripedPalette(CRGB::Pink, CRGB::Pink);
        paletteControl.FillLEDsFromPaletteColors(++animFrame);
        break;
      case 4:
        paletteControl.SetupXAndYStripedPalette(CRGB::Orange, CRGB::Orange);
        paletteControl.FillLEDsFromPaletteColors(--animFrame);
        break;
    }
    ChangeAnimEvery_N_Seconds(30);
  }
  
  void Xmas1(){
    switch (animNum) {
      case 0:
        paletteControl.SetupXAndYStripedPalette(CRGB::Red, CRGB::Yellow);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
      case 1:
        paletteControl.SetupXAndYStripedPalette(CRGB::Blue, CRGB::Green);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
      case 2:
        paletteControl.SetupXAndYStripedPalette(CRGB::Green, CRGB::Yellow);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
      case 3:
        paletteControl.SetupXAndYStripedPalette(CRGB::Yellow, CRGB::Blue);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
      case 4:
        paletteControl.Setup4ColorPalette(CRGB::Red, CRGB::Yellow, CRGB::Green, CRGB::Blue);
        paletteControl.FillLEDsFromPaletteColors(0);
        break;
    }
    ChangeAnimEvery_N_Seconds(30);
  }

  void ChangeAnimEvery_N_Seconds(uint8_t secs) {
    EVERY_N_SECONDS(secs) ++animNum;
    if (animNum >= 5) {
      animNum = 0;
    }
  }
};

presets presets;
