// Calibration_first
// After connecting the Arduino board, select its port and upload the code
// Open the serial monitor and lay your hand flat to collect the minimum readings
// Close your hand to collect the maximum readings
// Copy your readings

const int fingerPins[6] = {A0, A1, A2, A3, A4, A5};  // Order of finger connections from thumb to elpow
int fingerVals[6];  // Stores value of flex sensor on each finger
const char *names[6] = {"Thumb: ", "Index: ", "Middle: ", "Ring: ", "Pinky: ", "elpow: "};
int calibrationVals[2][6];  // Stores minimum and maximum calibration values

const int numReadings = 10;  // Number of readings to average
const int readingDelay = 200;  // Delay between readings in milliseconds

void setup() {
  Serial.begin(9600);
  calibrateFlexSensors();
}

void loop() {
  // Nothing needed in the loop
}

void calibrateFlexSensors() {
  for (int calibrationCount = 0; calibrationCount <= 1; calibrationCount++) {
    // If calibrationCount == 0, find minimum flex value (hand relaxed position)
    // If calibrationCount == 1, find maximum flex value (hand in fist position)
    if (calibrationCount == 0) {
      Serial.println("Please lay your hand flat");
      delay(3000);
      Serial.println("Collecting minimum flex readings");
    } else {
      Serial.println("Please close your hand into a fist");
      delay(3000);
      Serial.println("Collecting maximum flex readings");
    }

    for (int i = 0; i < 6; i++) {
      int readingSum = 0;

      for (int readingCount = 0; readingCount < numReadings; readingCount++) {
        readingSum += analogRead(fingerPins[i]);
        delay(readingDelay);
      }

      calibrationVals[calibrationCount][i] = readingSum / numReadings;  // Record average of 10 readings
    }
  }

  Serial.println("Calibration Complete");
  Serial.println("In the order from thumb to pinky, your offsets are:");
  
  Serial.print("Minimum Offsets:\t");
  for (int j = 0; j < 6; j++) {
    Serial.print(calibrationVals[0][j]);
    Serial.print(", ");
  }
  Serial.println();

  Serial.print("Maximum Offsets:\t");
  for (int j = 0; j < 6; j++) {
    Serial.print(calibrationVals[1][j]);
    Serial.print(", ");
  }
  Serial.println();
}