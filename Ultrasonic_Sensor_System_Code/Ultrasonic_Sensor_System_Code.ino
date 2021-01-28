//Code adapted from http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/

//include libraries
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <ButtonEvents.h>

//define variables and initialize Arduino pins

//initialize LCD pin
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

//initialize ultrasonic sensor pins
int trigPind1 = 1;
int echoPind1 = 2;
int trigPind2 = 12;
int echoPind2 = 13;

//initialize LED pins
int redPind1=A5;
int greenPind1=A4;
int bluePind1=A3;
int redPind2=A2;
int greenPind2=A1;
int bluePind2=A0;

//define distance variable
float distanced1;
float distanced2;

//make arrady to store multiple preset values under distanceSetd1 and distanceSetd2
float distanceSetd1[4]; 
float distanceSetd2[4];

//initialize button pins
const byte buttonPin1 = 3;
const byte buttonPin2 = 4;
const byte buttonPin3 = 5;

//define buttons 1,2,3
ButtonEvents button1;
ButtonEvents button2;
ButtonEvents button3;

//define t to track preset number
//serves as index for distanceSetd1[t], distanceSetd2[t], and EEPROM positions
int t=0; 

//define variables for distance calculations
int a;
int b;
int c;
int d;

float e;
float f;
float g;
float h;

void setup() {
  // put your setup code here, to run once:

  //set dimensions of LCD
  lcd.begin(16,2); 

  //setup pins as output/input
  //output - Arduino sends signal out
  //input - Arduino reads signal coming in
  
  //pin setup for ultrasonic sensors
  pinMode(trigPind1, OUTPUT);
  pinMode(echoPind1, INPUT);
  pinMode(trigPind2, OUTPUT);
  pinMode(echoPind2, INPUT);

  //pin setup for RGB LEDs
  pinMode(redPind1, OUTPUT);
  pinMode(greenPind1, OUTPUT);
  pinMode(bluePind1, OUTPUT);
  pinMode(redPind2, OUTPUT);
  pinMode(greenPind2, OUTPUT);
  pinMode(bluePind2, OUTPUT);

  //pin setup for buttons
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  //attach button pins to Button Event library
  button1.attach(buttonPin1);
  button2.attach(buttonPin2);
  button3.attach(buttonPin3);

  //preset number appears on LCD screen
  lcd.clear();
  lcd.print("PRESET #");
  lcd.print(t+1);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  //diplay preset number in top right corner
  lcd.setCursor(15,0);
  lcd.print(t+1);

  //conditions for holding 3 buttons
  
  //if button 1 is held:
  //saves intantaneous position as preset distances in d1 and d2 direction
  if (button1.update() == true){
    switch(button1.event()) {
      case (hold) : {
        
        //the instantaneous distances will be saved in variables a,b,c,d
        //since a and c are int values, no decimals are saved to them
        //b and d equations record decimals of distanced1 and distanced2
        //breaking up integers and decimals is necessary to save decimals on Arduino correctly
        a=distanced1;
        b=(distanced1-a)*100;
        c=distanced2;
        d=(distanced2-c)*100;

        //these values will be written into Arduino and saved if Arduino is unplugged using EEPROM.write
        //serve as preset distances so teams can save their desired initial position distances
        EEPROM.write(t,a);
        EEPROM.write(t+10,b);
        EEPROM.write(t+20,c);
        EEPROM.write(t+30,d);

        //take saved distances and assign them new names
        e=EEPROM.read(t);
        f=EEPROM.read(t+10);
        g=EEPROM.read(t+20);
        h=EEPROM.read(t+30);

        //below equations combine decimals and integers back into one number for LCD displays/LED conditions
        //distanceSetd1[t] and distanceSetd2[t] are the preset distances
        //t serves as index variable corresponding to each preset
        distanceSetd1[t]=e+f/100;
        distanceSetd2[t]=g+h/100;

        //the new presets (d1 and d2 direction) will be displayed on LCD screen
        //if statements to minimize inaccurate (extra large - over 200 inches) distance readings
        //this avoids spotty ultrasonic distance readings
        if(distanced1<200){
          lcd.setCursor(0,0);
          lcd.print("              ");
          lcd.setCursor(0,0);
          lcd.print("SET d1: ");
          lcd.print(distanceSetd1[t]);
          }
       
        if(distanced2<200){
          lcd.setCursor(0,1);
          lcd.print("                ");
          lcd.setCursor(0,1);
          lcd.print("SET d2: ");
          lcd.print(distanceSetd2[t]);
          }
        delay(3000);  

        break;
      }}}

  //if button 2 is held:
  //displays current preset distances
  if (button2.update() == true){
    switch(button2.event()) {
      case (hold) : {

        //recalling distances from Arduino board
        e=EEPROM.read(t);
        f=EEPROM.read(t+10);
        g=EEPROM.read(t+20);
        h=EEPROM.read(t+30);
        distanceSetd1[t]=e+f/100;
        distanceSetd2[t]=g+h/100;

        //current preset distances appear on LCD screen
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("              ");
        lcd.setCursor(0,0);
        lcd.print("PRESET d1: ");
        lcd.print(distanceSetd1[t]);
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("PRESET d2: ");
        lcd.print(distanceSetd2[t]);
        delay(4000);
        lcd.clear();
        break;
      }}}

  //if button 3 is held:
  //switch from current to next preset (between four overall preset distances)
  if (button3.update() == true){
    switch(button3.event()) {
      case (hold) : {
        
        //add one to preset counter to rotate through the four presets
        t=t+1;

        //return to first preset if on 4th preset
        if(t>3){t=0;}

        //display preset number on LCD screen
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("PRESET #");
        lcd.print(t+1);
        delay(3000);
        break;
      }}}

  //send signals out of both ultrasonic sensors
  //"LOW" state is included to make sure detection period is isolated
  digitalWrite(trigPind1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPind1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPind1, LOW);
  
  //calculate instantaneous distance (in inches)
  //pulseIN finds time (in microseconds) it takes for ultrasonic sound wave to be transmitted and received
  //then multiply time by speed of sound (cm/microseconds), divide by 2 (since travels to wall and back), and convert into inches
  distanced1 = pulseIn(echoPind1, HIGH)*0.0343/2/2.54;

  //repeat for d2
  digitalWrite(trigPind2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPind2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPind2, LOW);
  distanced2 = pulseIn(echoPind2, HIGH)*0.0343/2/2.54;

  //recalling distances from Arduino board
  e=EEPROM.read(t);
  f=EEPROM.read(t+10);
  g=EEPROM.read(t+20);
  h=EEPROM.read(t+30);
  distanceSetd1[t]=e+f/100;
  distanceSetd2[t]=g+h/100;

  //if statements minimize inaccurate (extra large - over 200 inches) distance readings
  //this avoids spotty ultrasonic distance readings
  if(distanced1<200){
    //display instantaneous distance on LCD screen
    lcd.setCursor(0,0);
    lcd.print("               ");
    lcd.setCursor(0,0);
    lcd.print("d1: ");
    lcd.print(distanced1);

    //RGB LEDs light up according to how far instantaneous distances are away from current preset distance
    //if 12 inches or more away from current preset distance, LED turns red
    //if under 1 inch away from current preset distance, LED turns green
    //if less than 12 inches but not within 1 inch from current preset distance, LED turns yellow
    if(distanced1>=distanceSetd1[t]+12.0 or distanced1<=distanceSetd1[t]-12.0)
      {colorFunction(redPind1, greenPind1, bluePind1, 255,0,0);}
    if(distanced1>distanceSetd1[t]-12.0 && distanced1<=distanceSetd1[t]-1.0 or distanced1<distanceSetd1[t]+12.0 && distanced1>=distanceSetd1[t]+1.0)
      {colorFunction(redPind1, greenPind1, bluePind1, 255,255,0);}
    if(distanced1>distanceSetd1[t]-1.0 && distanced1<distanceSetd1[t]+1.0)
      {colorFunction(redPind1, greenPind1, bluePind1, 0,255,0);}}

  //repeat for d2 sensor and d2 LED
  if(distanced2<200){
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("d2: ");
    lcd.print(distanced2);
    delay(100);  
    if(distanced2>=distanceSetd2[t]+12.0 or distanced2<=distanceSetd2[t]-12.0)
      {colorFunction(redPind2, greenPind2, bluePind2, 255,0,0);}
    if(distanced2>distanceSetd2[t]-12.0 && distanced2<=distanceSetd2[t]-1.0 or distanced2<distanceSetd2[t]+12.0 && distanced2>=distanceSetd2[t]+1.0)
      {colorFunction(redPind2, greenPind2, bluePind2, 255,255,0);}
    if(distanced2>distanceSetd2[t]-1.0 && distanced2<distanceSetd2[t]+1.0)
      {colorFunction(redPind2, greenPind2, bluePind2, 0,255,0);}}
    
  delay(1000);
}

//create function to implement LED conditions (from above) by inputting pin numbers and corresponding color codes
void colorFunction(int redPin, int greenPin, int bluePin, int redVal, int greenVal, int blueVal)
 {analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);}
