Finding the initial position is key to minimize error throughout the competition. To do this, we created a system that uses HC-SR04 Ultrasonic Sensors. We chose these sensors because they are compatible with Arduino, and they come in most Arduino starter kits. These sensors are also a good choice because they are budget-friendly without compromising measurement accuracy. The sensors have the ability to measure distances between 0.78 inches and 196 inches, and they are precise up to 0.12 inches (source [here](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?dchild=1&keywords=hcsr04+ultrasonic+sensor&qid=1611768243&sr=8-3)).

The function of these sensors is fairly straightforward. Each ultrasonic sensor has two transducers -- one transmitter and one reciever. The transmitter sends out a sound pulse at 40 kHz which then reflects off of a hard, stationary surface (note: cloth fabrics tend to absorb these sound waves and are unable to reflect them). After reflection, the receiver picks up on the reflected pulse and records the total time (in microseconds) that the process took from initial transmission to final reciept. The calculation shown in [this image](https://i.imgur.com/lByl8aq.jpg) is then performed to yield distance traveled in inches ([source](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/)). By implementing an LCD screen, this distance measurement is visually output and constantly updates on the screen.  

In addition, students will be able to point the sensor set-up at a solid surface and save their desired distances in the Arduino computer that is wired inside of the system.  These “presets” will serve as various positions the robot can be placed in at the start of the round. During the actual competition, the students will be able to cycle through their saved presets -- a total of four presets -- so that they can recall precise initial positions and align the robot as accurately as possible. 

A multi color LED will change color as an indicator of how close the user is to the current preset. The LED conditions are as follows:

**Red light**

actualdistance < distanceSet - 12 OR actualdistance > distanceSet + 12

**Yellow light**

actualdistance > distanceSet - 12 && actualdistance < distanceSet - 1 OR actualdistance < distanceSet + 12 && actualdistance > distanceSet + 1

**Green light**

actualdistance > distanceSet - 1 && actualdistance < distanceSet + 1

- Supplies
  - Arduino Uno R3 board
  - Compatible Arduino proto shield
  - 2 HC-SR04 ultrasonic sensors
  - 10 kΩ Potentiometer
  - 3 Buttons
  - Male to male jumper cables
  - Female to male jumper cables
  - Soldering device

- Setting up System:
  - Using the soldering gun, attach all parts of the system according to this circuit diagram
  - A circuit diagram of the system set-up can be found [here](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?dchild=1&keywords=hcsr04+ultrasonic+sensor&qid=1611768243&sr=8-3).

- Use **add more here**

These sensors can be used again throughout the competition to “check” and recalibrate the position of the robot as needed by the user. Additionally, there are two sensors in each set-up so that the system can be used for alignment purposes. Ideally, if the two sensors are reading two numbers that are very close to each other, the user has a general idea of whether the robot is oriented properly relative to the measurement reference point.

Future considerations for these sensors include adding ping pong balls over the LEDs so that their color more visible from far distances.
