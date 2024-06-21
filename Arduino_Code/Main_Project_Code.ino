/*
 * Build flex glove first, then run Flex_Glove_Calibration.ino. 
 * Copy output into line 22,23
 *
 * Wiring Convention:  
 * Finger  | Lilypad Pin        
 * Thumb   | D5     
 * Index   | D6        
 * Middle  | D7        
 * Ring    | D8        
 * Pinky   | D9 
 * elpow   | D10
 */

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Servo.h>

Servo thumb, index, middle, ring, pinky, elpow, wrist;

MPU6050 mpu;  // for gyroscope

int16_t ax, ay, az;
int16_t gx, gy, gz;

int angles[6];  // array for storing servo angles
int val;
const int flexPins[] = {A0, A1, A2, A3, A6, A7};  // order of finger connections from thumb to pinky

// Calibrated flex sensor ranges for each finger (from Flex_Glove_Calibration.ino output)
const int flexsensorRange[2][6] = {
  {440, 358, 605, 230, 0, 15},  // Minimum calibrated values
  {726, 465, 814, 360, 13, 24}  // Maximum calibrated values
};

void setup() {
  Serial.begin(9600);   
  Serial.println("Initialize MPU");
  mpu.initialize();

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  // Attach servos to pins
  wrist.attach(4);                     
  thumb.attach(5); 
  index.attach(6); 
  middle.attach(7);
  ring.attach(8);  
  pinky.attach(9);
  elpow.attach(10);
}

void loop() {
  for (int i = 0; i < 6; i++) {  // Repeat process for each of the 5 fingers and elpow
    val = analogRead(flexPins[i]);  // Read the position of the finger

    // Map flex sensor value to servo angle
    if (i % 2 == 0) {
      angles[i] = map(val, flexsensorRange[0][i], flexsensorRange[1][i], 0, 180);  // Standard mapping
    } else {
      angles[i] = map(val, flexsensorRange[0][i], flexsensorRange[1][i], 180, 0);  // Reverse mapping for some fingers
    }

    angles[i] = constrain(angles[i], 0, 180);  // Constrain angles to valid range

    Serial.print("Finger ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(angles[i]);
    Serial.print('\t');    

    // Move servos to set angle
    switch (i) {
      case 0: thumb.write(angles[i]); break;
      case 1: index.write(angles[i]); break;
      case 2: middle.write(angles[i]); break;
      case 3: ring.write(angles[i]); break;
      case 4: pinky.write(angles[i]); break;
      case 5: elpow.write(angles[i]); break;
    }
  }

  // Read gyroscope data
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  ax = map(ax, -17000, 17000, -1500, 1500);
  int GY = map(ax, -1500, 1500, 0, 180);
  wrist.write(GY);

  Serial.print("Wrist: ");
  Serial.println(GY);
  Serial.println();
  delay(100);
}