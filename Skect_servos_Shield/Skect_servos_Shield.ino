#include <Servo.h>


/* 
  The code is structure by:
  1. Initialization or set the pins of the potentiometers (PotPin$)
  2. Read the values of the potentiometers in each variable (potValue$)
  3. Map the values to the range of the servo motors (angulo_servo$)
*/

int PotPin = A0; 
int PotValue; 
int angulo;

int PotPin2 = A1;
int potValue2;
int angulo_Servo1;
int angulo_Servo2;

int Potpin3 = A2;
int PotValue3;
int angulo_Servo3;

int Potpin4 = A3;
int PotValue4;
int angulo_Servo4;

int Potpin5 = A4;
int PotValue5;
int angulo_Servo5;


// Set the variables of each part of the robot arm
Servo SERVO_BASE;

Servo SERVO1_TRONCO_SUPERIOR;
Servo SERVO2_TRONCO_SUPERIOR;

Servo SERVO3_CODO;

Servo SERVO4_ANTEBRAZO;

Servo SERVO_GANCHO;



void setup() {

  // Asign each potentiometer as INPUT 
  pinMode(PotPin, INPUT);
  pinMode(PotPin2, INPUT);
  pinMode(Potpin3, INPUT);
  pinMode(Potpin4, INPUT);
  pinMode(Potpin5, INPUT);


  // Each section of the arm is related with a specific PIN 
  // Of the module Sensor Shield V.5 Arduino
  SERVO_BASE.attach(2);  
  SERVO1_TRONCO_SUPERIOR.attach(3);
  SERVO2_TRONCO_SUPERIOR.attach(4);

  SERVO3_CODO.attach(5);

  SERVO4_ANTEBRAZO.attach(6);

  SERVO_GANCHO.attach(7);
 
  Serial.begin(9600);
}

void loop() {

  // SERVO_BASE the first servo of the robot arm
  PotValue = analogRead(PotPin);
  angulo = map(PotValue, 0, 1023, 0, 180);
  SERVO_BASE.write(angulo);
  
  Serial.print("The Angle value for SERVO_BASE: ");
  Serial.println(angulo);

  delay(15); 


  // SERVO1_TRONCO_SUPERIOR and SERVO2_TRONCO_SUPERIOR 
  // the medium servos who manages the firsts movements of the arm
  potValue2 = analogRead(PotPin2);
  angulo_Servo1 = map(potValue2, 0, 1023, 0, 135);
  angulo_Servo2 = map(potValue2, 0, 1023, 180, 45);


  SERVO1_TRONCO_SUPERIOR.write(angulo_Servo1);
  SERVO2_TRONCO_SUPERIOR.write(angulo_Servo2);

  Serial.print("The angle value for SERVO1_TRONCO_SUPERIOR: ");
  Serial.println(angulo_Servo1);

  Serial.print("The angle value for SERVO2_TRONCO_SUPERIOR: ");
  Serial.println(angulo_Servo2);

  delay(15); 


  // SERVO3_CODO the fourth servo of the robot arm
  PotValue3 = analogRead(Potpin3);
  angulo_Servo3 = map(PotValue3, 0, 1023, 120, 30);
  SERVO3_CODO.write(angulo_Servo3);

  Serial.print("The Angle value for SERVO3_CODO: ");
  Serial.println(angulo_Servo3);


  // SERVO4_ANTEBRAZO the fifth servo of the robot arm
  PotValue4 = analogRead(Potpin4);
  angulo_Servo4 = map(PotValue4, 0, 1023, 90, 180);
  SERVO4_ANTEBRAZO.write(angulo_Servo4);

  Serial.print("The Angle value for SERVO4_ANTEBRAZO: ");
  Serial.println(angulo_Servo4);

  delay(15); 

  // SERVO_GANCHO the sixth servo of the robot arm
  PotValue5 = analogRead(Potpin5);
  angulo_Servo5 = map(PotValue5, 0, 1023, 0, 40);
  SERVO_GANCHO.write(angulo_Servo5);

  Serial.print("The Angle value for SERVO_GANCHO: ");
  Serial.println(angulo_Servo5);

  Serial.print("\n");  
}