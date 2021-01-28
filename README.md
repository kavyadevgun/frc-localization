# FRC Localization Project
## PHYS 360 Project Report: Interim 2021
### Kavya Devgun, Sara Barrows, Rahaf Youssef, Eric Johnson, and Elvis Haisa
### Professor Jason Engbrecht

Welcome! The purpose of this repository is to provide easy access to information about our FRC localization system project. Our project aims to locate First Robotics Competition (FRC) robots in the competition field. We created this system according to the following design requirements:

The localization system must be an off-the-shelf product that is:
1. Less than $400
2. Compatible with the FRC control system that is used by each team
3. Accurate within one foot, but preferably within one inch
4. Programmable in Java, C++, or LabVIEW

Our system consists of three main parts: one that determines the initial position of the robot, another that finds the instantaneous position of the robot throughout the competition, and a third that displays the position of the robot in a user-friendly manner.

We tackled this project by splitting our group into two teams -- the first team investigated the use of HC-SR04 Ultrasonic Sensors to determine the initial position of the robot relative to the objects in and around the field. The second team investigated the use of encoder technology used in conjunction with a navX sensor to report the robot's instantaneous position throughout the course of the competition. 

The first system will be used to determine and check the placement of the initial position of the robot. Using two HC-SR04 Ultrasonic Sensors oriented in the same plane, students will be able to set and save starting positions that they would like their robot to be placed in during the actual competition. By saving these desired distances in the Arduino memory during the competition preparation season, students will be able to access these same saved distance measurements when initially placing their robots prior to the actual competition. They will receive visual confirmation of correct placement in two ways — both the desired and actual distance measurements will be displayed on an LCD screen, and a pair of RGB LEDs will light up differently according to set conditions based on the saved, preset distances. This system will also aid in proper alignment of the robot before the competition starts. Picture of our currect prototype:

![Diagram 1](https://i.imgur.com/og15BO1.jpg)

The second system will be used to give the user constant updates on the position of the robot. This will be achieved through combining the readings of two incremental encoders and a navX-mxp sensor. The encoders will be placed on an add-on wheel, which will be attached to the robot.

![Diagram 2](https://i.imgur.com/NkYWwsZ.png)

The following technical drawing of the wheel shows the placement of the two encoders:

![Diagram 3](https://i.imgur.com/9mRG25O.png) 

Additionally, the navX-mxp sensor will be placed on the robot.

One of the encoders will be used to find the distance that the add-on wheel has traveled. The other encoder will be used to get the orientation of the wheel relative to the direction of the robot. The navX-mxp sensor will be used to find the orientation of the robot. Our program will compare the orientation from the encoder attached to the upper axle to that from navX. By taking the angles added together, the system is able to determine the orientation of the add-on wheel relative to its starting orientation. Finally, our program will put together the traveled distance and the orientation to print out the current position of the wheel.

The end goal for this product will be a system composed of two parts, the initial positioning system and the instantaneous positioning system. At the start of the match, the users will use the initial positioning system to properly place the robot at their desired distances away from reference points, accompanied by visual confirmation. Once the match starts, users will start using the instantaneous positioning system, which will set their starting position as (0, 0). The robot will then track its position through an add-on wheel which is presumed to be in constant contact with the ground. As described above, the readings of the two encoders and navX-mxp sensors will be processed by Arduino to calculate the position of the wheel. 

Once we have a value for position, we will display this information in Visual Studio Code (VS Code) or the Driver Station console. This can be done by a Java code that makes RoboRIO send a signal to Arduino to request information about the position. Once Arduino has sent a signal containing the position coordinates, the program will display this information in VS Code. The position coordinates can also be viewed in the Driver Station console to make it easier for the robot driver. 

Please check out the other pages in this repository for more specifics about each project.
