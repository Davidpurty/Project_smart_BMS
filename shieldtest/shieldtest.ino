#include<AFMotor.h>
//***5 Channel IR Sensor Connection***//
AF_DCMotor motor1(1); // Left Side First Motor
AF_DCMotor motor2(2); // Left Side Second Motor
AF_DCMotor motor3(3); // Right Side First Motor
AF_DCMotor motor4(4); // RIght Side Second Motor

int var = 200; //when going front
//is it workning

void setup() {
  // put your setup code here, to run once:
motor1.setSpeed(var);
motor2.setSpeed(var);
motor3.setSpeed(var);
motor4.setSpeed(var);
}

void loop() {
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
delay(5000);
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
delay(50);
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
delay(5000);

motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
delay(50);

}

//this is just a start of programming
