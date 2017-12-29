#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX of bt to 10, RX of bt to 11 arduino respetively
String readdata;

void setup() {
 BT.begin(38400);
 Serial.begin(9600);
  pinMode(13, OUTPUT);
//  pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);
//  pinMode(9, OUTPUT);

}
//-----------------------------------------------------------------------//
void loop() {
  while (BT.available())
  {  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

  if(readdata == "ON")
  {
    digitalWrite(13,HIGH);
//   analogWrite(3,190);
//    analogWrite(5,0);
//    analogWrite(6,0);
//    analogWrite(9,190);
    delay (100);
  }

  else if(readdata == "OFF")
  {
    digitalWrite(13, LOW);
//    analogWrite (3,0);
//    analogWrite (5,190);
//    analogWrite (6,190);
//    analogWrite (9,0);
    delay (100);
}

//  else if (readdata == "right")
//  {
//   
//    analogWrite(3,190);
//    analogWrite(5,0);
//    analogWrite(6,190);
//    analogWrite(9,0);
//    delay (100);
//  
//   
//  }
//
// else if ( readdata == "left")
// {
// 
//    analogWrite (3,30);
//    analogWrite (5,190);
//    analogWrite (6,90);
//    analogWrite (9,190);
//    delay (100);
//
// }
//
// else if (readdata == "stop")
// {
//  
//   digitalWrite (3, LOW);
//   digitalWrite (4, LOW);
//   digitalWrite (5, LOW);
//   digitalWrite (6, LOW);
//   delay (100);
// }

 


readdata="";}} //Reset the variable
