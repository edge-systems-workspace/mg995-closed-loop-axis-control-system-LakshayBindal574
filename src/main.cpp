#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
    myServo.attach(5);
}

void loop() {
    myServo.write(0);
}