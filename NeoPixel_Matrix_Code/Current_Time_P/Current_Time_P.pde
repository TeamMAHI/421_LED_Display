import processing.serial.*;

Serial myPort;

int s;
int m;
int h;
String S;
String M;
String H;

void setup()
{
  size(200,200);
  //println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  //if (mousePressed == true)
  //{
    //myPort.write('1');
    s = second();
    if(s<10){
      S = "0"+s;
    } else {
      S = ""+ s;
    }
    m = minute();
    if(m<10){
      M = "0"+m;
    } else {
      M = ""+m;
    }
    h = hour();
    if(h<10){
      H = "0"+h;
    } else {
      H = ""+h;
    }
    
    myPort.write(H+ ":" +M+ ":" +S+ "!");
    println(H+ ":" +M+ ":" +S+ "!");
  //} else
  //{
  //  myPort.write('0');
  //}
  delay(1000);
}