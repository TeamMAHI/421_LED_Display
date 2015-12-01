// John Michael and Cecilia

// This processing code handles the serial communication 
// with Arduino, and uses the DangerShield to rotate, translate,
// and zoom into a complex image

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
float zoom = 1.0;
float Size;
float shapechoice = 1.0; 

PShape RhoAGDPbound;
PShape rat;
PShape rocket;

void setup() {
  size( 700, 700, P3D);
  Size = width/6;
  
  RhoAGDPbound = loadShape("1FTN-ribbon.obj");
  rat = loadShape("2231-0.obj");
  rocket = loadShape("rocket.obj");
  
  //Serial.list() [0] lists the available Serial Port on the computer, 0 means the first value in the array which is the one Serial Port processing uses 
  usbPort = new Serial (this, Serial.list() [0], 9600); 
  usbPort.bufferUntil('\n');
}


void draw() {
  background(0,0,20);
  lights();
  
  if (shapechoice == 1.0) {
    translate(xmove, ymove);
    scale(7+zoom, 7+zoom, 7+zoom);
  
    rotateX(radians(xrot));
    rotateY(radians(yrot));
    rotateZ(radians(zrot));
    shape(RhoAGDPbound);
  }
  
  if (shapechoice == 2.0) {
    translate(xmove, ymove);
    scale(1+(0.5*zoom), 1+(0.5*zoom), 1+(0.5*zoom));
  
    rotateX(radians(xrot+90));
    rotateY(radians(yrot));
    rotateZ(radians(zrot));
    shape(rat);
  }
  
  if (shapechoice == 3.0) {
    translate(xmove, ymove);
    scale(zoom, zoom, zoom);
  
    rotateX(radians(xrot));
    rotateY(radians(yrot));
    rotateZ(radians(zrot+180));
    shape(rocket);
  }
  
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
      
      float oldxmove = xmove;
      xmove = sensors[4];
      // The following code prevents the jitters/vibrations caused by small translational/zoom changes
      if (abs(oldxmove - xmove) < 3) { //so if the change is too small, keep xmove as the previous value
        xmove = oldxmove;
      }
      
      float oldymove = ymove;
      ymove = sensors[5];
      if (abs(oldymove - ymove) < 3) {
        ymove = oldymove;
      }
      
      float oldzoom = zoom; //store old value
      zoom = sensors[6];
      if (abs(oldzoom - zoom) < 0.05) {
        zoom = oldzoom;
      }
      
      shapechoice = sensors[7];
      usbPort.write("A");
    }
  }
}
