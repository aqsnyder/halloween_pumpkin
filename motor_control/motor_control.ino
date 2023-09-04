#include <Servo.h>

//---------------------------------------------------

Servo servo_set1;
Servo servo_set2;
Servo servo_set3;

int angle = 40;
const int button_pin = 8;
int button_state = 0;
int motor_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);

  servo_set1.attach(2);
  servo_set2.attach(3);
  servo_set3.attach(4);

  servo_set1.write(angle);
  servo_set2.write(angle);
  servo_set3.write(angle);

}

//---------------------------------------------------

void loop() {
  if (digitalRead(button_pin) == HIGH) {
      motor_state = 1;
      while (motor_state == 1) {
        move_eye();
        motor_state = 0;
      }                 
  }
}

//---------------------------------------------------

void move_eye(){
  long rand_angle_set1 = random(0,80);
  long rand_angle_set2 = random(0,80);
  long rand_angle_set3 = random(0,80);

  for(angle = 40; angle < rand_angle_set1; angle++) {                                  
  servo_set1.write(angle);              
  delay(15);
  } 
  for(angle = 40; angle > rand_angle_set1; angle--) {                                  
  servo_set1.write(angle);              
  delay(15);
  }

    for(angle = 40; angle < rand_angle_set2; angle++) {                                  
  servo_set2.write(angle);              
  delay(15);
  } 
  for(angle = 40; angle > rand_angle_set2; angle--) {                                  
  servo_set2.write(angle);              
  delay(15);
  }

    for(angle = 40; angle < rand_angle_set3; angle++) {                                  
  servo_set3.write(angle);              
  delay(15);
  } 
  for(angle = 40; angle > rand_angle_set3; angle--) {                                  
  servo_set3.write(angle);              
  delay(15);
  }

}

//--------------------------------------------------- 
