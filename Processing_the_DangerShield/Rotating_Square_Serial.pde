// Serial communication with Arduino (rotating shape)
import processing.serial.*;
Serial usbPort;
boolean firstContact = false; //sets firstContact to false to ensure Arduino keeps searching
int [] sensorData; //creates array for data
int [] sensors = null;
int xrot;
int yrot;
int zrot;
float Size;

void setup() {
  size( 700, 700, P3D);
  Size = width/6;
  
  //Serial.list() [0] lists the available Serial Port on the computer, 0 means the first value in the array which is the one Serial Port processing uses 
  usbPort = new Serial (this, Serial.list() [0], 9600); 
  usbPort.bufferUntil('\n');
}


void draw() {
  background(126);
  translate(width/2, height/2);
  
  rotateX(radians(xrot));
  rotateY(radians(yrot));
  rotateZ(radians(zrot));
  
  fill(0, 250, 250);
  //rect(-rSize, -rSize, rSize*2, rSize*2);
  box(Size*2);
}


void serialEvent(Serial usbPort) {
  String usbString = usbPort.readStringUntil ('\n'); //fills usbString with data over usbPort
  if (usbString != null) {   //so if string is not empty...
    usbString = trim(usbString); //remove carriage return and any whitespace characters
    if (firstContact == false) {
      if (usbString.equals("Hello")) {
        usbPort.clear();
        firstContact = true; //changes contact to true
        usbPort.write('A');
        println("contact");
      }
    }
    else {
      int sensors[] = int(split(usbString, ',')); //splits string into integer values
      for (int sensorNum = 0; sensorNum <sensors.length; sensorNum++) {
      //println("Sensor" + sensorNum+ ":" + sensors [sensorNum]);
      }
      int slider1 = sensors[1];
      int slider2 = sensors[2];
      int slider3 = sensors[3];
      xrot = int(map(slider1, 1, 1023, 0, 360)); //mapping the slider1 value
      yrot = int(map(slider2, 1, 1023, 0, 360)); //mapping the slider2 value
      zrot = int(map(slider3, 1, 1023, 0, 360)); //mapping the slider3 value
      usbPort.write("A");
    }
  }
}
