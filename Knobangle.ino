// Controlling a servo motor angle using an LDR (variable resistor) 

#include <Servo.h>                      //including the library for controlling servo motor in the code
 
Servo myservo;                         // create servo object to control a servo motor 
 
int potpin;                          // analog pin used to connect the LDR
int angle;                          // variable to read the value from the analog pin 
 
void setup() 
{ 
  myservo.attach(30);                 // attaches the servo motor on pin 29 to the servo object 
  Serial.begin(9600);                 //initializing the serial monitor
} 
 
void loop() 
{ 
  potpin = analogRead(A6);                  // reads the value of the LDR resistances (value between 0 and 1500) 
  angle = map(potpin, 0, 4000, 0, 180);     // scale it to use it with the servo motor to give angle (value between 0 degree and 180 degrees) 
  myservo.write(angle);                     // sets the servo motor angle according to the scaled value 
  
  Serial.print("ldr");                       
  Serial.println(potpin);                   //printing the values of resistance of LDR on Serial monitor
  Serial.print("angle");
  Serial.println(angle);                    //printing instanteneous values of angles given to the servo motor
  
  delay(500);                           // waits for the servo motor to settle at the given angle 
} 
