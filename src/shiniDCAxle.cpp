


#include <shiniDCAxle.h>

      void shiniDCAxle::begin(shiniDCPins _left,shiniDCPins _right, uint32_t _freq, uint8_t _res){
            
            left.begin(_left.zero ,_left.one ,_left.duty, _freq, _res);
            right.begin(_right.zero ,_right.one ,_right.duty, _freq, _res);        
      }  //left right

      void shiniDCAxle::stop(){
             left.stop();
             right.stop();
             state = 0;
      } //  X X - 0
      void shiniDCAxle::forward(){
             left.forward();
             right.forward();
             state = 1;

      } // F F - 1
      void shiniDCAxle::reverse(){
             left.reverse();   
             right.reverse();
            state = 2;   
      } // R - R -2

      void shiniDCAxle::spinLeft(){
    left.forward();
    right.reverse();
    state = 3;
      } 

      void shiniDCAxle::spinRight(){
      left.reverse();
      right.forward();
      state = 4;
      }

      void shiniDCAxle::concernLeft(){
      left.forward();
      right.stop();
      state = 5;
      }

      void shiniDCAxle::concernRight(){
      left.stop();
      right.forward();
      state = 6;
      }

      void shiniDCAxle::concernReverseLeft(){
      left.reverse();
      right.stop();
      state = 7;
      }

      void shiniDCAxle::concernReverseRight(){
      left.stop();
      right.reverse();
    state = 8;
      } 


 
      
      uint8_t shiniDCAxle::getState(){
            return state;
      }
      uint16_t shiniDCAxle::getDuty(){
      return duty; 
      }

      void shiniDCAxle::setDuty(uint16_t _duty){
    left.setDuty(_duty);
    right.setDuty(_duty);
    duty = _duty;
      }