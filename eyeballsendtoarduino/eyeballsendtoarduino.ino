/*
  multivalue Send 
 
  This example code is in the public domain.
 */
 int X;
 int Y;
 
#include <Servo.h> 
 Servo myservo;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 

int value1 = X;
int value2 = Y;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.

  Serial.begin(9600);
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(11);  // attaches the servo on pin 9 to the servo object 

}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  
  value1 = analogRead(A0);
  value2 = analogRead(A1);
  
  value1 = map(value1,0,1023,0,180);
  value2 = map(value2,0,1023,0,180);
     myservo.write(value1);                  // sets the servo position according to the scaled value 
  myservo2.write(value2);                  // sets the servo position according to the scaled value 

  // print out comma separated values.
  Serial.print(value1); // send value1
  Serial.print(',');    // insert comma between values
  Serial.print(value2); // send value2
  Serial.print('\n');   // end with line feed

  delay(100);               // wait for a while

}
