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

We tackled this project by splitting our group into two teams -- the first team investigated the use of HC-SR04 Ultrasonic Sensors to determine the initial position of the robot relative to the objects in and around the field. The second team investigated the use of encoder technology used in conjunction with a NavX sensor to report the robot's instantaneous position throughout the course of the competition. 

The first system will be used to determine and check the placement of the initial position of the robot. Using two HC-SR04 Ultrasonic Sensors oriented in the same plane, students will be able to set and save starting positions that they would like their robot to be placed in during the actual competition. By saving these desired distances in the Arduino memory during the competition preparation season, students will be able to access these same saved distance measurements when initially placing their robots prior to the actual competition. They will receive visual confirmation of correct placement in two ways — both the desired and actual distance measurements will be displayed on an LCD screen, and a pair of RGB LEDs will light up differently according to set conditions based on the saved, preset distances. This system will also aid in proper alignment of the robot before the competition starts. **we should add a picture of the sensors and LCD screen here**

The second system will be used to give the user constant updates on the position of the robot. This will be achieved through combining the readings of two incremental encoders and a NavX-mxp sensor. The encoders will be placed on an add-on wheel ([Figure 1]([Imgur](https://i.imgur.com/NkYWwsZ.png)), which will be attached to the robot. Figure 2 shows a technical drawing of the wheel with the placement of the two encoders. Additionally, the NavX-mxp sensor will be placed on the robot. 


Please check out the other pages in this repository for more specifics about each project.
