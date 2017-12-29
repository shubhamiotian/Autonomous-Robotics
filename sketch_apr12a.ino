int led=13; 

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led,LOW);
delay(1000);
}



  
  // put your main code here, to run repeatedly:


