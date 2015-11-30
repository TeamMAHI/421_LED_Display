// John Michael Frullo & Cecilia Brookshier

// Serial communication handshake between Arduino and Processing, controlled by the DangerShield,
//   to send text to be displayed on NeoPixel

import processing.serial.*; //import the Serial library
Serial myPort;  //the Serial port object
String val;
// since we're doing serial handshaking, 
// we need to check if we've heard from the microcontroller
boolean firstContact = false;

int curr = 0;
int strcurr = 0; //current string

//News Feed:
//Different URLs to choose from
String Scienceurl = "http://rss.nytimes.com/services/xml/rss/nyt/Science.xml";
String USurl = "http://rss.nytimes.com/services/xml/rss/nyt/US.xml";
String Sportsurl = "http://rss.nytimes.com/services/xml/rss/nyt/Sports.xml";
String Techurl = "http://rss.nytimes.com/services/xml/rss/nyt/Technology.xml";
XML xml; //define the XML objects
XML channel;
XML[] children;
String[] UStitles = new String[20];
String[] USdesc = new String[20];
String[] Sciencetitles = new String[20];
String[] Sciencedesc = new String[20];
String[] Sportstitles = new String[20];
String[] Sportsdesc = new String[20];
String[] Techtitles = new String[20];
String[] Techdesc = new String[20];

//Date/Time
int m;
int h;
int d;
int mon;
int y;
String M;
String H;
String D;
String Mon;
String Y;

void setup() {
  size(200, 200); //make our canvas 200 x 200 pixels big

  //US
  // URL for the XML document New York Times section
  xml = loadXML(USurl);
  channel = xml.getChild("channel");
  children = channel.getChildren("item"); //get all of the headline titles
  //Gather all titles and save them in titles array
  for (int i = 0; i < children.length; i++) {
    UStitles[i] = children[i].getChild("title").getContent();
    String Desc = children[i].getChild("description").getContent();
    String[] desc = split(Desc, '<'); //split the description to only get relevant text (remove formatting text)
    USdesc[i] = desc[0];
  }
  //Science
  // URL for the XML document New York Times section
  xml = loadXML(Scienceurl);
  channel = xml.getChild("channel");
  children = channel.getChildren("item"); //get all of the headline titles
  //Gather all titles and save them in titles array
  for (int i = 0; i < children.length; i++) {
    Sciencetitles[i] = children[i].getChild("title").getContent();
    String Desc = children[i].getChild("description").getContent();
    String[] desc = split(Desc, '<'); //split the description to only get relevant text (remove formatting text)
    Sciencedesc[i] = desc[0];
  }
  //Sports
  // URL for the XML document New York Times section
  xml = loadXML(Sportsurl);
  channel = xml.getChild("channel");
  children = channel.getChildren("item"); //get all of the headline titles
  //Gather all titles and save them in titles array
  for (int i = 0; i < children.length; i++) {
    Sportstitles[i] = children[i].getChild("title").getContent();
    String Desc = children[i].getChild("description").getContent();
    String[] desc = split(Desc, '<'); //split the description to only get relevant text (remove formatting text)
    Sportsdesc[i] = desc[0];
  }
  //Tech
  // URL for the XML document New York Times section
  xml = loadXML(Techurl);
  channel = xml.getChild("channel");
  children = channel.getChildren("item"); //get all of the headline titles
  //Gather all titles and save them in titles array
  for (int i = 0; i < children.length; i++) {
    Techtitles[i] = children[i].getChild("title").getContent();
    String Desc = children[i].getChild("description").getContent();
    String[] desc = split(Desc, '<'); //split the description to only get relevant text (remove formatting text)
    Techdesc[i] = desc[0];
  }

  //  initialize your serial port
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  //we can leave the draw method empty, 
  //because all our programming happens in the serialEvent (see below)
}

void serialEvent( Serial myPort) {
  //put the incoming data into a String - 
  //the '\n' is our end delimiter indicating the end of a complete packet
  val = myPort.readStringUntil('\n');
  //make sure our data isn't empty before continuing
  if (val != null) {
    //trim whitespace and formatting characters (like carriage return)
    val = trim(val);

    //look for our 'A' string to start the handshake
    //if it's there, clear the buffer, and send a request for data
    if (firstContact == false) {
      if (val.equals("A")) {
        myPort.clear();
        firstContact = true;
        myPort.write("A");
        println("contact");
      }
    } else { //if we've already established contact, keep getting and parsing data

      //take out later - for prototyping
      if (val.equals("^") == false) {
        println(val);
      }

      if (val.equals("US")) {
        myPort.write("echo: US");
        strcurr = 1;
      } 
      else if (val.equals("Select")) {
        //strcurr = 2;
      } 
      else if (val.equals("Science")) {
        myPort.write("echo: Science");
        strcurr = 3;
      } 
      else if (val.equals("Sports")) {
        myPort.write("echo: Sports");
        strcurr = 4;
      } 
      else if (val.equals("Tech")) {
        myPort.write("echo: Tech");
        strcurr = 5;
      }
      else if (val.equals("Date")) { //get date and time
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
        myPort.write(Mon+ "/"+ D +"/"+ Y+ " "+ H+ ":" +M);
        println(Mon+ "/"+ D +"/"+ Y+ " "+ H+ ":" +M);
        strcurr = 0;
      }
      else {
        curr = parseInt(val);
        if (strcurr == 1) {
          myPort.write(curr+ ": "+ UStitles[curr]);
        }
        //else if (strcurr == 2) {
        //  myPort.write(curr+ ": "+ USdesc[curr]);
        //} 
        else if (strcurr == 3) {
          myPort.write(curr+ ": "+ Sciencetitles[curr]);
        } 
        else if (strcurr == 4) {
          myPort.write(curr+ ": "+ Sportstitles[curr]);
        } 
        else if (strcurr == 5) {
          myPort.write(curr+ ": "+ Techtitles[curr]);
        }
      }

      // when you've parsed the data you have, ask for more:
      myPort.write("@");
    }
  }
}