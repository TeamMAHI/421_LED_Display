// Serial communication with Arduino (rotating shape)
import processing.serial.*;
Serial usbPort;
boolean firstContact = false; //sets firstContact to false to ensure Arduino keeps searching
float [] sensorData; //creates array for data
float [] sensors = null;
float xrot;
float yrot;
float zrot;
float xmove;
float ymove;
float zoom;
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
  translate(xmove, ymove);
  scale(zoom, zoom, zoom);
  
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
      float sensors[] = float(split(usbString, ',')); //splits string into integer values
      for (int sensorNum = 0; sensorNum <sensors.length; sensorNum++) {
      //println("Sensor" + sensorNum+ ":" + sensors [sensorNum]);
      }
      xrot = sensors[1];
      yrot = sensors[2];
      zrot = sensors[3];
      xmove = sensors[4];
      ymove = sensors[5];
      zoom = sensors[6];
      usbPort.write("A");
    }
  }
}
