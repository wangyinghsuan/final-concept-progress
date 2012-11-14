/*
  multivalue Send 
 
  This example code is in the public domain.
 */
 int X = 0;
 int Y = 0;
 
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
  if(Serial.available() > 0){
    X = Serial.parseInt(); //convert String value from Processing to Integer value. 
  }

  value1 = map(X,0,1023,0,180);
  value2 = map(Y,0,1023,0,180);
     myservo.write(value1);                  // sets the servo position according to the scaled value 
  myservo2.write(value2);                  // sets the servo position according to the scaled value 

  // print out comma separated values.
  Serial.print(value1); // send value1
  Serial.print(',');    // insert comma between values
  Serial.print(value2); // send value2
  Serial.print('\n');   // end with line feed

  delay(100);               // wait for a while

}
