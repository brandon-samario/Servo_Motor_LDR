/*
  Purpose of this program is to know how to use and understand the funcion of servo motors with an LDR.
  An LDR is a photoresistor that decreases resistance with an increase in incident light intensity on the component's surface.
  Servo motor connects to digital pin 3 of the ardunio.
  The direction of servo motor is being changed using an LDR.
  LDR connects to analog pin A0 of the ardunio.
  LDR ground connects to analog pin A2, 5V pin connects to analog pin A3.
*/

#include<Servo.h>

int lightval;
int lightpin = A0; //LDR will connect to analog pin A0
int servopin = 3; //Sero motor will connect to ardunio digital pin 3
int angle;
float input_voltage = 0.0; //voltage setup

Servo myservo;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(lightpin, INPUT); //pin A0 used as input
  myservo.attach(servopin);
  pinMode(servopin, OUTPUT); //pin 3 used as output
}

void loop() {
  // put your main code here, to run repeatedly:

  lightval = analogRead(lightpin); //read LDR input on pin A0
  Serial.print("Bit Value = "); //print text "Bit Value = "
  Serial.println(lightval); //print the value from A0
  delay(100);

  angle = lightval / 5; //direction
  myservo.write(angle);
  Serial.print("Angle = "); //print text "Angle = "
  Serial.println(angle); //print the value from A0

  input_voltage = (lightval * 5.0) / 1024.0; //Conversion formula for voltage
  Serial.print("Voltage = "); //print text "Voltage = "
  Serial.println(input_voltage); //print the value from A0

}