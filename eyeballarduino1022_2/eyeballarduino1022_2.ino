/*
  Serial RGB controller
 
 Reads a serial input string looking for three comma-separated
 integers with a newline at the end. Values should be between 
 0 and 255. The sketch uses those values to set the color 
 of an RGB LED attached to pins 9 - 11.
 
 The circuit:
 * Common-anode RGB LED cathodes attached to pins 9 - 11
 * LED anode connected to pin 13
 
 To turn on any given channel, set the pin LOW.  
 To turn off, set the pin HIGH. The higher the analogWrite level,
 the lower the brightness.
 
 created 29 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain. 
 */
int sensorValue = 0;
int prevSensorValue = 0;
int sensorValue2 = 0;
int prevSensorValue2 = 0;
const int bufSiz = 10;
static int micBuf[bufSiz];
int midLevel = 512;

String inString = "";    // string to hold input
int X, Y = 0;
int currentColor =  0;
int value1 = 0;
int value2 = 0;

#include <Servo.h> 
 Servo myservo;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
   myservo.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(11);  // attaches the servo on pin 9 to the servo object 

  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // send an intro:
  Serial.println("\n\nHi there:");
  Serial.println();
  // set LED cathode pins as outputs:
  //pinMode(9, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode(11, OUTPUT);
  // turn on pin 13 to power the LEDs:
  //pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);
}

void loop() {
  int inChar;

  // Read serial input:
  if (Serial.available() > 0) {
    inChar = Serial.read();
    Serial.print((char)inChar);
     
  }

  if (isDigit(inChar)) {
    // convert the incoming byte to a char 
    // and add it to the string:
    inString += (char)inChar; 
  }

  // if you get a comma, convert to a number,
  // set the appropriate color, and increment
  // the color counter:
  if (inChar == ',') {
    // do something different for each value of currentColor:
    switch (currentColor) {
    case 0:    // 0 = red
      X = inString.toInt();
      // clear the string for new input:
      inString = ""; 
      break;
    }
    currentColor++;
  }
  // if you get a newline, you know you've got
  // the last color, i.e. blue:
  if (inChar == '\n') {
    Y = inString.toInt();

    // set the levels of the LED.
    // subtract value from 255 because a higher
    // analogWrite level means a dimmer LED, since
    // you're raising the level on the anode:
    
     sensorValue = analogRead(X);
  sensorValue = abs(sensorValue - midLevel);
  sensorValue = prevSensorValue + (sensorValue - prevSensorValue) * 0.01;
  
  prevSensorValue = sensorValue;
  
  // print out the value you read:
  Serial.println(sensorValue);
  
    sensorValue2 = analogRead(Y);
  sensorValue2 = abs(sensorValue2 - midLevel);
  sensorValue2 = prevSensorValue2 + (sensorValue2 - prevSensorValue2) * 0.01;
  
  prevSensorValue2 = sensorValue2;
  
  // print out the value you read:
  Serial.println(sensorValue2);
    value1 = map(sensorValue,0,1023,0,10);
  value2 = map(sensorValue2,0,1023,0,10);
     myservo.write(value1);                  // sets the servo position according to the scaled value 
  myservo2.write(value2);  
    //analogWrite(11,  255 - red);
    //analogWrite(9, 255 - green);
    //analogWrite(10, 255 - blue);

    // print the colors:
    Serial.print("X: ");
    Serial.print(X);
    Serial.print("Y: ");
    Serial.print(Y);

    // clear the string for new input:
    inString = ""; 
    // reset the color counter:
    currentColor = 0;
      delay(100);               // wait for a while

  }

}

