Finding the initial position is key to minimize error throughout the competition.

To find the initial position, we created a system that uses HC-SR04 Ultrasonic Sensors. We chose these sensors because they are compatible with Arduino, and they come in most Arduino starter kits. These sensors are also a good choice because they are budget-friendly without compromising measurement accuracy. The sensors have the ability to measure distances between 0.78 inches and 196 inches, and they are precise up to 0.12 inches (source [here](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?dchild=1&keywords=hcsr04+ultrasonic+sensor&qid=1611768243&sr=8-3)).

The [function](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/) of these sensors is fairly straightforward. Each ultrasonic sensor has two transducers -- one transmitter and one reciever. The transmitter sends out a sound pulse at 40 kHz which then reflects off of a hard, stationary surface (note: cloth fabrics tend to absorb these sound waves and are unable to reflect them). After reflection, the receiver picks up on the reflected pulse and records the total time (in microseconds) that the process took from initial transmission to final reciept. The following calculation is then performed to yield distance traveled in inches:

distance (inches) = (total time (microseconds) * 0.0343 (speed of sound in centimeters per microsecond))/(2 (isolate one direction of travel) * 2.54 (centimeters per inch))

**how do distance sensors work**

**what is the set up of the system**
By implamenting an LCD screen, this distance measurement is read and constantly updating.

Using the ultrasonic sensor measurements, the distance from the walls will constantly be updated and the instantaneous position of the robot will be displayed on an LCD screen and sent to the Robot’s system.  

In addition, students will be able to point our sensor set up at a solid surface and save their desired distances in the Arduino computer that is wired inside of the system.  These “presets” will serve as various positions the robot can be placed in at the start of the round.  During the actual competition, the students will be able to cycle through their saved presets, four overall, so that they can recall precise initial positions and align the robot as accurately as possible.  

A multi color LED will change color as an indicator of how close the user is to the current preset.  If the LED appears red, the robot is 12 or more inches away from the preset distance, if the LED appears yellow, the robot is within 12 inches of the preset distance (but not closer than an inch), and if the LED appears green, the robot is within 1 inch of the preset distance.

These sensors can be used again throughout the competition to “check” and recalibrate the position of the robot as needed by the user.

Possible additions to the ultrasonic sensors is using them throughout the competition to “check” and recalibrate the position of the robot as needed by the user.  Other additions include the use of ping pong balls as a cap to the LEDs, to make their color more visible from far distances.
