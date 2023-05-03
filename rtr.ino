#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // SRX | STX
// Connect the HC-05 TX to Arduino pin 2(as SRX).
// Connect the HC-05 RX to Arduino pin 3 (as STX) through a voltage divider.
#define IN1 12
#define IN2 11
#define IN3 10
#define IN4 9

void setup()
{
 Serial.begin(9600);
 BTserial.begin(9600);
}

void loop()
{
 while (BTserial.available())
 {
   int x = BTserial.read();
   Serial.write(x);
   Serial.println("running");
   Serial.println(x);

   if(x==50){
    Serial.println("forward");
    forward();
   } else if (x==51){
    Serial.println("reverse");
    reverse();
   } else if (x==48){
    Serial.println("left");
    left();
   } else if (x==49){
    Serial.println("right");
    right();
   } else if (x==52){
    Serial.println("right");
    stoprobot();
   }


//   switch (x)
//{
//    case 1: 
//        forward();
//    case 2:
//        reverse();
//    case 3:
//        left();
//    case 4:
//        right();
//    default:
//        stoprobot(); 
//}
 }

 if (Serial.available())
 {
   int y = Serial.read();
   BTserial.write(y);
   if(y == 1) {
    Serial.write("forward");
   }
 }
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stoprobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
