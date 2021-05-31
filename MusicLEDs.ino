#include <FastLED.h>

int r=252;
int g=0;
int b=0;

#define LED_PIN     7
#define NUM_LEDS    30

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int s=0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = 4; i >= 0; i--) 
  {
     leds[i] = CRGB ( r,g,b);
     leds[29-i] = CRGB (r,g,b );
     delay(40);
    FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}
void loop()
{
  s=analogRead(A0);
  Serial.println(s);
  if((s>=26)&&(s<=28))
  {
    leds[14]=CRGB (150, 50, 204);
    leds[15]=CRGB (150, 50, 204);
  }
  else if((s>=1021)&&(s<=1023))
   {
     leds[14]=CRGB (20, 217, 30); 
    leds[15]=CRGB (20, 217, 30);
   }
  else
  {
     leds[14] = CRGB ( r,g,b);
     leds[15] = CRGB ( r,g,b);
  }
    for (int i = 0; i <= 13; i++) 
  {
     leds[i] = leds[i+1];
     leds[29-i] = leds[28-i];
     
  }
 FastLED.show();
 delay(30);

  
  
 
}
