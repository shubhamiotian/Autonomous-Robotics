int lm1=10;
int lm2=11;
int rm1=5;
int rm2 = 6;
int s1=A0,s2=A1,s3=A2,s4=A3,s5=A4,s6=A5;
int sem1=0,sem2=0,sem3=0,sem4=0,sem5=0,sem6=0;
int lr = 0;

int k=600;


void setup() {
  
Serial.begin(9800);
pinMode(lm1,OUTPUT);  
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);

pinMode(s1,INPUT);  
pinMode(s2,INPUT);
pinMode(s3,INPUT);  
pinMode(s4,INPUT);
pinMode(s5,INPUT);
pinMode(s6,INPUT);
}

void loop() {
//motor_check();
//pwm_frwd();
//delay(3000);
//pwm_left();
//delay(3000);
//pwm_right();
//delay(3000);
//check();

assign();

//motor_check();
if((sem1==1&&sem2==1&&sem3==0&&sem4==0&&sem5==1&&sem6==1)||(sem1==1&&sem2==1&&sem4==0&&sem5==0&&sem6==1)||(sem1==1&&sem2==0&&sem4==0&&sem5==1&&sem6==1))
   {
    pwm_frwd();
    lr=3;
   }
else if(sem1==1&&sem2==1&&sem3==1&&sem4==1&&sem5==1&&sem6==1)  //all black
{
 if(lr==1)
    {
      pwm_left();
      lr=2;
    }
  else if(lr==2)
    {
       pwm_right();   
       lr=1;
    } 
  else if(lr==3)
    {
        pwm_bckwd();
      
      } 
   else
     halt();     
  
 // pwm_bckwd();
}
else if((sem1==1 && sem2==1 && (sem3 == 0|| sem4==0) &&sem5==0   && sem6 == 0)||(sem1==1 && sem2==1 && sem3 == 1 && sem4==1 &&sem5==0   && sem6 == 0)||(sem1==1 && sem2==1 && sem3 ==1&&sem4==1 &&sem5==1   && sem6 == 0))
{
   pwm_right();
   lr=1;
}
else if((sem1==0 && sem2==0 && (sem3 == 0 || sem4==0) &&sem5==1   && sem6 == 1)||(sem1==0 && sem2==1 && sem3 == 1 && sem4==1 &&sem5==1   && sem6 == 1)||(sem1==0 && sem2==0 && sem3 ==1 &&sem4==1 &&sem5==1   && sem6 == 1))
{
   pwm_left();
   lr=2;
                                                                                        
}
}

void frwd()
{
digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);  
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);
  }

void pwm_frwd()
{
 Serial.println("forward");
analogWrite(lm1,70);
analogWrite(lm2,0);  
analogWrite(rm1,70);
analogWrite(rm2,0);
  }
    void pwm_bckwd()
{
analogWrite(lm1,0);
analogWrite(lm2,70);  
analogWrite(rm1,0);
analogWrite(rm2,70);
  }
void right(){
digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
digitalWrite(rm1,LOW);
digitalWrite(rm2,HIGH);
}
void pwm_right()
{
  Serial.println("right");
digitalWrite(lm1,0);
analogWrite(lm2,90);  
analogWrite(rm1,90);
analogWrite(rm2,0);
  
  }
  void pwm_left()
{
  Serial.println("left");
analogWrite(lm1,90);
analogWrite(lm2,0);  
analogWrite(rm1,0);
analogWrite(rm2,90);
  
  }

void left(){
digitalWrite(lm1,LOW);
digitalWrite(lm2,HIGH);
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
}


void halt(){
  Serial.println("halt");
digitalWrite(lm1,LOW);
digitalWrite(lm2,LOW);  
digitalWrite(rm1,LOW);
digitalWrite(rm2,LOW);
  }
  
void bckwd(){
digitalWrite(lm1,LOW);
digitalWrite(lm2,HIGH);  
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
  }



void motor_check()
{
    
//pwm_frwd();
 pwm_frwd();
delay(5000);
pwm_bckwd();
delay(5000);
pwm_left();
//left();
delay(5000);
pwm_right();
//right();
delay(5000);
    
    }

void check(){
  Serial.println("--------------");
  /*Serial.println(analogRead(s1));
  Serial.println(analogRead(s2));
  Serial.println(analogRead(s3));
  Serial.println(analogRead(s4));
  Serial.println(analogRead(s5));
  Serial.println(analogRead(s6));
  Serial.println("--------------");*/
  assign();
  Serial.println("the array is:");
  Serial.print(sem1);
  Serial.print(sem2);
  Serial.print(sem3);
  Serial.print(sem4);
  Serial.print(sem5);
  Serial.println(sem6);                                                                                                                                                                        ;(analogRead(s6));
  
  
}

void assign(){
  sem1= analogRead(s1)/k; 
  sem2= analogRead(s2)/k;
  sem3= analogRead(s3)/k;
  sem4= analogRead(s4)/k;
  sem5= analogRead(s5)/k;
  sem6= analogRead(s6)/k;
}
  
