#include <FastLED.h>
#include "paletteControl.h"

class genPals {

  private:
    CRGBPalette256 finalPalette;
  
  public:
    CRGBPalette256 GeneratedPalette1() {
      CRGB slots[2];
    
      slots[0].r = 0;
      slots[0].g = 128;
      slots[0].b = 0;
      slots[1].r = 128;
      slots[1].g = 0;
      slots[1].b = 0;
      CRGB background;
      background.r = 0;
      background.g = 0;
      background.b = 90;
      finalPalette = paletteControl.fillPalette256(slots, finalPalette, background);
      return finalPalette;
    };

    void GeneratedPalette2() {
      CRGB slots[2];
    
      slots[0].r = 0;
      slots[0].g = 128;
      slots[0].b = 0;
      slots[1].r = 128;
      slots[1].g = 0;
      slots[1].b = 0;
      CRGB background;
      background.r = 0;
      background.g = 0;
      background.b = 0;
      finalPalette = paletteControl.fillPalette256(slots, finalPalette, background);
    }

    void GeneratedPalette3() {
      CRGB slots[15];
    
      slots[0].r = 255;
      slots[0].g = 255;
      slots[0].b = 0;
      slots[1].r = 255;
      slots[1].g = 255;
      slots[1].b = 0;
      slots[2].r = 255;
      slots[2].g = 128;
      slots[2].b = 0;
      slots[3].r = 255;
      slots[3].g = 128;
      slots[3].b = 64;
      slots[4].r = 255;
      slots[4].g = 255;
      slots[4].b = 0;
      slots[5].r = 255;
      slots[5].g = 255;
      slots[5].b = 0;
      slots[6].r = 255;
      slots[6].g = 128;
      slots[6].b = 64;
      slots[7].r = 255;
      slots[7].g = 128;
      slots[7].b = 64;
      slots[8].r = 255;
      slots[8].g = 128;
      slots[8].b = 0;
      slots[9].r = 255;
      slots[9].g = 255;
      slots[9].b = 0;
      slots[10].r = 255;
      slots[10].g = 255;
      slots[10].b = 0;
      slots[11].r = 255;
      slots[11].g = 255;
      slots[11].b = 0;
      slots[12].r = 255;
      slots[12].g = 128;
      slots[12].b = 64;
      slots[13].r = 255;
      slots[13].g = 128;
      slots[13].b = 0;
      slots[14].r = 255;
      slots[14].g = 255;
      slots[14].b = 0;
      slots[15].r = 255;
      slots[15].g = 255;
      slots[15].b = 0;
      CRGB background;
      background.r = 255;
      background.g = 255;
      background.b = 0;
      CRGBPalette16 currentPalette = CRGBPalette16(slots[0], slots[1], slots[2], slots[3], slots[4], slots[5], slots[6], slots[7], slots[8], slots[9], slots[10], slots[11], slots[12], slots[13], slots[14], slots[15] );
      finalPalette = currentPalette;
    }
};

genPals gens;
