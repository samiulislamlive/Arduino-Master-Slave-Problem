#include<Wire.h>
int dis = 0; // as this is the distance initially it will be 0
const int led = 4; // in the slave arduino the LED is connected to the 4 number pin so the number is 4
void setup() {
  Wire.begin(3); // as we started the process from 3 so it will be 3
  Wire.onReceive(receiveEvent); // this is a function which we called
  Serial.begin(9600);

  pinMode(led, OUTPUT);

}

void receiveEvent(int hm) //this is the slave's main part where it will get the message from the master arduino
{
  dis = Wire.read(); // it will read the value from the wire it has been put on with
  }


void loop() {
  if(dis < 255)
  {
    digitalWrite(led, HIGH); //led will light up high 
    delay(dis);
    digitalWrite(led, LOW); // led will not be lighted up
    delay(dis);
    Serial.print("This one is for Slave");
    Serial.println(dis); // slave will always respond to the light up and the low part of the LED which is mainly an ACKNOWLEDGMENT
    delay(10);
    
    }
}
