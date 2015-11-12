//John Michael Frullo and Cecilia Brookshier

//uses Processing sketches that stream text information to control the stream of words across the NeoPixel 8x32 matrix


#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

#define PIN 13
#define SLIDER1  A2 //Matches button 1
#define SLIDER2  A1 
#define SLIDER3  A0 //Matches button 3
#define BUTTON1  10
#define DATA     4
#define LATCH    7
#define CLOCK    8

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
//Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(5, 8, PIN,
//  NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
//  NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
//  NEO_GRB            + NEO_KHZ800);
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);

//const uint16_t colors[] = {
//  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };

String val; // Data received from the serial port
String str;
int R = 255; // colors read by sliders (default, Red)
int G = 0;
int B = 0;
int Bval = 20; //brightness
int Sval = 50; //speed

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  
  Serial.begin(9600); // Start serial communication at 9600 bps
  
  pinMode(SLIDER1, INPUT);
  pinMode(SLIDER2, INPUT);
  pinMode(SLIDER3, INPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  digitalWrite(LATCH, LOW); // turn off the seven segment LED
  shiftOut(DATA, CLOCK, MSBFIRST, ~(00000000));
  digitalWrite(LATCH, HIGH);
  
  establishContact();  // send a byte to establish contact until receiver responds
}

int x    = matrix.width();
int pass = 0;

void loop() {
  int val1 = analogRead(SLIDER1);
  int val2 = analogRead(SLIDER2);
  int val3 = analogRead(SLIDER3);
  
  if(digitalRead(BUTTON1) == LOW) {
    R = map(val1, 0, 1020, 0, 255);
    G = map(val2, 0, 1020, 0, 255);
    B = map(val3, 0, 1020, 0, 255);
  } 
  else {
    Sval = map(val2, 0, 1020, 10, 200); //Map the slider value to a scroll speed
    Bval = map(val3, 0, 1020, 0, 60); //Map the slider value to a brightness
  }
  matrix.setTextColor(matrix.Color(R,G,B));
//  int Cval = map(val1, 0, 1020, 0, 2); //Map the slider value to Color option
//  matrix.setTextColor(colors[Cval]);
  
  matrix.setBrightness(Bval);
  
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.readStringUntil('!'); // read it and store it in val
  }
  if(strcmp("A",(char*) val[0]) != 1) {
    str = val; 
  }
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(str);
  if(--x < -60) {
    x = matrix.width();
  }
  matrix.show();
  delay(Sval);
}

void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}
