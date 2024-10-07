#include <Adafruit_TiCoServo.h>
#include <FastLED.h>
#include "octoskull.h"

// WS2812 RGB LED 
#define NUM_LEDS  74  // 24 LEDs(Ring 1) + 24 LEDs(Ring 2) + 24 LEDs(Ring 3) + 2 LEDs(Eyes)
#define LED_PIN   14

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

const float frameDurationMillis = 1000 / FPS;    //Single frame duration in milliseconds
const float animationDurationMillis = FRAMES * frameDurationMillis;   // Total animation duration in milliseconds

// Color palette for WS2812 RGB LEDs
DEFINE_GRADIENT_PALETTE( bhw3_51_gp ) 
{
    0,   1,  1,  1,
   35,   1,  1, 21,
   61,   5, 13,123,
   86,  27, 35,184,
  127, 252,250,237,
  160, 229, 43,233,
  204,  68,  6,212,
  255,  19,  8, 93
};

CRGBPalette16 palette = bhw3_51_gp; // initialize palette

CRGB leds[NUM_LEDS]; 
uint8_t colorIndex[NUM_LEDS]; 

long startMillis; // to store number of milliseconds passed since the Arduino board began running the program

void setup() 
{
  startMillis = millis();

  // Init FastLED
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);

  //Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    colorIndex[i] = random8();
  }

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
  servo1.write(63);
  servo2.write(40);
  servo3.write(113);
  servo4.write(130);
  servo5.write(138);
  servo6.write(150);
  servo7.write(113);
  servo8.write(130);
  servo9.write(116);
  servo10.write(150);
  servo11.write(90);
  servo12.write(90);

  // Enable the relays after writting servo positions
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);

  delay(2000); //The delay is here so that the octoskull can settle down in its initial pose before it starts reading new servo positions from the memory
}

void loop() 
{
  long currentMillis = millis();
  long positionMillis = currentMillis - startMillis;

  if (positionMillis >= animationDurationMillis) 
  {
    startMillis = currentMillis;
  } 

  else 
  {
    long frame = floor(positionMillis / frameDurationMillis);
    int positionValue1 = (int)(pgm_read_float_near(Bone001 + frame));
    servo1.write(positionValue1);
    
    int positionValue2 = (int)(pgm_read_float_near(Bone002 + frame));
    servo2.write(positionValue2);

    int positionValue3 = (int)(pgm_read_float_near(Bone003 + frame));
    servo3.write(positionValue3);

    int positionValue4 = (int)(pgm_read_float_near(Bone004 + frame));
    servo4.write(positionValue4);

    int positionValue5 = (int)(pgm_read_float_near(Bone005 + frame));
    servo5.write(positionValue5);

    int positionValue6 = (int)(pgm_read_float_near(Bone006 + frame));
    servo6.write(positionValue6);

    int positionValue7 = (int)(pgm_read_float_near(Bone007 + frame));
    servo7.write(positionValue7);

    int positionValue8 = (int)(pgm_read_float_near(Bone008 + frame));
    servo8.write(positionValue8);

    int positionValue9 = (int)(pgm_read_float_near(Bone009 + frame));
    servo9.write(positionValue9);

    int positionValue10 = (int)(pgm_read_float_near(Bone010 + frame));
    servo10.write(positionValue10);

    int positionValue11 = (int)(pgm_read_float_near(Bone011 + frame));
    servo11.write(positionValue11);

    int positionValue12 = (int)(pgm_read_float_near(Bone012 + frame));
    servo12.write(positionValue12);

     // Color each LED from the palette using the index from colorIndex[]
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      leds[i] = ColorFromPalette(palette, colorIndex[i]);
    }
  
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      colorIndex[i]++;
    }
    FastLED.show();
  }
}
