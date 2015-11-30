// John Michael Frullo & Cecilia Brookshier

// Serial communication handshake between Arduino and Processing, controlled by the DangerShield,
//   to send text to be displayed on NeoPixel

// Levels:
//
//  _0__             |     _1__                     |       _2__
//  Home             |                              |
//  Date/Time        |                              |
//  News             | US, Science, Sports, Tech    |     Headlines
//  ???-Coming Soon  |                              |


#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <CapacitiveSensor.h>

#define PIN 13
#define SLIDER1  A2 //Matches button 1
#define SLIDER2  A1 
#define SLIDER3  A0 //Matches button 3
#define BUTTON1  10
#define BUTTON2  11
#define BUTTON3  12
#define DATA     4
#define LATCH    7
#define CLOCK    8

// Create the Neomatrix object
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG, NEO_GRB + NEO_KHZ800);

String val; // Data received from the serial port
String str;
String opts[4] = {"Home", "Date/Time", "News", "??? - Coming Soon"}; 
String news[4] = {"US", "Science", "Sports", "Tech"};
String commstr;

int level = 0; //current display level
int curr = 0; //current display index
int oldcurr = 0;
int L; //Length of text currently displayed
int newsind = 0; //indicate if news is the display option
int dateind = 0; //indicate if date is the display option
int ctime;
int otime = 0;
int homecnt = 0; // timer for return to home

int R = 255; // colors read by sliders (default, Red)
int G = 0;
int B = 0;
int Bval = 20; //brightness
int Sval = 50; //speed

void setup() 
{
  matrix.begin();
  matrix.setTextWrap(false);

  //initialize serial communications
  Serial.begin(9600);

  pinMode(SLIDER1, INPUT); //DangerShield inputs
  pinMode(SLIDER2, INPUT);
  pinMode(SLIDER3, INPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  digitalWrite(LATCH, LOW); // turn off the seven segment LED
  shiftOut(DATA, CLOCK, MSBFIRST, ~(00000000));
  digitalWrite(LATCH, HIGH);

  establishContact();  // send a byte to establish contact until receiver responds 
}

int x = matrix.width();

void loop()
{
  
  oldcurr = curr;
  
  int val1 = analogRead(SLIDER1); // read the sensor values
  int val2 = analogRead(SLIDER2);
  int val3 = analogRead(SLIDER3);

  if (digitalRead(BUTTON1) == LOW) { // select the color
    R = map(val1, 0, 1020, 0, 255);
    G = map(val2, 0, 1020, 0, 255);
    B = map(val3, 0, 1020, 0, 255);
  }
  else {
    if (level == 0) { //Home
      curr = map(val1, 0, 1020, 0, 3); //Map the slider location to a text option
    }
    else if (level == 1 ) {
      curr = map(val1, 0, 1020, 0, 3); //Map the slider location to a text option
    }
    else if (level == 2) {
      curr = map(val1, 0, 1020, 0, 19); //Map the slider location to a text option 
    }
    Sval = map(val2, 0, 1020, 10, 200); //Map the slider value to a scroll speed
    Bval = map(val3, 0, 1020, 0, 60); //Map the slider value to a brightness
  }

  if (digitalRead(BUTTON2) == LOW) { //Select the next mode of display
    if (level == 2) {
      if (newsind == 1) {
        level = 3;
        Serial.println("Select");
      }
    }
    if (level == 1) {
      if (newsind == 1) {
        level = 2;
        Serial.println(news[curr]);
      }
    }
    if (level == 0) {
      if (curr == 2) {
        newsind = 1;
        level = 1;
      }
      else if (curr == 1) {
        dateind = 1;
        level = 1;
        Serial.println("Date");
      }
    }
    delay(200);
    x = matrix.width();
  }
  
  if (digitalRead(BUTTON3) == LOW) { //Return to Home
    if (level == 0) {
      //do nothing
    }
    else if (level == 1) {
      level = 0;
      newsind = 0;
      dateind = 0;
      otime = 0;
    }
    else {
      level = level -1;
    }
    x = matrix.width();
    delay(200);
  }
  
  if (curr != oldcurr) {
    x = matrix.width();
    if (level == 2) {
      Serial.println(curr);
    }
  }
  
  if (dateind == 1) {
    ctime = millis() - otime;
    if (ctime > 20000) {
      otime = otime + ctime;
      Serial.println("Date");
    }
  }

  //Matrix Code
  matrix.setTextColor(matrix.Color(R,G,B));
  matrix.setBrightness(Bval);

  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  
  if (level == 0) {
    commstr = opts[curr];
  }
  else if (level == 1) {
    if (newsind == 1) {
      commstr = news[curr];
    }
    else {
      commstr = str; //date
    }
  }
  else if (level == 2) {
    commstr = str; //titles
  }
  else if (level == 3) {
    commstr = str;
  }
  else { //if error
    commstr = "Go home.. you're drunk";
  }
  matrix.print(commstr);
  L = commstr.length();
  if(--x < -(6*L)) {
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

void serialEvent() {
  if (Serial.available() > 0) { // If data is available to read,

    val = Serial.readStringUntil('\n');
    if (val.substring(0,(val.length()-1)).equals("@") == false) {
      str = val.substring(0,(val.length()-1));
    }
    delay(100);
  } 
}



