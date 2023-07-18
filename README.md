# Autonomous Vehicle Control System with STM32F103C8T6 Microcontroller and Raspberry Pi Integration

# Description
This project focuses on the development of a self-driving car system that utilizes the STM32F103C8T6 microcontroller for motor control, along with various sensors and communication modules. The system incorporates a line follower model running on a Raspberry Pi, which captures frames of the line and performs image processing to determine the appropriate driving actions. Additionally, security measures are implemented using facial recognition and communication with a server.

# Components

## STM32F103C8T6 Microcontroller 
The main control unit responsible for motor control and interfacing with various sensors.

## L298N Motor Driver
Controls the motors used for the car's movement, allowing precise speed and direction control.

## Buzzer
Used for audio feedback and alarm purposes.

## Ultrasonic Sensor
Measures the distance between the car and nearby objects, enabling obstacle detection and collision avoidance.

## Temperature Sensor
Monitors the car's temperature to prevent overheating and potential damage.

## Raspberry Pi 4
Runs the line follower model and performs image processing to determine the appropriate driving actions.

## UART Communication
Facilitates communication between the STM32 microcontroller and Raspberry Pi, allowing instruction exchange for motor control.

##Camera 
Mounted on the Raspberry Pi, captures images of the line and the user's face for further processing.

## Facial Recognition 
Utilizes the captured images to perform facial recognition and verify the user's identity for car access control.

## Server
Receives and processes the images from the car's camera, performing facial recognition and generating alerts if unauthorized access is detected.

## Twilio
Integrates with the server to send notifications to the car owner via SMS in case of unauthorized access attempts.

# Functionality

## Line Following 
The Raspberry Pi captures frames of the line, processes them, and determines the appropriate driving actions (right, left, forward, or stop). The instructions are then sent to the 

## STM32 microcontroller
for motor control.

## Security Measures 
The car's camera captures the user's face, and the server performs facial recognition to verify the owner's identity. If successful, the engine is unlocked and the car starts. If an 
unauthorized user is detected, a notification is sent to the car owner using Twilio, and the car's alarm is triggered.

## Temperature Monitoring
The temperature sensor measures the car's temperature, and if it exceeds a threshold, the STM32 microcontroller stops the car to prevent overheating and potential damage.

## Obstacle Detection
The ultrasonic sensor measures the distance between the car and nearby objects. If the distance falls below a certain threshold, the STM32 microcontroller stops the car to prevent 

# Videos of the project.

## Worng person
https://github.com/aliabooof/graduation-project/assets/62174374/7270cf0c-65ea-4380-9033-4c6400169cfc


## Right person
https://github.com/aliabooof/graduation-project/assets/62174374/21db6166-8d43-407b-a248-48f64af1fd79


## Line follower model
https://github.com/aliabooof/graduation-project/assets/62174374/c638c4c5-a6e8-4000-bc07-c1aab402dd8a

## Car 
https://github.com/aliabooof/graduation-project/assets/62174374/d501d961-4ec5-4660-8667-cce9bf26c828


https://github.com/aliabooof/graduation-project/assets/62174374/edc85ba0-8a72-4b2c-9503-a010c93f19b6



