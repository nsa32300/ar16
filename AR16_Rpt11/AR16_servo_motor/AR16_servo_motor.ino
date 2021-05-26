/*
 예제 7.2
 서보모터 구동
*/
 
// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1;
const int inputPinL = 2;
const int inputPinR = 3; 

// 서보 모터 신호핀 설정
int servoMotorPin = 9;

boolean left = false;
boolean right = false;

void setup() {
  
  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin,600,2400);
  pinMode(inputPinL, INPUT_PULLUP);
  pinMode(inputPinR, INPUT_PULLUP);
  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop(){
  int left2 = digitalRead(inputPinL);
  int right2 = digitalRead(inputPinR);

 if(right2==LOW) {
  right = true;
  left = false;
 }
 else if(left2==LOW){
  right = false;
  left = true;
 }

 if(right == true) {
  motor1.write(0);
 } else if(left == true) {
  motor1.write(270);
 }
  delay(20);
}
