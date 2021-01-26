# FRC Localization Project
## PHYS 360 Project Report: Interim 2021
### Kavya Devgun, Sara Barrows, Rahaf Youssef, Eric Johnson, and Elvis Haisa
### Professor Jason Engbrecht

Welcome! The purpose of this repository is to provide easy access to information about our FRC localization system project. 

Our project aims to locate First Robotics Competition (FRC) robots in the competition field. To this end, our system consists of three subsystems: one that finds the initial position, another that finds the instantaneous position of the robot, and finally a system that displays the position and orientation of the robot in a user-friendly way. The description of the project and its subsystems is as follows:

We created a system according to the following design requirements:

*The localization system must be an off-the-shelf product that is:*
1. *Less than $400*
2. *Compatible with the FRC control system that is used by each team*
3. *Accurate within one foot, but preferably within one inch*
4. *The system is programmable in Java, C++, or LabVIEW*

We tackled this problem by splitting our group into two teams -- one team investigated the use of HC-SR04 Ultrasonic Sensors to determine the initial position of the robot, and the other team investigated the use of encoder technology used in conjunction with a navEx sensor to report the robot's instantaneous position throughout the course of the competition.
