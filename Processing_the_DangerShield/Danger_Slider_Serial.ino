#define BUTTON1 10
#define BUTTON2 11
#define BUTTON3 12
#define SLIDER1 2   //slider 1 is pin 2
#define SLIDER2 1
#define SLIDER3 0
char START_BYTE = '*';
char Delimiter = ','; //specifying what the delimiter is
char END_BYTE = '#';
int xrot;
int yrot;
int zrot;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  establishContact();

}

void loop() {
  //acquiring the slider data
  xrot = analogRead(SLIDER1); //read slider 1
  yrot = analogRead(SLIDER2); //read slider 2
  zrot = analogRead(SLIDER3); //read slider 3 
  
  //sending the slider data
  Serial.print(START_BYTE);
  Serial.print(xrot, DEC); //passes just a number to processing
  Serial.print(Delimiter); //inserts delimiter to separate data
  Serial.print(yrot, DEC); //passes just a number to processing
  Serial.print(Delimiter); //inserts delimiter to separate data
  Serial.print(zrot, DEC);
  Serial.print(Delimiter);
  Serial.println(END_BYTE); //uses serial.println so that it sends a carriage return (signals end of data)

}

void establishContact() {
  while(Serial.available() <= 0) {
    Serial.println("Hello"); //prints Hello is there is NO communication 
    delay(300);
  }
}

