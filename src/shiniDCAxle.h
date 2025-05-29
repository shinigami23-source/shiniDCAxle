 
#ifndef shiniDCAxle_h
#define shiniDCAxle_h

  
  /*
    * @class shiniDCAxle Class to control  2 shiniDCMotors in an axle manner, with tread steering
      meant to be used sigle or chain for 4wheel drive or xWheel drive
    @usage shiniDCMotor x; x.begin(pin0,pin1,dutyPin)
        Basics
    --@method stop -- stop motor
    --@method forward -- 
    --@method reverse -- 
    Tread streering
    --@method spinRight();  // left forwrd (CW) -- right reverse (reverse)
    --@method  spinLeft();  // sam pattern
    --@method concernLeft(); // left stopped -- right forward
    --@method concernRight();  // same pattern
    --@method concernReverseLeft();
    --@method concernReverseRight();     
    --@method setDuty(duty);  //sets duty
    --@method getDuty : returns current duty
  */
#include <Arduino.h>
#include <shiniDCMotor.h>

    struct shiniDCPins{
      uint8_t zero,one,duty;
    };

class shiniDCAxle {
    protected:
      uint16_t duty;
      shiniDCMotor left, right;
      uint8_t state;
    public:
      void begin(shiniDCPins,shiniDCPins,uint32_t,uint8_t);  //left right
      void stop(); //  X X - 0
      void forward(); // F F - 1
      void reverse(); // R - R -2
      void spinRight();
      void spinLeft();   
      void concernLeft();
      void concernRight();
      void concernReverseLeft();
      void concernReverseRight(); 
      uint8_t getState();                                                                                                                                                                                                     
      uint16_t getDuty();
      void setDuty(uint16_t _duty);
    };

    #endif