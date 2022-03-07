#include "def.h"
typedef enum zoneName{BEHIND_SCREEN, DOOR_CORNER, GUNS} zoneName;

class zones{
  public:
    int zoneStart;
    int zoneEnd;

  
    void SetZoneFull(int zoneNum, CRGB color){

      if(zoneNum > 0 && zoneNum <= 4){
        zoneNum = (zoneNum%4)+1;
        
        zoneStart = NUM_LEDS_PER_STRIP*(zoneNum-1);
        zoneEnd = NUM_LEDS_PER_STRIP*zoneNum;

        directControl.SetRangeTo(zoneStart, zoneEnd, color);
      }
    }

   void SetZoneSeconds(int zoneNum, CRGB color){

      if(zoneNum > 0 && zoneNum <= 4){
        zoneNum = (zoneNum%4)+1;
        
        zoneStart = NUM_LEDS_PER_STRIP*(zoneNum-1);
        zoneEnd = NUM_LEDS_PER_STRIP*zoneNum;

        directControl.SetRangeSeconds(zoneStart, zoneEnd, color);
      }
    }

    void SetZone(enum zoneName z, CRGB color){
      switch(z){
        case BEHIND_SCREEN:
          zoneStart = 1460;
          zoneEnd = 1650;
        break;

        case DOOR_CORNER:
          zoneStart = 1660;
          zoneEnd = 100;
        break;

        case GUNS:{
          zoneStart = 735;
          zoneEnd = 814;
        break;
        }
      }

      if(zoneEnd < zoneStart){
        directControl.SetRangeTo(zoneStart, TOTAL_LEDS, color);
        directControl.SetRangeTo(1, zoneEnd, color);
      }else{
        directControl.SetRangeTo(zoneStart, zoneEnd, color);
      }
    }
};

zones zones;
