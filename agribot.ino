#include <Servo.h>
Servo Smst;
Servo Ssdr;
Servo Sspr;


// Starting of Program
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
int pmp = 6;

char val;

void setup() 
{  
  Smst.attach(3);
  Ssdr.attach(4);
  Sspr.attach(5);
  
  pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
  pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
  pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
  pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
  pinMode(pmp, OUTPUT);  // Digital pin 6 set as output Pin
  
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
    }
else if(val == 'L') //Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(val == 'R') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
    }
  else if(val == 'I') //Forward Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
else if(val == 'J') //Backward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   else if(val == 'G') //Forward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);     
    digitalWrite(m2b, LOW);
    }
  else if(val == 'H') //Backward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH); 
    }

  else if(val == 'W') //Spray Servo swing on
    {
  for (int pos = 75; pos <= 150; pos ++) { 
    // in steps of 1 degree
    Sspr.write(pos);              
    delay(10);                       
  }
for (int pos = 150; pos >= 0; pos --) { 
    Sspr.write(pos);              
    delay(10); 
    }
  for (int pos = 0; pos <= 75; pos ++) { 
    // in steps of 1 degree
    Sspr.write(pos);              
    delay(10);                       
  }
    }
  else if(val == 'w') //Spray servo swing off
    {
      Sspr.write(75); 
      delay(10);
    }
  else if(val == 'V') //Spray servo swing off
    {
      digitalWrite(pmp, HIGH);
    }
  else if(val == 'v') //Spray servo swing off
    {
      digitalWrite(pmp, LOW);
    }

  else if(val == 'X') //Moisture down
    {
    Smst.write(0);               
    delay(10);                       
  }
else if(val == 'x') //Moisture up
    {
      Smst.write(30); 
      delay(10);
    }


    else if(val == 'U') //Seeder on
    {
  for (int pos = 0; pos <= 30; pos ++) { 
    // in steps of 1 degree
    Ssdr.write(pos);              
    delay(5);                       
  }
  for (int pos = 30; pos >= 0; pos --) { 
    Ssdr.write(pos);              
    delay(5); 
    }                      
  }
  else if(val == 'u') //Seeder off
    {
      Ssdr.write(0); 
      delay(10);
    }
}