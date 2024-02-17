#ifndef SICA
#define SICA

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Arduino_H7_Video.h>
#include <Arduino_GigaDisplayTouch.h>
#include <lvgl.h>
#include <RPC.h>
#include <Adafruit_MAX31865.h>
#include <lv_conf.h>
Arduino_H7_Video  Display(800,480, GigaDisplayShield);
Arduino_GigaDisplayTouch  TouchDetector;

/*-------------------------------SICA---------------------------------------*/
 
#define PT100_RNOMINAL 100.0 
#define REF_RESISTOR   430.0  
Adafruit_MAX31865 max31865 = Adafruit_MAX31865(10, 11, 12, 13);   //current sensor pin config
float temperature=0;
float display_temp=0;

const int RelayPIN=7;
 
const int currentSensorPin = A0; //define sensor pin dfrobot
const int mVperAmp = 100; // use 185 for 5A Module, and 66 for 30A Module 100 for 20Ap
float Vref  = 0; //read your Vcc voltage,typical voltage should be 5000mV(5.0V)
int START_flag=0;
float CurrentValue=0;
float display_current=0;
short update_display_flag=0;

int dd_flag=3;
unsigned long flush_delay=millis()+2000;
float arr_current[50];
int avg_iter;
float sum=0;
int sample=0;
int processingFLAG=0;

void read_data(void);

//function definition
void lv_example_dropdown_1(void);
void lv_example_style_1(void);
void lv_example_style_2(void);
void lv_example_style_3(void);
void lv_example_style_4(void);
void lv_example_btn_2(void); 
void lv_example_arc_2(void);
void update_temp(void);
void update_current(void);
void LOGODisplay(void);


using namespace rtos;

Thread task1;

#endif
