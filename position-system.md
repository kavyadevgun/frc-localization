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
  
2) Download Arduino IDE from [here](https://www.arduino.cc/en/software).

3) 
