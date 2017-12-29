#define echopin  13 // echo pin it recieves the signal
#define trigpin 14 // Trigger pin  it sends the signal
int maximumRange = 40;
long duration, distance;

void setup() {
  Serial.begin (115200);
  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
//  pinMode (2, OUTPUT);
//  pinMode (3, OUTPUT);
//  pinMode (4, OUTPUT);
//  pinMode (5, OUTPUT);
}
void loop ()
{

  {
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    duration=pulseIn (echopin,HIGH);
    distance = (duration/2) / 29.1;//29.1 is th\e pace of the sound instead of using the Speed of Sound, we can also use the "Pace of Sound".
                                   //The Pace of Sound = (1 / Speed of Sound) = 1 / 0.03435 = 29.1 ss/cm
    delay (100);
    Serial.println(distance);
  }
  
  if (distance<=40)
  Serial.println(Danger!!!!);
  }
