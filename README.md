# HurdleDetectionUsingUltrasonicSensor

This Arduino-based project implements a simple yet effective obstacle detection system using an ultrasonic sensor. The system measures distances and categorizes them into three zones based on the detected proximity:

- **Red Zone (Danger)**: Indicates an obstacle within 40cm. The system activates an LED and alerts the user of a potential collision.
- **Yellow Zone (Caution)**: Represents obstacles within 40-80cm. The warning LED lights up, signaling a moderate proximity to an object.
- **Green Zone (Safe)**: Indicates distances greater than 80cm, considered a safe zone with no immediate obstacles.

The system utilizes an ultrasonic sensor to measure distances in centimeters and inches. It displays real-time distance readings on an LCD screen and relays the data via the serial monitor for debugging purposes.
Additionally, when an obstacle is detected within 15cm, the system triggers a "Vehicle Collided" alert, simulating a collision scenario. It then displays the alert on the LCD and initiates a call to emergency services (911) for immediate assistance.

Simulation: The code has been simulated using Tinkercad. You can view the simulated project and test its functionality [here](https://www.tinkercad.com/things/dsgjgU7oQnv-hurdle-detection).

