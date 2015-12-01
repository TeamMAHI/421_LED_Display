#define BUTTON1 10
#define BUTTON2 11
#define BUTTON3 12
#define SLIDER1 A2   //slider 1 is pin 2
#define SLIDER2 A1
#define SLIDER3 A0
#define LIGHT   A3

char START_BYTE = '*';
char Delimiter = ','; //specifying what the delimiter is
char END_BYTE = '#';

int slider1;
int slider2;
float slider3;

int xrot;
int yrot;
int zrot;

int xmove = 0;
int ymove = 0;
float zoom = 1.0;

int light = 0;
int avglight;

int shapechoice = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  establishContact();
  pinMode(SLIDER1, INPUT);
  pinMode(SLIDER2, INPUT);
  pinMode(SLIDER3, INPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(LIGHT, INPUT);
  
  // find avg light level
  for(int x = 0; x < 16; x++) {
  avglight += analogRead(LIGHT);
  }
  avglight /= 16; 

}

void loop() {
  //acquiring the slider data
  slider1 = analogRead(SLIDER1); //read slider 1
  slider2 = analogRead(SLIDER2); //read slider 2
  slider3 = analogRead(SLIDER3); //read slider 3 
  // transforming the slider data
  xmove = (map(slider1, 1, 1023, 0, 700)); //mapping the slider1 value
  ymove = (map(slider2, 1, 1023, 0, 700)); //mapping the slider2 value
  zoom = 0.005382*slider3 + 0.4946; //mapping the slider3 value. Needed a float, couldn't use map
  
  // collecting the light sensor data
  light = analogRead(LIGHT);
  
  //calculating the x rotation with BUTTON1
  if (digitalRead(BUTTON1) == LOW & light < (avglight * 3/4)) { // if the botton is pressed, rotate the object in x
    xrot = xrot + 2;    
    if (xrot == 360) {
      xrot = 0;
    }
  }
  else if (digitalRead(BUTTON1) == LOW) {
    xrot = xrot - 2;    
    if (xrot == 0) {
      xrot = 360;
    }
  }

  // calculating y-rotation with BUTTON2
  if (digitalRead(BUTTON2) == LOW & light < (avglight * 3/4)) { // if the botton is pressed, rotate the object in x
    yrot = yrot + 2;    
    if (yrot == 360) {
      yrot = 0;
    }
  }
  else if (digitalRead(BUTTON2) == LOW) {
    yrot = yrot - 2;    
    if (yrot == 0) {
      yrot = 360;
    }
  }

  // calculating z-rotation with BUTTON3
  if (digitalRead(BUTTON3) == LOW & light < (avglight * 3/4)) { // if the botton is pressed, rotate the object in x
    zrot = zrot + 2;    
    if (zrot == 360) {
      zrot = 0;
    }
  }
  else if (digitalRead(BUTTON3) == LOW) {
    zrot = zrot - 2;    
    if (zrot == 0) {
      zrot = 360;
    }
  }

// determining if the user wants to change images (pressing both BUTTON1 and BUTTON2)
  if (digitalRead(BUTTON1) == LOW & digitalRead(BUTTON2) == LOW) {
    shapechoice++; // add 1 to shapechoice
    if (shapechoice == 4) {
      shapechoice = 1;
    }
    delay(300);    // include a delay to ensure it doesn't increase more than 1 because of a
  }
  
  //sending the slider data
  Serial.print(START_BYTE);
  Serial.print(Delimiter); //inserts delimiter to separate data
  // Rotational mode
  Serial.print(xrot, DEC); //passes just a number to processing
  Serial.print(Delimiter); //inserts delimiter to separate data
  Serial.print(yrot, DEC); //passes just a number to processing
  Serial.print(Delimiter); //inserts delimiter to separate data
  Serial.print(zrot, DEC);
  Serial.print(Delimiter);
  // Translational/zoom mode
  Serial.print(xmove, DEC); 
  Serial.print(Delimiter); 
  Serial.print(ymove, DEC); 
  Serial.print(Delimiter); 
  Serial.print(zoom);
  Serial.print(Delimiter);
  // Shapechoice
  Serial.print(shapechoice);
  Serial.print(Delimiter);
  Serial.println(END_BYTE); //uses serial.println so that it sends a carriage return (signals end of data)

}

void establishContact() {
  while(Serial.available() <= 0) {
    Serial.println("Hello"); //prints Hello is there is NO communication 
    delay(300);
  }
}

