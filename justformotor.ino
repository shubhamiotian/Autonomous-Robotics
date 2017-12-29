 int LM1 = 6;
 int LM2 = 5;
 int RM1 = 10;
 int RM2 = 11;

int LED = 13;

void setup() {

  Serial.begin (9600);

    pinMode(LED, OUTPUT);


  pinMode (LM1, OUTPUT);
  pinMode (LM2, OUTPUT);
  pinMode (RM1, OUTPUT);
  pinMode (RM2, OUTPUT);
 
  // put your setup code here, to run once:

}

void loop() 
{  
  // motor A = LM1 and LM2; motor B = RM1 and RM2 

void forward();
Serial.println("HI");
digitalWrite(LED,HIGH);
  delay (500);
  digitalWrite(LED,LOW);
  delay(500);

}

// put your main code here, to run repeatedly:
 
 
 void forward()

{
  
  digitalWrite (LM1,HIGH);
  digitalWrite (LM2,LOW);
  digitalWrite (RM1,HIGH);
  digitalWrite (RM2,LOW);
  
}

