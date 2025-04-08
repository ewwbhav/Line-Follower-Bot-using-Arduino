#include <Arduino.h>
// new perfect runnable code
#define ENA  14  
#define IN1  26   
#define IN2  27   
#define ENB  25   
#define IN3  33   
#define IN4  32   

#define IR_SENSOR_COUNT 8
#define MAX_SPEED 250
#define BASE_SPEED 250  // Increased for higher speed and smoother turns

int sensorPins[IR_SENSOR_COUNT] = {34, 35, 36, 39, 12, 13, 4, 2};
int sensorValues[IR_SENSOR_COUNT];
int sensorMin[IR_SENSOR_COUNT], sensorMax[IR_SENSOR_COUNT], sensorThreshold[IR_SENSOR_COUNT];

float Kp = 2.0;  // Increased for sharper turns
float Ki = 0.0001;  // Prevents integral windup
float Kd = 0.9;  // Helps reduce oscillations

int lastError = 0, totalError = 0;

void calibrateSensors() {
    Serial.println("Calibrating sensors... Move the robot over the track.");
    unsigned long startTime = millis();
    for (int i = 0; i < IR_SENSOR_COUNT; i++) sensorMin[i] = 4095, sensorMax[i] = 0;
    
    while (millis() - startTime < 5000) { // Faster calibration
        for (int i = 0; i < IR_SENSOR_COUNT; i++) {
            int sensorValue = analogRead(sensorPins[i]);
            sensorMin[i] = min(sensorMin[i], sensorValue);
            sensorMax[i] = max(sensorMax[i], sensorValue);
        }
    }
    for (int i = 0; i < IR_SENSOR_COUNT; i++) {
        sensorThreshold[i] = (sensorMin[i] + sensorMax[i]) / 2;
        Serial.print("Sensor "); Serial.print(i);
        Serial.print(" Threshold: "); Serial.println(sensorThreshold[i]);
    }
    Serial.println("Calibration complete.");
}

int readSensors() {
    int position = 0, weight = 0;
    for (int i = 0; i < IR_SENSOR_COUNT; i++) {
        sensorValues[i] = analogRead(sensorPins[i]) > sensorThreshold[i] ? 1 : 0;
        position += sensorValues[i] * (i * 100);
        weight += sensorValues[i];
    }
    if (weight == 0) return lastError;
    return (position / weight) - ((IR_SENSOR_COUNT - 1) * 50);
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

    analogWrite(ENA, abs(leftSpeed)); 
    digitalWrite(IN1, leftSpeed > 0);
    digitalWrite(IN2, leftSpeed <= 0);

    analogWrite(ENB, abs(rightSpeed)); 
    digitalWrite(IN3, rightSpeed > 0);
    digitalWrite(IN4, rightSpeed <= 0);
}

void setup() {
    Serial.begin(115200);
    pinMode(ENA, OUTPUT); pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT); pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
    
    for (int i = 0; i < IR_SENSOR_COUNT; i++) pinMode(sensorPins[i], INPUT);

    calibrateSensors();
}

void loop() {
    int error = readSensors();
    totalError = constrain(totalError + error, -300, 300);
    int deltaError = error - lastError;
    lastError = error;

    int correction = (Kp * error) + (Ki * totalError) + (Kd * deltaError);
    setMotorSpeed(BASE_SPEED - correction, BASE_SPEED + correction);
}
