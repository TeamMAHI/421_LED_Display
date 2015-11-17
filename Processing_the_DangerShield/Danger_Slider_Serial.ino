#define BUTTON1 10
#define BUTTON2 11
#define BUTTON3 12
#define SLIDER1 A2   //slider 1 is pin 2
#define SLIDER2 A1
#define SLIDER3 A0
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
boolean mode = true; //sets the mode to true 
                     // True = rotation mode
                     // False = translation zoom mode

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  establishContact();
  pinMode(SLIDER1, INPUT);
  pinMode(SLIDER2, INPUT);
  pinMode(SLIDER3, INPUT);
  pinMode(BUTTON1, INPUT_PULLUP);

}

void loop() {
  //acquiring the slider data
  slider1 = analogRead(SLIDER1); //read slider 1
  slider2 = analogRead(SLIDER2); //read slider 2
  slider3 = analogRead(SLIDER3); //read slider 3 
  
  //determining the mode
  if (digitalRead(BUTTON1) == LOW) { // if the botton is pressed, switch the boolean
    mode = !mode; //switch the boolean
  }

  if (mode == true) { // if the mode is true, so rotational mode...
    xrot = (map(slider1, 1, 1023, 0, 360)); //mapping the slider1 value
    yrot = (map(slider2, 1, 1023, 0, 360)); //mapping the slider2 value
    zrot = (map(slider3, 1, 1023, 0, 360)); //mapping the slider3 value
  }
  else {
    xmove = (map(slider1, 1, 1023, 0, 700)); //mapping the slider1 value
    ymove = (map(slider2, 1, 1023, 0, 700)); //mapping the slider2 value
    //zoom = float(map(slider3, 1.0, 1023.0, 0.5, 6.0)); //mapping the slider3 value
    zoom = 0.005382*slider3 + 0.4946;  
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
  Serial.print(mode);
  Serial.print(Delimiter);
  Serial.println(END_BYTE); //uses serial.println so that it sends a carriage return (signals end of data)

}

void establishContact() {
  while(Serial.available() <= 0) {
    Serial.println("Hello"); //prints Hello is there is NO communication 
    delay(300);
  }
}

