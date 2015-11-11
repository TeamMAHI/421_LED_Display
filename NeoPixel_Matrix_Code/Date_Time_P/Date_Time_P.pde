import processing.serial.*;

Serial myPort;
String val;
boolean firstContact = false;
boolean sender = true;
int s;
int m;
int h;
int d;
int mon;
int y;
String S;
String M;
String H;
String D;
String Mon;
String Y;
int otime = 0; //keep track of millis

void setup()
{
  size(200, 200);
  //println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  int ctime = millis() - otime; //update ctime
  if (ctime > 20000) {
    sender = true; //turn on "sender" var again to resend info
    otime = otime + ctime; // update otime
  }
  if (sender == true) {  
    //s = second();
    //if(s<10){
    //  S = "0"+s;
    //} else {
    //  S = ""+ s;
    //}
    m = minute();
    if (m<10) {
      M = "0"+m;
    } else {
      M = ""+m;
    }
    h = hour();
    if (h<10) {
      H = "0"+h;
    } else {
      H = ""+h;
    }
    d = day();
    if (d<10) {
      D = "0"+d;
    } else {
      D = ""+d;
    }
    mon = month();
    if (mon<10) {
      Mon = "0"+mon;
    } else {
      Mon = ""+mon;
    }
    y = year()-2000;
    if (y<10) {
      Y = "0"+y;
    } else {
      Y = ""+y;
    }
    //myPort.write(H+ ":" +M+ ":" +S+ "!");
    //println(H+ ":" +M+ ":" +S+ "!");
    myPort.write(Mon+ "/"+ D +"/"+ Y+ " "+ H+ ":" +M+ "!");
    println(Mon+ "/"+ D +"/"+ Y+ " "+ H+ ":" +M+ "!");
    sender = false;
  }
}

void serialEvent( Serial myPort) {
  //put the incoming data into a String - 
  //the '\n' is our end delimiter indicating the end of a complete packet
  val = myPort.readStringUntil('\n');
  //make sure our data isn't empty before continuing
  if (val != null) {
    //trim whitespace and formatting characters (like carriage return)
    val = trim(val);
    println(val);

    //look for our 'A' string to start the handshake
    //if it's there, clear the buffer, and send a request for data
    if (firstContact == false) {
      if (val.equals("A")) {
        myPort.clear();
        firstContact = true;
        myPort.write("A");
        println("contact");
      }
    }
  }
}