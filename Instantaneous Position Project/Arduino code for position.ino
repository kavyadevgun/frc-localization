
/*This code is to run 2 rotary encoders and the navX MXP sensor the get heading from 
the sensor and distance travelled from the encoders in order to calculate position relative to starting position 
We made use of libraries from https://pdocs.kauailabs.com/navx-mxp/software/arduino-library/  which drive the naVx sensor and from 
https://github.com/SuperDroidRobots/Encoder-Buffer-Breakout which reads from the encoder*/




#include <Wire.h> //Arduino library
#include <SoftwareSerial.h>//Arduino library
#include "AHRSProtocol.h"//NavX library for arduino can be downloaded at https://pdocs.kauailabs.com/navx-mxp/software/arduino-library/
#include "IMURegisters.h"//NavX library for arduino can be downloaded at https://pdocs.kauailabs.com/navx-mxp/software/arduino-library/
#include "IMUProtocol.h"//NavX library for arduino can be downloaded at https://pdocs.kauailabs.com/navx-mxp/software/arduino-library/
#include <SPI.h>//Arduino library

// Slave Select pins for encoders 1 and 2
// Feel free to reallocate these pins to best suit your circuit
const int slaveSelectEnc1 = 7;
const int slaveSelectEnc2 = 8;

// These hold the current encoder count.
signed long encoder1count = 0;
signed long encoder2count = 0;

void initEncoders() {
  
  // Set slave selects as outputs
  pinMode(slaveSelectEnc1, OUTPUT);
  pinMode(slaveSelectEnc2, OUTPUT);
  
  // Raise select pins
  // Communication begins when you drop the individual select signsl
  digitalWrite(slaveSelectEnc1,HIGH);
  digitalWrite(slaveSelectEnc2,HIGH);
  
  SPI.begin();
  
  // Initialize encoder 1
  //    Clock division factor: 0
  //    Negative index input
  //    free-running count mode
  //    x4 quatrature count mode (four counts per quadrature cycle)
  // NOTE: For more information on commands, see datasheet, https://www.superdroidrobots.com/product_info/LS7366R.pdf   
  digitalWrite(slaveSelectEnc1,LOW);        // Begin SPI conversation
  SPI.transfer(0x88);                       // Write to MDR0
  SPI.transfer(0x03);                       // Configure to 4 byte mode
  digitalWrite(slaveSelectEnc1,HIGH);       // Terminate SPI conversation 

  // Initialize encoder 2
  //    Clock division factor: 0
  //    Negative index input
  //    free-running count mode
  //    x4 quatrature count mode (four counts per quadrature cycle)
  // NOTE: For more information on commands, see datasheet
  digitalWrite(slaveSelectEnc2,LOW);        // Begin SPI conversation
  SPI.transfer(0x88);                       // Write to MDR0
  SPI.transfer(0x03);                       // Configure to 4 byte mode
  digitalWrite(slaveSelectEnc2,HIGH);       // Terminate SPI conversation 
}

long readEncoder(int encoder) {
  
  // Initialize temporary variables for SPI read
  unsigned int count_1, count_2, count_3, count_4;
  long count_value;  
  
  // Read encoder 1
  if (encoder == 1) {
    digitalWrite(slaveSelectEnc1,LOW);      // Begin SPI conversation
    SPI.transfer(0x60);                     // Request count
    count_1 = SPI.transfer(0x00);           // Read highest order byte
    count_2 = SPI.transfer(0x00);           
    count_3 = SPI.transfer(0x00);           
    count_4 = SPI.transfer(0x00);           // Read lowest order byte
    digitalWrite(slaveSelectEnc1,HIGH);     // Terminate SPI conversation 
  }
  
  // Read encoder 2
  else if (encoder == 2) {
    digitalWrite(slaveSelectEnc2,LOW);      // Begin SPI conversation
    SPI.transfer(0x60);                      // Request count
    count_1 = SPI.transfer(0x00);           // Read highest order byte
    count_2 = SPI.transfer(0x00);           
    count_3 = SPI.transfer(0x00);           
    count_4 = SPI.transfer(0x00);           // Read lowest order byte
    digitalWrite(slaveSelectEnc2,HIGH);     // Terminate SPI conversation 
  }
  
  // Calculate encoder count
  count_value = (count_1 << 8) + count_2;
  count_value = (count_value << 8) + count_3;
  count_value = (count_value << 8) + count_4;
  
  return count_value;
}

void clearEncoderCount() {
    
  // Set encoder1's data register to 0
  digitalWrite(slaveSelectEnc1,LOW);      // Begin SPI conversation  
  // Write to DTR
  SPI.transfer(0x98);    
  // Load data
  SPI.transfer(0x00);  // Highest order byte
  SPI.transfer(0x00);           
  SPI.transfer(0x00);           
  SPI.transfer(0x00);  // lowest order byte
  digitalWrite(slaveSelectEnc1,HIGH);     // Terminate SPI conversation 
  
  delayMicroseconds(100);  // provides some breathing room between SPI conversations
  
  // Set encoder1's current data register to center
  digitalWrite(slaveSelectEnc1,LOW);      // Begin SPI conversation  
  SPI.transfer(0xE0);    
  digitalWrite(slaveSelectEnc1,HIGH);     // Terminate SPI conversation   
  
  // Set encoder2's data register to 0
  digitalWrite(slaveSelectEnc2,LOW);      // Begin SPI conversation  
  // Write to DTR
  SPI.transfer(0x98);    
  // Load data
  SPI.transfer(0x00);  // Highest order byte
  SPI.transfer(0x00);           
  SPI.transfer(0x00);           
  SPI.transfer(0x00);  // lowest order byte
  digitalWrite(slaveSelectEnc2,HIGH);     // Terminate SPI conversation 
  
  delayMicroseconds(100);  // provides some breathing room between SPI conversations
  
  // Set encoder2's current data register to center
  digitalWrite(slaveSelectEnc2,LOW);      // Begin SPI conversation  
  SPI.transfer(0xE0);    
  digitalWrite(slaveSelectEnc2,HIGH);     // Terminate SPI conversation 
}

//Define distance and heading//
bool flag = true;                         //used later to check for the first iteration of the loop 
float distance = 0;                       // keep track of distance travelled 
float NavX_initial_angle = 0;             //initialise navX initial angle, the actual angle will be read in through the first iteration.
float offset = 0;                         //variable to keep track of wheel offset from the navx heading
const float WheelDiameter = 4;            //diameter of wheel needed for distance calculation
float absolute_angle = 0;                 //variable to get the real angle where the wheel is facing relative to the field/ starting positin.
float x_pos = 0;                          //initialise x coordinate
float y_pos = 0;                          //initialise y coordinate
float prev_distance = 0;                  //used for comparing change in distance
int ss = 10;                              
int rx = 8;
int tx = 9;
SoftwareSerial serport(rx,tx);

byte x = 0;
byte y = 0;
byte data[512];
char protocol_buffer[128];

#define TEST_I2C
//#define TEST_UART
#define TEST_STREAM_UPDATE_RATE_CHANGE
#define TUNING_VAR_TEST 
//#define I2C_UPDATE_RATE_TEST
#define SPI_UPDATE_RATE_TEST
#define ITERATION_DELAY_MS 10
void tuning_var_test();
void periodic_update_rate_modify_i2c();

void setup()
{
  Serial.begin(9600);
  initEncoders();       Serial.println("Encoders Initialized...");  
  clearEncoderCount();  Serial.println("Encoders Cleared...");
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(ss,OUTPUT);
  digitalWrite(SS, HIGH);
  //SPI.begin();
  //SPI.setBitOrder(MSBFIRST);
  //SPI.setDataMode(SPI_MODE3);
  //SPI.setClockDivider(8); /* 16Mhz/32 = 500kHz; /16=1Mhz; /8=2Mhz */ 
  serport.begin(57600);
  for ( int i = 0; i < sizeof(data); i++ ) {
      data[i] = 0;
  }
  int bytes_to_send = IMUProtocol::encodeStreamCommand( protocol_buffer, 
        MSGID_YPR_UPDATE, 60);  
  serport.write((const uint8_t *)protocol_buffer,bytes_to_send);
}

int loop_count = 0;
int next = NAVX_REG_YAW_L;
void loop()
{
  //delay(100);
 
 // Retrieve current encoder counters
 encoder1count = readEncoder(1); 
 encoder2count = readEncoder(2);
 
 //Serial.print("Enc1: "); Serial.print(encoder1count); Serial.print(" Enc2: "); Serial.println(encoder2count); 

  int bytes_to_send = 0;
  //int uart_bytes_received = 0;
  int i = 0;
  int first = 0;
  //uint8_t spi_crc;
  //uint8_t spi_data[3];
  //next++;
  //if ( next > 1 ) {
      //next = 16;  
  //}
#ifdef TUNING_VAR_TEST  
  tuning_var_test();
#endif
#ifdef I2C_UPDATE_RATE_TEST
  periodic_update_rate_modify_i2c();
#endif
 
#ifdef TEST_I2C
  /* Transmit I2C data */
  Wire.beginTransmission(0x32); // transmit to device #0x32 (50)
  Wire.write(next); // Sends the starting register address
  Wire.write(8);   // Send number of bytes to read
  Wire.endTransmission();    // stop transmitting
  /* Receive the echoed value back */
  Wire.beginTransmission(0x32);
  Wire.requestFrom(0x32,8);
  while(Wire.available()) { // slave may send less than requested
     data[i++] = Wire.read();
  }
  Wire.endTransmission();
   // Get pitch yaw and roll values. 
  float yaw =  IMURegisters::decodeProtocolSignedHundredthsFloat((char *)&data[0])+180;   // The cast is needed on arduino, since the "byte" data type is an unsigne
  float pitch =  IMURegisters::decodeProtocolSignedHundredthsFloat((char *)&data[2]);   // The cast is needed on arduino, since the "byte" data type is an unsigne
  float roll =  IMURegisters::decodeProtocolSignedHundredthsFloat((char *)&data[4]);   // The cast is needed on arduino, since the "byte" data type is an unsigne
  float heading = IMURegisters::decodeProtocolUnsignedHundredthsFloat((char *)&data[6]);  // The cast is needed on arduino, since the "byte" data type is an unsigned char


  //check if first iteration 
  if (flag){
    NavX_initial_angle = yaw;
    flag = false;
    }
  
// update distance and Offset//////
  distance = (encoder2count*PI*WheelDiameter)/400;
  offset = (encoder1count)*(360.0/400.0);

  absolute_angle = (yaw - NavX_initial_angle)- offset*1.02;
  x_pos += (distance - prev_distance) * sin (absolute_angle * (PI/180));
  y_pos += (distance - prev_distance) * cos (absolute_angle * (PI/180));

  prev_distance = distance;
  Serial.print("yaw: ");
  Serial.print(yaw - NavX_initial_angle,2);
  //Serial.print(" offset: ");
  //Serial.print(offset,2);
  Serial.print(" absolute angle: ");
  Serial.println(absolute_angle,2);
  //Serial.print("X-position:");
  //Serial.print(x_pos);
  //Serial.print("     Y-position:");
  //Serial.println(y_pos);
  //Serial.print("Distance: ");
  //Serial.println(distance,2);
  //Serial.print("OffSet: ");
  //Serial.println(offset,2);
  

// This section communicates to the roborio using java 
//If the RoboRIO has sent something
  //if(Serial.available()) {
    //Read a byte from the input buffer
    //byte value = Serial.read();


  //If the byte is 0x12 (i.e. 18 in decimal)
    //if(value == 0x12) {
      
      //print data to send to roborio
      //Serial.print("Distance: ");
      //Serial.print(distance,2);
      //Serial.print(" OffSet: ");
      //Serial.println(offset,2);
    //}
  //}

    

#endif  

  delay(ITERATION_DELAY_MS);
  delay(50);
}
// LOOP ENDS HERE



int var = 1;
void tuning_var_test()
{
    int bytes_to_send = 0;
    int first = 0;
    if ( var > 4 ) {
        var = 1;
    }
    bytes_to_send = AHRSProtocol::encodeDataGetRequest( protocol_buffer, 
        TUNING_VARIABLE, (AHRS_TUNING_VAR_ID)var++);  
  if ( bytes_to_send > 0 ) 
  {
    serport.write((unsigned char *)protocol_buffer, bytes_to_send);           
  }
  delay(1);
  while(serport.available()) {
    if ( first == 0 ) {
        //Serial.print("UART:  ");
        first = 1;
    }
    Serial.print((char)serport.read());
  }
}

uint8_t min_update_rate = 1;
uint8_t max_update_rate = 100;
uint8_t curr_update_rate = min_update_rate;

uint8_t periodic_i2c_update_iteration_count = 0;
#define PERIODIC_I2C_UPDATE_ITERATIONS 50

void periodic_update_rate_modify_i2c()
{
    periodic_i2c_update_iteration_count++;
    if ( periodic_i2c_update_iteration_count >= PERIODIC_I2C_UPDATE_ITERATIONS ) {
        periodic_i2c_update_iteration_count = 0;
    } else {
        return;
    }
    if ( curr_update_rate > max_update_rate ) {
        curr_update_rate = min_update_rate;
    }
    
  /* Transmit I2C data */
  Wire.beginTransmission(0x32); // transmit to device #0x32 (50)
  Wire.write(0x80 | NAVX_REG_UPDATE_RATE_HZ); // Sends the starting register address
  Wire.write(curr_update_rate++);   // Send number of bytes to read
  Wire.endTransmission();    // stop transmitting

  

  
}
