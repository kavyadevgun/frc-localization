# Instantaneous Position Project
## This document will provide an easy-to-follow user manual for the reader to replicate our instantaneous position system. 
1) You will need the following components:

Electronic components:
  - [Arduino UNO R3 controller board](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=asc_df_B008GRTSV6/?tag=hyprod-20&linkCode=df0&hvadid=309751315916&hvpos=&hvnetw=g&hvrand=16596161655038666986&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9019556&hvtargid=pla-457497319401&psc=1&tag=&ref=&adgrpid=67183599252&hvpone=&hvptwo=&hvadid=309751315916&hvpos=&hvnetw=g&hvrand=16596161655038666986&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9019556&hvtargid=pla-457497319401). 
  - [Female-to-male dupont wires](https://www.amazon.com/female-jumper-Dupont-Arduino-Breadboard/dp/B01FDD3LJA). 
  - A [breadboard](https://www.amazon.com/DEYUE-breadboard-Set-Prototype-Board/dp/B07LFD4LT6/ref=sr_1_1?dchild=1&keywords=breadboard&qid=1611798540&s=electronics&sr=1-1).
  - [Breadboard jumper wires](https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_3?crid=295FBR6HWRJ6Z&dchild=1&keywords=breadboard+jumper+wires&qid=1611798578&s=electronics&sprefix=breadboard+jump%2Celectronics%2C191&sr=1-3). 
  - [2K resistors](https://www.amazon.com/EDGELEC-Resistor-Tolerance-Multiple-Resistance/dp/B07QJB31M4/ref=sr_1_3?crid=11MPBKEPVKXA4&dchild=1&keywords=2k+resistor&qid=1611798604&sprefix=2k+resistance%2Celectronics%2C179&sr=8-3). 

Wheel components:
  - 2 [AMT 103V Encoders](https://www.mouser.com/ProductDetail/CUI-Devices/AMT103-V?qs=%2Fha2pyFadugimG5fIsqch5ZfA8H%2FZ5abFSUgMn5%252BIVw%3D&gclid=CjwKCAiAu8SABhAxEiwAsodSZMTk4yNiF3Q1-kwQHPKwzAf8UvomMOSElIQCnKRo9gF3vlXJTWBh5RoCKS4QAvD_BwE).
  - A [Dual LS7366R Quadrature Encoder Buffer](https://www.servocity.com/4-heavy-duty-wheel/).
  - A [4-inch wheel](https://www.servocity.com/4-heavy-duty-wheel/).
  - A [3-inch D-shaft](https://www.servocity.com/0-250-1-4-x-3-00-stainless-steel-d-shafting/).
  - A [dual ball bearing hub](https://www.servocity.com/dual-ball-bearing-hubs/).
  - 2 [Pairs of bearings](https://www.servocity.com/dual-ball-bearing-hubs/).
  - 3 [Hubs](https://www.servocity.com/0-250-bore-set-screw-d-hub-tapped-0-770-pattern/).
  - 6 [Shaft collars](https://www.servocity.com/0-250-bore-steel-set-screw-collar-2-pack/).
  - Double-sided tape.
  - Duct tape.
  - A [pattern bracket B](https://www.servocity.com/pattern-bracket-b/).
  - [Washers](https://www.servocity.com/6-undersized-washers-25-pack/).
  - A [hole pattern plate] (https://www.servocity.com/4-5-x-6-aluminum-pattern-plate/).
  - 25 [1/4-inch 6-32 UNC Socket Head Screws](https://www.servocity.com/6-32-socket-head-screws/).
  - 25 [one-inch 6-32 UNC Socket Head Screws](https://www.servocity.com/6-32-socket-head-screws/).
  - 25 [6-32 UNC Nuts](https://www.servocity.com/6-32-nylock-nuts-pack-25-pack/).
  - A [10-inch D-shaft](https://www.servocity.com/0-250-1-4-x-10-00-stainless-steel-d-shafting/).
  - A [12-wire through hole slip ring](https://www.amazon.com/Taidacent-Electrical-Collector-Conductive-Connector/dp/B07XHQLJ2H/ref=sr_1_2?dchild=1&keywords=CNBTR%2B12%2BWires%2B12.7MM%2BHole%2BDia%2BCurrent%2BConductors%2BCircuits%2BThrough%2BHole%2BSlip%2BRing%2B380V%2BAC%2FDC%2B10A%2BPower%2BCollector%2BRing%2B54mm&qid=1611349663&s=hi&sr=1-2&th=1).
  

2) The wiring of the electronic components is as follows:
  - 
 
3) Wheel set-up: 
  - In order to set up the wheel, 
    - Attach a Bore Set Screw D-Hub to each side of the wheel and run 4 1-inch screws through both of them, leaving space for an axle to go through. Attach nuts to the other ends of the screws.
    - Attach ½ inch bearing to the lowest ½ inch holes on each side of the pattern bracket, and run the 3-inch shaft through each of those with the wheel/hubs in the middle of them. On the outside of each of the bearings, attach a shaft collar around the shaft to hold it in place.
    - Attach the ¼ inch diameter adaptor to the encoder. Attach that encoder to one end of the shaft and use tape to fix it to the pattern bracket. On the side where the encoder is attached, attach the counter to the bracket with tape.
    - Attach the dual ball bearing hub to the ½ inch hole on top of the pattern bracket using two 1-inch screws. Run the 4 inch shaft through the dual ball bearing hub and attach an encoder with a ¼ inch adapter to the end of the shaft inside of the pattern bracket.
    - Attach the slip ring to one of the holes on the pattern plate. On that hole, attach a Bore Set Screw D-Hub. Run the four inch shaft attached to the top of the wheel apparatus to that D-Hub and use shaft collars to hold the shaft in place.
    - A budget sheet of all the components and their cost can be found [here](https://docs.google.com/spreadsheets/d/1regwJqUuxn_IKwp0wBsyjQyA4pPa4EQ17EqyYSeluSA/edit#gid=0).
   
   
  - [This diagram](https://i.imgur.com/9mRG25O.png) can be referenced to make sure your wheel is set up correctly. 
  

4) Once your wheel is set up and components are wired, you are ready to implement the software aspect of the project:
  - Download Arduino IDE from [here](https://www.arduino.cc/en/software).
  - In order to display your position readings in Visual Studio Code or the Driver Station console, you need to
    - Install software prerequisites (VS Code and WPI library):
      - Download Visual Studio Code [here](https://code.visualstudio.com/download).
      - Download the WPILib from [here](https://github.com/wpilibsuite/allwpilib/releases/tag/v2021.2.1). You will find instructions on installing WPILib [here](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/wpilib-setup.html).
      - Learn more about VS Code and WPILib extension [here](https://docs.wpilib.org/en/stable/docs/software/vscode-overview/vscode-basics.html). You can also find the WPILab commands in VS Code [here](https://docs.wpilib.org/en/stable/docs/software/vscode-overview/wpilib-commands-vscode.html). 
     - Build and deploy the Arduino program that calculates instantaneous position:
      - Connect your Arduino board to roboRIO via USB.
      - Make sure you are connected to the Driver Station.
      - Scroll down to Creating a New WPILib Project and follow instructions until the end of [this page](https://docs.wpilib.org/en/stable/docs/software/vscode-overview/creating-robot-program.html). 
      - Open the New Project, which will show up as Robot.Java on the left menu, and copy and paste [this code](https://github.com/brad95411/RoboRIOSerialToArduino/blob/master/src/main/java/frc/robot/Robot.java). Detailed explanation of the Java code, which sends signals from roboRIO to Arduino and receives signals back, can be found [here](https://www.youtube.com/watch?v=RMHCSwLIyqg&ab_channel=BradBickford). You can try the [Arduino code](https://github.com/brad95411/ArduinoSerialToRoboRIO/blob/master/RoboRIOSerialResponse.ino) provided in the video to make sure everything works properly. 
      - Now you can build your project by following [this link](https://docs.wpilib.org/en/stable/docs/software/vscode-overview/deploying-robot-code.html).
     - Now that your Arduino is connected to roboRIO, you will need to download [this folder](https://github.com/kavyadevgun/frc-localization/tree/gh-pages/Instantaneous%20Position%20Project) to your computer. Copy and paste [this Arduino](https://github.com/kavyadevgun/frc-localization/blob/gh-pages/Instantaneous%20Position%20Project/Arduino%20code%20for%20position.ino) code into a new project in your Arduino IDE. 
     - You then will build your project and deploy your code to display the results of your Arduino project in VS Code. You can also view your results in one of the two methods outlined in [this link](https://docs.wpilib.org/en/stable/docs/software/vscode-overview/viewing-console-output.html). 


5) Accuracy of the system:
  - 
     

