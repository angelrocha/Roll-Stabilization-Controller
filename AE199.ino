#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_10DOF.h>

Servo myservo;  // create servo object to control a servo
int pos = 0; // variable to store the servo position
boolean alpha = false;
boolean lastAlpha = false;
boolean servoAtZero = false;
float beta;
float dt;
float theta;
float phi;
float yaw;
//boolean more efficient than int: saves working memory
//int = 8 bits, boolean = 1bit

unsigned long time;
Adafruit_10DOF                dof   = Adafruit_10DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);
Adafruit_L3GD20_Unified       gyro  = Adafruit_L3GD20_Unified(20);
/* Update this with the correct SLP for accurate altitude measurements */
float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); //initialize serial port
  pinMode(2,INPUT); //buton AKA pot
  initSensors();
  alpha = (digitalRead(2)==1);
  lastAlpha = alpha;
}

void loop() {
  time=millis()/1000;
  imu();
  alpha = (digitalRead(2)==1);
  if(alpha!=lastAlpha) {
    if(servoAtZero) turnCW();
    else turnCCW();    
    lastAlpha = alpha;
  }
  
}


