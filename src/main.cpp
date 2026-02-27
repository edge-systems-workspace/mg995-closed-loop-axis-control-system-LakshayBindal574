#include<Arduino.h>
#include <Servo.h>

Servo MYSERVO;

int trigPin = 9;
int echoPin = 10;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    MYSERVO.attach(5);
    Serial.begin(9600);
}

void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = (duration * 0.0343) / 2;

    if (distance <= 5) {
        MYSERVO.write(180);   // rotate servo
    } else {
        MYSERVO.write(0);     // reset servo
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}
/**
 * @file Ultrasonic_Servo_Control.ino
 * @author Lakshay Bindal
 * @date 2026-02-27
 * @version 1.0
 *
 * @brief Controls a servo motor based on distance measured
 *        by an ultrasonic sensor.
 *
 * @details
 * This program uses an ultrasonic sensor (HC-SR04) to measure
 * the distance of an object. If the object is within 5 cm,
 * the servo motor rotates to 180 degrees. Otherwise, it
 * remains at 0 degrees.
 *
 * Connections:
 * - Trig  → Digital Pin 9
 * - Echo  → Digital Pin 10
 * - Servo Signal → Digital Pin 5
 *
 * @note
 * Ensure the servo motor has sufficient power supply.
 * External power source is recommended for stable operation.
 *
 * @warning
 * Do not power high torque servos directly from Arduino 5V pin.
 */

#include <Arduino.h>
#include <Servo.h>

/** @brief Servo object declaration */
Servo MYSERVO;

/** @brief Ultrasonic sensor trigger pin */
#define TRIG_PIN 9

/** @brief Ultrasonic sensor echo pin */
#define ECHO_PIN 10

/** @brief Distance threshold in centimeters */
#define DISTANCE_THRESHOLD 5


/**
 * @brief Initializes pins and serial communication.
 */
void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    MYSERVO.attach(5);   // Attach servo to pin 5
    Serial.begin(9600);
}


/**
 * @brief Measures distance using ultrasonic sensor.
 *
 * @return Distance in centimeters
 */
long measureDistance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);

    // Speed of sound = 0.0343 cm/µs
    long distance = (duration * 0.0343) / 2;

    return distance;
}


/**
 * @brief Main loop function.
 *
 * @details
 * Continuously measures distance and rotates servo
 * based on threshold value.
 */
void loop()
{
    long distance = measureDistance();

    if (distance <= DISTANCE_THRESHOLD)
    {
        MYSERVO.write(180);   // Rotate servo
    }
    else
    {
        MYSERVO.write(0);     // Reset servo
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}