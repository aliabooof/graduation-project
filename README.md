# Autonomous Vehicle Control System with STM32F103C8T6 Microcontroller and Raspberry Pi Integration

Description:
The Autonomous Vehicle Control System is an advanced project designed to develop a self-driving car prototype. The system combines the power and flexibility of the STM32F103C8T6 microcontroller and Raspberry Pi integration to achieve autonomous navigation, obstacle detection, temperature monitoring, and robust security features. By leveraging a combination of sensors, including an ultrasonic sensor, temperature sensor, and a camera, the system ensures safe and efficient operation. Additionally, facial recognition technology enhances security by allowing only authorized individuals to access and operate the vehicle.

# Requirements:

#_1 STM32F103C8T6 Microcontroller:

Implement motor control algorithms to enable precise speed and direction control.
Integrate with the Raspberry Pi via UART for seamless communication.
Support various input/output configurations for sensor integration.
Ensure real-time responsiveness and reliable operation.
Raspberry Pi 4:

Run a line follower model to process camera frames and determine driving actions (right, left, forward, or stop) based on line detection algorithms.
Communicate with the STM32 microcontroller via UART for exchanging motor control instructions.
Utilize image processing libraries and algorithms for accurate line detection and tracking.
Support high-resolution camera input for capturing clear images.
L298N Motor Driver:

Provide efficient and reliable motor control for the vehicle's movement.
Enable precise control over motor speed and direction.
Integrate seamlessly with the STM32 microcontroller's output pins.
Ultrasonic Sensor:

Measure distances accurately to detect nearby objects and avoid collisions.
Provide real-time data on object proximity.
Interface with the STM32 microcontroller to trigger appropriate actions based on distance thresholds.
Temperature Sensor:

Monitor the vehicle's temperature to prevent overheating.
Implement temperature threshold detection and automatic system shutdown to protect the vehicle's components.
Integrate with the STM32 microcontroller for real-time temperature monitoring.
Camera:

Capture high-quality images for line detection and facial recognition.
Support video streaming capabilities for real-time image processing.
Interface with the Raspberry Pi for image acquisition and processing.
Facial Recognition:

Utilize the captured images from the camera for face detection and recognition.
Employ machine learning algorithms to match faces against a database of authorized individuals.
Implement a secure authentication mechanism to grant access only to authorized users.
Communicate with the server for additional processing and verification.
Server:

Receive and process images captured by the vehicle's camera.
Perform facial recognition on the received images to verify the user's identity.
Store and manage a database of authorized individuals for comparison during authentication.
Generate alerts and notifications in case of unauthorized access attempts.
Integrate with external services like Twilio for SMS notifications.
Twilio Integration:

Interface with the Twilio API to send SMS notifications to the car owner in the event of unauthorized access attempts.
Provide a secure and reliable communication channel for alerting the car owner.
Implement error handling and retry mechanisms for message delivery assurance.
Conclusion:
