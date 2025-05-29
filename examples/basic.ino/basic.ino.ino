#include <shiniDCAxle.h>

shiniDCAxle testAxle;


#define LEFT_P0 25    //brown
#define LEFT_P1 26    //white
#define LEFT_DUTY 33  //blue

#define RIGHT_P0 19
#define RIGHT_P1 18
#define RIGHT_DUTY 21


void setup() {
  // put your setup code here, to run once:
  shiniDCPins leftPins{ LEFT_P0, LEFT_P1, LEFT_DUTY }, rightPins{ RIGHT_P0, RIGHT_P1, RIGHT_DUTY };
  Serial.begin(115200);
  testAxle.begin(leftPins, rightPins, 10000, 8);
  testAxle.setDuty(150);  //change if needed 0-254
}

void loop() {
  // put your main code here, to run repeatedly:
  testAxle.stop();  //  X X - 0
  delay(1000);
  Serial.print("mode: ");
  Serial.println(testAxle.getState());

  testAxle.forward();  // F F - 1
  delay(1000);
  Serial.print("mode: ");
  Serial.println(testAxle.getState());

  testAxle.reverse();  // R - R -2
  delay(1000);
  Serial.print("mode: ");
  Serial.println(testAxle.getState());


  testAxle.spinRight();
  delay(1000);
  Serial.print("mode: ");
  Serial.println(testAxle.getState());

  testAxle.spinLeft();
  delay(1000);
  Serial.print("mode: ");
  Serial.println(testAxle.getState());

}
