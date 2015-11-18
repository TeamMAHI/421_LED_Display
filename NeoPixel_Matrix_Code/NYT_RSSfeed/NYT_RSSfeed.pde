//John Michael Frullo & Cecilia Brookshier
// uses RSS feeds from New York Times to display headlines

String[] titles = new String[20];

//Different URLs to choose from
String Scienceurl = "http://rss.nytimes.com/services/xml/rss/nyt/Science.xml";
String USurl = "http://rss.nytimes.com/services/xml/rss/nyt/US.xml";
String Sportsurl = "http://rss.nytimes.com/services/xml/rss/nyt/Sports.xml";
String Techurl = "http://rss.nytimes.com/services/xml/rss/nyt/Technology.xml";

int thiskey = 0; //default is first headline
int lastkey = 0; 

XML xml; //define the XML objects
XML channel;
XML[] children;

void setup() {
  size (600,360);
  
  // URL for the XML document New York Times section
  xml = loadXML(Scienceurl);
  channel = xml.getChild("channel");
  children = channel.getChildren("item"); //get all of the headline titles
  //println(xml.toString()); // print the XML tree to see what children are for each branch
  
  //Gather all titles and save them in titles array
  for (int i = 0; i < children.length; i++) {
    titles[i] = children[i].getChild("title").getContent();
  }
  // .. and print the titles array to view contents
  //for (int i = 0; i<children.length; i++) {
  //  println(titles[i]);
  //  println(" ");
  //}
}

void draw() {
  background(255);
  fill(0);
  
}

void keyPressed() {
  if((key >= 'a') && (key <= 't')) {
    thiskey = int(key - 'a');
    println(titles[thiskey]);
    println(" ");
    lastkey = thiskey;
  }
  if(key == '0') {
    String Desc = children[lastkey].getChild("description").getContent();
    String[] desc = split(Desc, '<'); //split the description to only get relevant text (remove formatting text)
    println(desc[0]);
    println(" ");
  }
  
}