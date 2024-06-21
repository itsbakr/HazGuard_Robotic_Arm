# HazGuard-Robotic-Arm

## Introduction

The **HazGuard Robotic Arm** project is a controlled robotic arm designed to facilitate tasks in nuclear power plant facilities, minimizing workers' exposure to hazards and radiation. The arm is controlled via a glove equipped with flexible sensors and NRF circuits, translating hand movements into precise robotic arm actions.

## Features

- **Control**: Operated through a glove with flexible sensors.
- **High Accuracy**: Responsive and accurate movement.
- **Cost-Effective**: Utilizes readily available materials.
- **Easy Assembly**: Simple to install and assemble.
- **Versatile Applications**: Suitable for various hazardous environments.

## Project Structure

- **Arduino_Code**: Contains the Arduino source code for calibration and main operation.
- **Schematics**: Includes circuit diagrams.
- **Images & Videos**: Demonstration images and videos showcasing the project.

## Getting Started

### Prerequisites

- Arduino UNO
- NRF Transceiver Modules
- Flexible Sensors
- Servo Motors
- Breadboard and jumper wires
- Resistors and other basic electronic components
- Power supply (batteries or an adapter)
- Computer with Arduino IDE installed

### Installation
#### 1. Set Up the Hardware

##### Robotic Arm Assembly

1. **Build the Robotic Arm**: Build the 3D model of the arm based on your specific needs.
2. **Connect the Servo Motors**: Connect the servo motors to the Arduino UNO as per the circuit diagram provided in the `Schematics/Circuit_Diagram.pdf`.

##### Glove Assembly

1. **Attach Flexible Sensors**: Place the flexible sensors on the glove.
2. **Wire the Sensors**: Connect the sensors to the NRF transceiver module and then to the Arduino UNO following the circuit diagram.

#### 2. Upload Code to Arduino

##### Calibration Code

1. **Open Arduino IDE**: Launch the Arduino IDE on your computer.
2. **Open Calibration Code**:
   - Navigate to the `Arduino_Code` directory in the cloned repository.
   - Open the `Calibration_Code.ino` file in Arduino IDE.
3. **Connect Arduino UNO**: Connect your Arduino UNO to your computer using a USB cable.
4. **Select the Board and Port**:
   - Go to `Tools > Board` and select `Arduino UNO`.
   - Go to `Tools > Port` and select the appropriate port for your Arduino.
5. **Upload the Code**: Click the upload button (right arrow) in the Arduino IDE to upload the calibration code to the Arduino UNO.
6. **Calibrate the Sensors**:
   - Follow the calibration instructions provided in the `Documentation/Calibration_Process.md`.
   - Ensure all sensors are properly calibrated for accurate control.

##### Main Project Code

1. **Open Main Project Code**:
   - Navigate to the `Arduino_Code` directory.
   - Open the `Main_Project_Code.ino` file in Arduino IDE.
2. **Upload the Code**: Click the upload button in the Arduino IDE to upload the main project code to the Arduino UNO.

#### 3. Final Setup and Testing

1. **Power the Circuit**:
   - Connect the power supply to the Arduino and other components.
   - Ensure all connections are secure.
2. **Wear the Glove**: Ensure the glove with flexible sensors is properly fitted on your hand.
3. **Test the Control and calibration**:
   - Move your hand to test the robotic arm's movements.
