#include <Adafruit_TiCoServo.h>
#include <Arduino.h>

// Servo pins
#define Servo_PIN_1  2
#define Servo_PIN_2  3
#define Servo_PIN_3  5
#define Servo_PIN_4  6
#define Servo_PIN_5  7
#define Servo_PIN_6  8
#define Servo_PIN_7  11
#define Servo_PIN_8  12
#define Servo_PIN_9  13
#define Servo_PIN_10 44
#define Servo_PIN_11 45
#define Servo_PIN_12 46

// Relay GPIO Pins
#define RELAY_PIN_1 22
#define RELAY_PIN_2 23
#define RELAY_PIN_3 24

// Servo Objects
Adafruit_TiCoServo servo1;   
Adafruit_TiCoServo servo2;
Adafruit_TiCoServo servo3;
Adafruit_TiCoServo servo4;
Adafruit_TiCoServo servo5;
Adafruit_TiCoServo servo6;
Adafruit_TiCoServo servo7;
Adafruit_TiCoServo servo8;
Adafruit_TiCoServo servo9;
Adafruit_TiCoServo servo10;
Adafruit_TiCoServo servo11;
Adafruit_TiCoServo servo12;


uint8_t data;     // for reading incoming byte over serial port 
uint8_t res[5];  // array for storing 5 bytes sent by Blender over Serial port

uint8_t servo_angle;


void setup() 
{
  // Init Serial
  Serial.begin(115200);
  Serial.flush();

  // set Relay GPIOs as output
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);

  // keep the relays disabled
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, LOW);
  digitalWrite(RELAY_PIN_3, LOW);

  // Init Servos
  servo1.attach(Servo_PIN_1);
  servo2.attach(Servo_PIN_2);
  servo3.attach(Servo_PIN_3);
  servo4.attach(Servo_PIN_4);
  servo5.attach(Servo_PIN_5);
  servo6.attach(Servo_PIN_6);
  servo7.attach(Servo_PIN_7);
  servo8.attach(Servo_PIN_8);
  servo9.attach(Servo_PIN_9);
  servo10.attach(Servo_PIN_10);
  servo11.attach(Servo_PIN_11);
  servo12.attach(Servo_PIN_12);

  // Write Initial Servo Positions
  servo1.write(55);
  servo2.write(24);
  servo3.write(120);
  servo4.write(136);
  servo5.write(133);
  servo6.write(148);
  servo7.write(103);
  servo8.write(122);
  servo9.write(113);
  servo10.write(149);
  servo11.write(90);
  servo12.write(90);
 
  // Enable the relays after writting servo positions
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);

  delay(2000); //The delay is here so that  the octoskull can settle down in its initial pose before it starts reading the new servo positions over serial port from blender 
}

void loop() 
{  
  Serial_Receive();
  
  if(res[0]==0x3C && res[4]==0x3E)
  {
    servo_angle= res[3];
    if(res[1]==0x01)
    {
      servo1.write(servo_angle);
    }
    if(res[1]==0x02)
    {
      servo2.write(servo_angle);
    }
    if(res[1]==0x03)
    {
      servo3.write(servo_angle);
    }
    if(res[1]==0x04)
    {
      servo4.write(servo_angle);
    }
    if(res[1]==0x05)
    {
      servo5.write(servo_angle);
    }
    if(res[1]==0x06)
    {
      servo6.write(servo_angle);
    }
    if(res[1]==0x07)
    {
      servo7.write(servo_angle);
    }
    if(res[1]==0x08)
    {
      servo8.write(servo_angle);
    }
    if(res[1]==0x09)
    {
      servo9.write(servo_angle);
    }
    if(res[1]==0x0A)
    {
      servo10.write(servo_angle);
    }
    if(res[1]==0x0B)
    {
      servo11.write(servo_angle);
    }
    if(res[1]==0x0C)
    {
      servo12.write(servo_angle);
    }
  }
  
  else
  {
    //DO NOTHING
  }
}

void Serial_Receive()
{
  uint8_t i=0;  
  while( data!= 0x3E)     
  {
    while(Serial.available())
    {
      data=Serial.read();
      res[i]=data;
      i++;
    }
  }
  data=0;
}
