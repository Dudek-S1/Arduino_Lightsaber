// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 120 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
int a,b,n,m;
void light_blade()
{
  n=0;
  m=119;
  for(int i=0; i<60;i++)
    {
      
      
       
       pixels.setPixelColor(n, pixels.Color(0,0,150));
       n++;
       pixels.setPixelColor(m, pixels.Color(0,0,150));
       m--;
       pixels.show();
       delay(5);
    }
}
void off_blade()
{
  n=59;
  m=60 ;
  for(int i=0; i<60;i++)
    {
      
       pixels.setPixelColor(n, pixels.Color(0,0,0));
       n--;
       pixels.setPixelColor(m, pixels.Color(0,0,0));
       m++;
       pixels.show();
       delay(5);
    }
}

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  
  

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();
}

void loop() {
   // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
   light_blade();
   delay(2000);
   off_blade();
   delay(2000);
   
}
