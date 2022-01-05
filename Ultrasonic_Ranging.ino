/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Ultrasonic_Ranging.c
* @author       Cindy
* @version      V1.0
* @date         2018.10.18
* @brief        Ultrasonic_Ranging
* @details
* @par History   
*
*/
#include "RGBLed.h"
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
const int SingPin = 12;

float distance;

#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                       //Define the pins of the RGB light
#define MAX_LED 1                   //Just one RGB light on the car

#define RGB_GREEN    0xFF0000    //Define different color(green,red,blue)
#define RGB_RED   0x00FF00
#define RGB_BLUE    0x0000FF
#define RGB_YELLOW  0xFFFF00
#define RGB_PURPLE  0x00FFFF
#define RGB_WHITE   0xFFFFFF
#define RGB_OFF  0x000000

const int RgbPin = 11;    //Define pin of Ultrasonic RGB light
RGBLed mRgb(RgbPin,2);

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
uint8_t i = 0;                            
uint32_t redbright = strip.Color(0,255,0);   //green,red,blue
uint32_t bluebright = strip.Color(0,0,255);   //green,red,blue
uint32_t greenbright = strip.Color(255,0,0);   //green,red,blue
uint32_t red = strip.Color(0,1,0);   //green,red,blue
uint32_t blue = strip.Color(0,0,1);   //green,red,blue
uint32_t green = strip.Color(1,0,0);   //green,red,blue
uint32_t greenblue = strip.Color(1,0,1);   //green,red,blue
uint32_t skyblue = strip.Color(10,0,10);   //green,red,blue
uint32_t teal = strip.Color(10,0,5);   //green,red,blue
uint32_t black = strip.Color(0,0,0);   //green,red,blue
uint32_t purple = strip.Color(0,1,1);   //green,red,blue
uint32_t bluepurple = strip.Color(0,1,3);   //green,red,blue
uint32_t magenta = strip.Color(0,20,5);   //green,red,blue
uint32_t toohotpink = strip.Color(0,10,1);   //green,red,blue
uint32_t pink = strip.Color(0,5,1);   //green,red,blue
uint32_t orange = strip.Color(1,10,0);   //green,red,blue
uint32_t brightwhite = strip.Color(255,255,255);   //green,red,blue
uint32_t white = strip.Color(100,100,100);   //green,red,blue
uint32_t dullwhite = strip.Color(10,10,10);   //green,red,blue
uint32_t sortofwhite = strip.Color(1,1,1);   //green,red,blue

/**
* Function       setup
* @author        liusen
* @date          2017.07.25
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
   
   mRgb.setColor(1,RGB_OFF);
    mRgb.setColor(2,RGB_OFF);
    mRgb.show();
   strip.begin();
   pwm.begin();
   pwm.setPWMFreq(60);                 //Analog servos run at ~60 Hz updates
   Serial.begin(9600);
   Serial.println("Ultrasonic sensor:");
}

/**
* Function       LOGO_light(brightness,time,increament)
* @author        wusicaijuan
* @date          2019.06.26
* @brief         LOGO_light
* @param[in1]    brightness
* @param[in2]    time
* @param[in3]    increament
* @param[out]    void
* @retval        void
* @par History   no
*/


/**
* Function       loop
* @author        Cindy
* @date          2019.07.30
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  strip.setPixelColor(i, green);  //Make Onboard RGB light
  strip.show();
  delay(500); 
  mRgb.setColor(1,RGB_GREEN);  //There are two RGB light on the Ultrasonic module No.1 and No.2. if you input 0, all light will be lit
  mRgb.setColor(2,RGB_GREEN);  
  mRgb.show();
  delay(500);
  pinMode(SingPin,OUTPUT); 
  digitalWrite(SingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(SingPin, LOW);
  
  pinMode(SingPin, INPUT);
  delayMicroseconds(50);
  distance = pulseIn(SingPin, HIGH) / 58.00;
  Serial.print("distance is :");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(1000);
}
