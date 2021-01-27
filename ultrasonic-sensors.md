Finding the initial position is key to minimize error throughout the competition.

To find the initial position, we created a system that uses HC-SR04 Ultrasonic Sensors. We chose these sensors because they are compatible with Arduino, and they come in most Arduino starter kits. These sensors are also a good choice because they are budget-friendly without compromising measurement accuracy. The sensors have the ability to measure distances between 0.78 inches and 196 inches, and they are precise up to 0.12 inches (source [here](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?dchild=1&keywords=hcsr04+ultrasonic+sensor&qid=1611768243&sr=8-3)).

The [function](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/) of these sensors is fairly straightforward. Each ultrasonic sensor has two transducers -- one transmitter and one reciever. The transmitter sends out a sound pulse at 40 kHz which then reflects off of a hard, stationary surface (note: cloth fabrics tend to absorb these sound waves and are unable to reflect them). After reflection, the receiver picks up on the reflected pulse and records the total time (in microseconds) that the process took from initial transmission to final reciept. The following calculation is then performed to yield distance traveled in inches:

distance (inches) = (total time (microseconds) * 0.0343 (speed of sound in centimeters per microsecond))/(2 (isolate one direction of travel) * 2.54 (centimeters per inch))

**how do distance sensors work**

**what is the set up of the system**

During the competition preparation season, students will be able to point our sensor set up at a solid surface and save their desired distances -- up to four "presets" -- in the Arduino computer that is wired inside of the system. During the actual competition, the students will be able to cycle through their saved presets so that the distance 

The distance from the walls will be displayed on an LCD screen and sent to the Robot’s system. A multi color LED will change color (on a scale of a red light meaning that the robot is far from the ideal position, a yellow light indicating that the robot is partially close, and a green light indicating that the robot is in range) as an indicator of how close the user is to the desired starting position. This desired starting position can be input by the user depending on the field layout.

These sensors can be used again throughout the competition to “check” and recalibrate the position of the robot as needed by the user.
Use ping pong balls
