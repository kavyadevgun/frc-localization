# Initial Position System

### Sensor Overview
Finding the initial position is key to minimize error throughout the competition. To do this, we created a system that uses HC-SR04 Ultrasonic Sensors. We chose these sensors because they are compatible with Arduino, and they come in most Arduino starter kits. These sensors are also a good choice because they are budget-friendly without compromising measurement accuracy. The sensors have the ability to measure distances between 0.78 inches and 196 inches, and they are precise up to 0.12 inches (source [here](https://www.amazon.com/Smraza-Ultrasonic-Distance-Mounting-Duemilanove/dp/B01JG09DCK/ref=sr_1_3?dchild=1&keywords=hcsr04+ultrasonic+sensor&qid=1611768243&sr=8-3)).

### Sensor Function
The function of these sensors is fairly straightforward. Each ultrasonic sensor has two transducers -- one transmitter and one receiver. The transmitter sends out a sound pulse at 40 kHz which then reflects off of a hard, stationary surface (note: cloth fabrics tend to absorb these sound waves and are unable to reflect them). After reflection, the receiver picks up on the reflected pulse and records the total time (in microseconds) that the process took from initial transmission to final receipt. The following calculation is then performed to yield distance traveled in inches ([source](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/)):

![Diagram 1](https://i.imgur.com/lByl8aq.jpg)

By implementing an LCD screen, this distance measurement is visually output and constantly updates on the screen.  

In addition, students will be able to point the sensor set-up at a solid surface and save their desired distances in the Arduino computer that is wired inside of the system.  These “presets” will serve as various positions the robot can be placed in at the start of the round. During the actual competition, the students will be able to cycle through their saved presets -- a total of four presets -- so that they can recall precise initial positions and align the robot as accurately as possible. 

### RGB LED Light Conditions

A multi color LED will change color as an indicator of how close the user is to the current preset. The LED conditions are as follows:

- Red light: The actual, instantaneous distance from an object differs by 12 inches or more from the preset distance
- Yellow light: The actual, instantaneous distance from an object differs by between one and 12 inches from the preset distance
- Green light: The actual, instantaneous distance from an object differs by one inch or less from the preset distance

### Assembly Instructions
- Supplies
  - Purchase [this](https://www.amazon.com/ELEGOO-Project-Tutorial-Controller-Projects/dp/B01D8KOZF4/ref=sr_1_1_sspa?dchild=1&keywords=Arduino+Kit&qid=1611777868&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzVVE2TU5ROE9JWEhDJmVuY3J5cHRlZElkPUEwMDM3MDU5MzRMV0NTQ0UyTlNVSiZlbmNyeXB0ZWRBZElkPUExMDAxMzc2M1RTT1dKR0NNR05TQiZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) Arduino kit, or the following supplies:
    - [Arduino Uno R3 board](https://store.arduino.cc/usa/arduino-uno-rev3)
    - Compatible [Arduino Proto Shield with Mini Breadboard Expansion](https://www.amazon.com/HiLetgo-Prototype-Expansion-Breadboard-ProtoShield/dp/B00HHYBWPO)
    - 2 [HC-SR04 Ultrasonic Sensors](https://www.amazon.com/gp/r.html?C=1GDZONJ9HF37K&K=3B2G0ZV0A1VH&M=urn:rtn:msg:2021011121282433b57dc4b8254e6baad3efc7a030p0na&R=3G9W10FANOCDP&T=C&U=http%3A%2F%2Fwww.amazon.com%2Fdp%2FB01JG09DCK%2Fref%3Dpe_386300_440135490_TE_item&H=BDKG9KYPRODS8XFH3SEOJABZHQOA&ref_=pe_386300_440135490_TE_item)
    - [10 kΩ Potentiometer](https://www.digikey.com/en/products/detail/sparkfun-electronics/COM-09806/7319606)
    - 3 Compatible [Push Buttons](https://www.amazon.com/Gikfun-12x12x7-3-Tactile-Momentary-Arduino/dp/B01E38OS7K/ref=sr_1_2_sspa?dchild=1&keywords=arduino+buttons&qid=1611851687&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzNzFGSTU0QVlOVVBRJmVuY3J5cHRlZElkPUEwNDkwNzEwMkw4M0owOUhaS1lRTiZlbmNyeXB0ZWRBZElkPUEwMTgxNTM5MlJTRzFKT01HTzhDQiZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
    - Male to male, Female to male, and Female to female [Jumper Wires with Breadboards](https://www.amazon.com/gp/r.html?C=1N85WR5439VWW&K=3B2G0ZV0A1VH&M=urn:rtn:msg:202101171230453b721d91c130407fb321505db850p0na&R=1J0D6UYLQI8HN&T=C&U=http%3A%2F%2Fwww.amazon.com%2Fdp%2FB07H7V1X7Y%2Fref%3Dpe_386300_442618370_TE_dp_i1&H=2QLPGXOGBSAUXRDOIELJDQK2R4OA&ref_=pe_386300_442618370_TE_dp_i1)
    - [RGB LEDs](https://www.amazon.com/gp/r.html?C=1N85WR5439VWW&K=3B2G0ZV0A1VH&M=urn:rtn:msg:202101171230453b721d91c130407fb321505db850p0na&R=NIS0DW0LO0TO&T=C&U=http%3A%2F%2Fwww.amazon.com%2Fdp%2FB01C19ENDM%2Fref%3Dpe_386300_442618370_TE_dp_i2&H=XONWUUVMACQN5QKISLCAYXWYFPGA&ref_=pe_386300_442618370_TE_dp_i2)
    - [220 Ohm Resistors](https://www.amazon.com/EDGELEC-Resistor-Tolerance-Multiple-Resistance/dp/B07QK9ZBVZ/ref=sr_1_1_sspa?dchild=1&keywords=220+Ohm+Resistor&qid=1611852770&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFIQk1SS1BOVFFSUVAmZW5jcnlwdGVkSWQ9QTAyNTE0NzdaN0RDMzYxR0tPWDEmZW5jcnlwdGVkQWRJZD1BMDAyOTgxODJaUFZTWUlUV0pQUTMmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)
    - [9V Battery](https://www.amazon.com/Duracell-Coppertop-Alkaline-Batteries-Count/dp/B000K2NW08/ref=sr_1_6?dchild=1&keywords=9v+battery&qid=1611853083&sr=8-6)
    - [Battery Connector Clip](https://www.amazon.com/Chanzon-Battery-2-1x5-5mm-Connector-Leather/dp/B083QFPBKF/ref=sr_1_1_sspa?crid=16XS5GKJ3LSLR&dchild=1&keywords=9v%2Bbattery%2Band%2Bclip&qid=1611852947&sprefix=9v%2Bbatter%2Band%2B%2Caps%2C192&sr=8-1-spons&smid=A14FP9XIRL6C1F&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEySVMyWjBWVUUzRDNGJmVuY3J5cHRlZElkPUEwOTMzOTM2UDNPRloyMjBHMzFNJmVuY3J5cHRlZEFkSWQ9QTA1NTY3MjEyNjBLTEdXMU9WTkNPJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ&th=1)
    - [Standard A-B USB Cable](https://www.adafruit.com/product/62?gclid=Cj0KCQiA3smABhCjARIsAKtrg6K0xBUo_ZZIXmq0TXXiwlrTI4mY_M_sOQwaESvqYHqFZJxHh55nyP0aAreQEALw_wcB) to connect Arduino to computer

- Setting up the system

  Assemble parts according to this circuit diagram:

  ![Diagram 2](https://i.imgur.com/Nut4l3B.jpg)

  This is only a prototype circuit if assembled with the breadboards that are listed above, but the system can be made 
  permanent by soldering the components to an Arduino proto shield.

- Using the system

  Point the sensors at hard surfaces to take distance measurements. These measurements will appear on the LCD screen and will change as more distances are measured. To store a 
  preset distance in the Arduino's memory, hold down Button #1 until a message flashes on the screen indicating the new set distances, d<sub>1</sub> and d<sub>2</sub>. To recall 
  the preset distances at any time, hold down Button #2 until the preset distances flash across the LCD screen. To rotate between the four preset distances, hold down Button #3 
  until the LCD screen flashes a message indicating "PRESET 1", "PRESET 2", "PRESET 3", or "PRESET 4". To change switch to another preset again, release the button briefly 
  before holding it down again until the "PRESET" indicator appears on the screen once more.
  
*A video demonstrating these features can be found [here](https://www.youtube.com/watch?v=9ASeUNyned8). The Arduino code for this system is available in this repository under the name "Ultrasonic_Sensor_System_Code.ino".*

### Alignment Feature
These sensors can be used again throughout the competition to “check” and recalibrate the position of the robot as needed by the user. Additionally, there are two sensors in each set-up so that the system can be used for alignment purposes. Ideally, if the two sensors are reading two numbers that are very close to each other, the user has a general idea of whether the robot is oriented properly relative to the measurement reference point. If the numbers are not similar, then the user knows to adjust the position of the robot until the distance measurements are similar once more.

### Results
We conducted numerous tests to see how accurate the initial position system is at detecting distance. We tested their how well the sensors measure distances, how repeatable these measurements are, and alignment of these sensors. From these tests, we concluded that the HC-SR04 Ultrasonic Sensors can consistently measure within one inch of the actual distance. In addition, these tests yielded results to suggest that these measurements are repeatable within one inch, meaning if a sensor is initially set a certain distance away from a surface, moved around, and set back in its original position, the first and second distance measurements are within one inch of each other.

The final test confirmed that the two ultrasonic sensors attached to the system must be further apart to ensure that similar measurements are not caused by smaller arc lengths (from the angle that the sensors are offset by). This arc length will be shorter when the sensors are closer together, but longer when they are further apart. When they are further apart, this will cause more measurement variability, but more assurance that the sensors are properly aligned.

### Future Considerations

Future considerations for these sensors include designing a custom circuit board for a more permanent product (as opposed to soldering, making the system more accessible to FRC teams), integrating the ultrasonic sensors with the roboRIO in conjunction with the position system for recalibration purposes, and adding ping pong balls over the LEDs so that their color is more visible from far distances.
