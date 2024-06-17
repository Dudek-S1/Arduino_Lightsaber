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
int stan = 0;
int tryb = 1;
int a, b, n, m;
int r,g;
int pp1,pp2,pp3,pp4,pp8,pp9,pp10,pp11;

void light_blade()
{
  n = 0;
  m = 119;
  for (int i = 0; i < 60; i++)
  {



    pixels.setPixelColor(n, pixels.Color(r, g, b));
    n++;
    pixels.setPixelColor(m, pixels.Color(r, g, b));
    m--;
    pixels.show();
    delay(5);
  }
}
void off_blade()
{
  n = 59;
  m = 60 ;
  for (int i = 0; i < 60; i++)
  {

    pixels.setPixelColor(n, pixels.Color(0, 0, 0));
    n--;
    pixels.setPixelColor(m, pixels.Color(0, 0, 0));
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
  Serial.begin(115200);
  pinMode(2, INPUT);
  n = 0;
  m = 120;
  r=0;
  b=150;
  g=0;
  a=121;
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear();
  delay(2000);
}

void loop() {

  stan = digitalRead(2);
  if (stan == 1)
  {
    tryb++;
    delay(500);

  }
  if (tryb >6)
    {
      tryb = 1;
    }
  if (tryb == 6)
  {
    off_blade();
    delay(1000);
    //tryb++;
  }
  if (tryb == 5)
  {
    r=0;
    g=140;
    b=0;
    light_blade();
  }
  if (tryb == 4)
  {
    off_blade();
    delay(1000);
    //tryb++;
  }
  if (tryb == 3)
  {
    r=0;
    g=0;
    b=140;
    light_blade();
  }
  if (tryb == 2)
  {
     off_blade();
    delay(1000);
   // tryb++;
  }
  if (tryb == 1)
  {
    r=140;
    g=0;
    b=0;
    light_blade();  
  }
   

  Serial.println(tryb);
  delay(10);

}

