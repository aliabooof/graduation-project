# Autonomous Vehicle Control System with STM32F103C8T6 Microcontroller and Raspberry Pi Integration

# Description:
This project focuses on the development of a self-driving car system that utilizes the STM32F103C8T6 microcontroller for motor control, along with various sensors and communication modules. The system incorporates a line follower model running on a Raspberry Pi, which captures frames of the line and performs image processing to determine the appropriate driving actions. Additionally, security measures are implemented using facial recognition and communication with a server.

# Requirements:

## STM32F103C8T6 Microcontroller:

Implement motor control algorithms to enable precise speed and direction control.
Integrate with the Raspberry Pi via UART for seamless communication.
Support various input/output configurations for sensor integration.
Ensure real-time responsiveness and reliable operation.

## Raspberry Pi 4:

Run a line follower model to process camera frames and determine driving actions (right, left, forward, or stop) based on line detection algorithms.
Communicate with the STM32 microcontroller via UART for exchanging motor control instructions.
Utilize image processing libraries and algorithms for accurate line detection and tracking.
Support high-resolution camera input for capturing clear images.

## L298N Motor Driver:

Provide efficient and reliable motor control for the vehicle's movement.
Enable precise control over motor speed and direction.
Integrate seamlessly with the STM32 microcontroller's output pins.

## Ultrasonic Sensor:

Measure distances accurately to detect nearby objects and avoid collisions.
Provide real-time data on object proximity.
Interface with the STM32 microcontroller to trigger appropriate actions based on distance thresholds.

##Temperature Sensor:

Monitor the vehicle's temperature to prevent overheating.
Implement temperature threshold detection and automatic system shutdown to protect the vehicle's components.
Integrate with the STM32 microcontroller for real-time temperature monitoring.

## Camera:

Capture high-quality images for line detection and facial recognition.
Support video streaming capabilities for real-time image processing.
Interface with the Raspberry Pi for image acquisition and processing.

## Facial Recognition:

Utilize the captured images from the camera for face detection and recognition.
Employ machine learning algorithms to match faces against a database of authorized individuals.
Implement a secure authentication mechanism to grant access only to authorized users.
Communicate with the server for additional processing and verification.




## Server:

Receive and process images captured by the vehicle's camera.
Perform facial recognition on the received images to verify the user's identity.
Store and manage a database of authorized individuals for comparison during authentication.
Generate alerts and notifications in case of unauthorized access attempts.
Integrate with external services like Twilio for SMS notifications.

## Twilio Integration:

Interface with the Twilio API to send SMS notifications to the car owner in the event of unauthorized access attempts.
Provide a secure and reliable communication channel for alerting the car owner.
Implement error handling and retry mechanisms for message delivery assurance.

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



