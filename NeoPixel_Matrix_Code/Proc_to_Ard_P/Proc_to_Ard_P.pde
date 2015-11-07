import processing.serial.*;

Serial myPort;

void setup()
{
  size(200,200);
  //println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (mousePressed == true)
  {
    myPort.write('1');
    println("1");
  } else
  {
    myPort.write('0');
  }
}