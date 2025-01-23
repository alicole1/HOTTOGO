// Add the Servo library. This library is a standart library
#include <stdio.h>
#include <Servo.h>

Servo rightElbow;
Servo leftElbow;
Servo rightArm;
Servo leftArm;

int serPos = 0;
int topPosLeft = 90;
int topPosRight = 90;
int bottomPosLeft = 105;
int bottomPosRight = 95;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connected to serial monitor");
  Serial.println("Start the slay?");
  rightElbow.attach(9);
  leftElbow.attach(11);
  rightArm.attach(3);
  leftArm.attach(6);
  
  StartPos();
  int delayTime1 = 540;
  hOTTOGO(delayTime1);
  int delayTime2 = 540;
  youCanTakeMe(delayTime2);
}

void loop() {
}

void StartPos() {
  leftElbow.write(topPosLeft);
  rightElbow.write(topPosRight);
  leftArm.write(bottomPosLeft - 90);
  rightArm.write(bottomPosRight + 90);
}

void HPosition() {
  leftElbow.write(topPosLeft);
  rightElbow.write(topPosRight);
}

void OPosition() {
  rightElbow.write(topPosRight-40);
  leftElbow.write(topPosLeft+40);
}

void TAPosition() {
  rightElbow.write(topPosRight+90);
  leftElbow.write(topPosLeft-90);
}

void TBPosition() {
  rightElbow.write(topPosRight+65);
  leftElbow.write(topPosLeft-65);
}

void GPosition() {
  rightElbow.write(topPosRight+90);
  leftElbow.write(topPosLeft+25); 
}

void youPosition() {
  leftArm.write(bottomPosLeft);
  leftElbow.write(topPosLeft);
}

void canPosition() {
  rightArm.write(bottomPosRight);
  rightElbow.write(topPosRight);
}

void takePosition() {
  leftArm.write(bottomPosLeft+30);
  leftElbow.write(topPosLeft+25);
}

void mePosition() {
  rightArm.write(bottomPosRight-40);
  rightElbow.write(topPosRight-25);
}

void hotPosition() {
  leftArm.write(bottomPosLeft-90);
  rightArm.write(bottomPosRight+90);
  rightElbow.write(topPosRight-25);
  leftElbow.write(topPosLeft+25);

}

void togoPosition() {
  leftElbow.write(topPosLeft-25);
  rightElbow.write(topPosRight+25);
  delay(300);
  leftElbow.write(topPosLeft-40);
  rightElbow.write(topPosRight+40);
}

void hOTTOGO(double delayTime) {
  HPosition();
  delay(delayTime);

  OPosition();
  delay(delayTime);

  TAPosition();
  delay(delayTime);
  TBPosition();
  delay(delayTime/4);
  TAPosition();
  delay(delayTime);

  OPosition();
  delay(delayTime);

  GPosition();
  delay(delayTime);

  OPosition();
  delay(delayTime);

}

void youCanTakeMe(double delayTime) {
  youPosition();
  delay(delayTime);
  canPosition();
  delay(delayTime);
  takePosition();
  delay(delayTime);
  mePosition();
  delay(delayTime);
  hotPosition();
  delay(delayTime+250);
  togoPosition();
}
