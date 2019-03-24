// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

class Position {
  public:
    Position(int r, int c) { row = r; col = c; }
    int toIndex() { return 0; }
  private:
    int row, col;
};

//
//  Since this converts a position into a neo index, it should be
//  incorporated into the Position class.
//
int rowcol2idx(int row, int col) {
  int colstart = col * 8;
  if((col % 2) != 0) {
    return colstart + (7 - row);
  } else {
    return colstart + row;
  }
}

//
//  Given a position in the upper left and lower
//  right corners, draw the rectangle with the specified
//  color.  This function should just update the model.
//  It should not call show or clear, etc...
//
void drawRectangle(AdaFruit_NeoPixel &pixels, Position ul, Position lr, Adafruit_NeoPixel::Color c) {
  return;
}

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.clear();
  pixels.show();
}

void loop() {
  for(int i = 0; i < 8; i++){
    pixels.setPixelColor(rowcol2idx(0,i), pixels.Color(5,0,5));
    pixels.show();
    delay(delayval);
}

for(int l = 0; l < 8; l++){
    pixels.setPixelColor(rowcol2idx(l, 7), pixels.Color(5,0,5));
    pixels.show();
    delay(delayval);
}

for(int j = 0; j < 8; j++){
    pixels.setPixelColor(rowcol2idx(7,(7 - j)), pixels.Color(5,0,5));
    pixels.show();
    delay(delayval);
}

for(int q = 0; q < 8; q++){
    pixels.setPixelColor(rowcol2idx((7 - q), 0), pixels.Color(5,0,5));
    pixels.show();
    delay(delayval);
}

  delay(5000);
  pixels.clear();
  pixels.show();

/*
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(5,0,5)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  */
}
