
#include<Wire.h>

long d; // just a variable to get the distance
int dis = 0; // distance for 
const int ec=10; // ultra sonic sensor's echo pin
const int tr=11; // ultra sonic sensor's trigger pin

void setup() {

 pinMode(ec, INPUT); // this will be the achknowledgment for the slave so the echo should be an input pin
 pinMode(tr, OUTPUT);  // as we know trigger must always be an output part
 Serial.begin(9600);
 Wire.begin(); // the write in the terminal will start

}

void loop() {
  digitalWrite(tr, LOW); //at first the write will be low 
  delayMicroseconds(10); // this is for the delay
  digitalWrite(tr, HIGH); // then the write will be high
  delayMicroseconds(10); 
  digitalWrite(tr, LOW);
  d = pulseIn(ec, HIGH); //pulseIn is mainly a library function


  dis = (d*0.034)/2; //calculating the distance
  if(dis < 255) // as it will be 8 bit and it cannot surpass 256 bits so max will be 255
  {
     Wire.beginTransmission(3); // transmission will start from 3
     Wire.write(dis); // the distance is going to be displayed here
     Wire.endTransmission(); // one transmission ends... so the process will go untill the program is stopped
     Serial.print("This one is for Master");
     Serial.println(dis); // the final print number which will show the distance
    }
  

}
