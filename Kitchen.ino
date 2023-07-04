#include <LEDStripDriver.h>

// pins Sensors
#define SENSOR 3

// Pins LedDriver
#define LEDDRIVER_DIN 11
#define LEDDRIVER_CIN 12

// Steps
#define TIME_LOW 5
#define STEP_HI 0.8
#define STEP_LOW 0.2
#define LOW_LIGHT 40
#define LOW_DELAY 60

// Variables
int PirVal = 0;
int Val = 0;
int State = 0;
float LedCur = 0;
float DelayCur = 0;

LEDStripDriver led = LEDStripDriver(LEDDRIVER_DIN, LEDDRIVER_CIN);

void Show(){
  if (State == 1){ 
    if (LedCur < 255) {LedCur = LedCur + STEP_HI;}
  } else {
    if (LedCur > 0) { LedCur = LedCur - STEP_LOW;
      if ((LedCur < LOW_LIGHT) and (DelayCur <  LOW_DELAY)) {DelayCur = DelayCur + 0.01; LedCur = LedCur + STEP_LOW;Serial.println(DelayCur);}
    }
  }
  led.setColor(LedCur,LedCur,LedCur) ;
}

void setup(){
  pinMode(SENSOR, INPUT);
}

void loop(){
  Val = digitalRead(SENSOR);
  if (Val != PirVal) PirVal = Val;
  if (Val == 1) State = 1
  else if (State !=0) {State = 0; DelayCur = 0;}   
  Show();
}


  
