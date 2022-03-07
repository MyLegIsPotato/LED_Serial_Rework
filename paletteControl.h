#include <FastLED.h>

extern uint16_t TOTAL_LEDS;
extern CRGB leds[];

class paletteControl {

  private:
    CRGBPalette16 currentPalette;
    TBlendType    currentBlending = LINEARBLEND;

  public:
    CRGBPalette16 fillPalette16(CRGB colorSlots[], CRGBPalette16 currentPalette, CRGB backgroundColor) {
      for (int i = 0; i < sizeof(colorSlots); i++) {
        currentPalette[i] = colorSlots[i];
      };
      for (int j = 0; j < (16 - sizeof(colorSlots)); j++) {
        int x = sizeof(colorSlots) + j;
        currentPalette[x] = backgroundColor;
      };
      return currentPalette;
    };

    CRGBPalette256 fillPalette256(CRGB colorSlots[], CRGBPalette256 currentPalette, CRGB backgroundColor) {
      for (int i = 0; i < sizeof(colorSlots); i++) {
        currentPalette[i] = colorSlots[i];
      };
      for (int j = 0; j < (256 - sizeof(colorSlots)); j++) {
        int x = sizeof(colorSlots) + j;
        currentPalette[x] = backgroundColor;
      };
      return currentPalette;
    };

    void FillLEDsFromPaletteColors(uint16_t colorIndex)
    {
      uint8_t brightness = 255;

      for ( uint16_t i = 0; i < TOTAL_LEDS; i++) {
        leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
      }
    }

    void SetupXAndYStripedPalette(CRGB col1, CRGB col2)
    {
      // 'black out' all 16 palette entries...
      fill_solid( currentPalette, 16, CRGB::Black);
      currentPalette[0] = col1;
      currentPalette[4] = col2;
      currentPalette[8] = col1;
      currentPalette[12] = col2;
    }

    void Setup4ColorPalette(CRGB col1, CRGB col2, CRGB col3, CRGB col4)
    {
      // 'black out' all 16 palette entries...
      fill_solid( currentPalette, 16, CRGB::Black);
      currentPalette[0] = col1;
      currentPalette[4] = col2;
      currentPalette[8] = col3;
      currentPalette[12] = col4;
    }

    bool rev = false;
    uint8_t brt = 5;
    void SetupTotallyRandomPaletteFor(uint8_t seconds) //TO DO timer
    {
      brt = FastLED.getBrightness();
      if (brt >= 250) {
        rev = true;
      } else if (brt <= 5) {
        rev = false;
        for ( int i = 0; i < 16; ++i) {
          currentPalette[i] = CHSV( random8(), 180, random8());
        }
      }
      if (rev == false) {
        FastLED.setBrightness(FastLED.getBrightness() + 3);
      } else {
        FastLED.setBrightness(FastLED.getBrightness() - 3);
      }
    }

};

paletteControl paletteControl;
