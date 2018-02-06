// RGBW (Red Green Blue White Neo-Pixel starter code
// 16 LEDS  increment
// CW Coleman 170413

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 25

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// Initialize some variables for the void loop()
int red = 0, green= 0, blue = 0, white = 10;
int wait = 150;
int led = 0;
int i;

void loop() {
  
  for ( led = 0; led < 16; led++){  
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 155;
    green = green + 12;
    blue = blue + 155;
    white = white + 0;

    if (red > 250) red = 0;
    if (green > 125) green = 0;
    if (blue > 45) blue = 0;
    if (white > 150) white = 0;
       
    if (red < 0) red = 125;
    if (green  < 0) green = 125;
    if (blue < 0) blue = 125;
    if (white  < 0 ) white = 120;
}


