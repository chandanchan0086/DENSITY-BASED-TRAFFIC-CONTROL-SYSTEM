#include <Ultrasonic.h>
int signal1[] = {23, 25, 27};
int signal2[] = {46, 48, 50};
int signal3[] = {11, 12, 13};
int signal4[] = {10, 9, 8};

int sw1=14,sw2=15,sw3=16,sw4=17;
int E1=0,E2=0,E3=0,E4=0;
int reddelay = 700;
int yellowdelay = 300;
int T=200;
int S1, S2, S3, S4;

Ultrasonic ultrasonic1(31, 29);
Ultrasonic ultrasonic2(44, 42);
Ultrasonic ultrasonic3(7, 6);
Ultrasonic ultrasonic4(5, 4);

void setup() {
  Serial.begin(9600);
  Serial.println("AUTOMATIC TRAFFIC CONTROL SYSTEM");
  // Declaring all the LED's as output
  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
}

void EMERGENCY()
{
  E1=digitalRead(sw1);
  E2=digitalRead(sw2);
  E3=digitalRead(sw3);
  E4=digitalRead(sw4);
  return;
}
void ultra_sonic_values()
{
  // Reading from first ultrasonic sensor
  S1= ultrasonic1.read(CM);
  // Reading from second ultrasonic sensor
  S2= ultrasonic2.read(CM);
  // Reading from third ultrasonic sensor
  S3= ultrasonic3.read(CM);
  // Reading from fourth ultrasonic sensor
  S4= ultrasonic4.read(CM);
  // Print distance values on serial monitor for debugging
  Serial.print("S1: ");
  Serial.print(S1);
  Serial.print("  S2: ");
  Serial.print(S2);
  Serial.print("  S3: ");
  Serial.print(S3);
  Serial.print("  S4: ");
  Serial.println(S4);
  delay(100);
  return;
}

void sub1()
{
  while(E1 != 0)
  {
    Serial.println("Ambulance in path 1");
    E1=digitalRead(sw1);
    digitalWrite(signal1[2], HIGH);
    digitalWrite(signal1[1], LOW);
    digitalWrite(signal1[0], LOW);
    digitalWrite(signal2[2], LOW);
    digitalWrite(signal2[1], LOW);
    digitalWrite(signal2[0], HIGH);
    digitalWrite(signal3[2], LOW);
    digitalWrite(signal3[1], LOW);
    digitalWrite(signal3[0], HIGH);
    digitalWrite(signal4[2], LOW);
    digitalWrite(signal4[1], LOW);
    digitalWrite(signal4[0], HIGH);
  }
  Serial.println("Ambulance in path 1 Cleared");
  return;
}

void sub2()
{
 while(E2 != 0)
 {
  Serial.println("Ambulance in path 2");
  E2=digitalRead(sw2);
  digitalWrite(signal1[2], LOW);
  digitalWrite(signal1[1], LOW);
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[2], HIGH);
  digitalWrite(signal2[1], LOW);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal3[2], LOW);
  digitalWrite(signal3[1], LOW);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[2], LOW);
  digitalWrite(signal4[1], LOW);
  digitalWrite(signal4[0], HIGH);
 }
 Serial.println("Ambulance in path 2 Cleared");
  return;
}

void sub3()
{
 while(E3 != 0)
 {
  Serial.println("Ambulance in path 3");
  E3=digitalRead(sw3);
  digitalWrite(signal1[2], LOW);
  digitalWrite(signal1[1], LOW);
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[2], LOW);
  digitalWrite(signal2[1], LOW);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[2], HIGH);
  digitalWrite(signal3[1], LOW);
  digitalWrite(signal3[0], LOW);
  digitalWrite(signal4[2], LOW);
  digitalWrite(signal4[1], LOW);
  digitalWrite(signal4[0], HIGH);
 }
 Serial.println("Ambulance in path 3 Cleared");
  return;
}

void sub4()
{
 while(E4 != 0)
 {
  Serial.println("Ambulance in path 4");
  E4=digitalRead(sw4);
  digitalWrite(signal1[2], LOW);
  digitalWrite(signal1[1], LOW);
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[2], LOW);
  digitalWrite(signal2[1], LOW);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[2], LOW);
  digitalWrite(signal3[1], LOW);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[2], HIGH);
  digitalWrite(signal4[1], LOW);
  digitalWrite(signal4[0], LOW);
 }
 Serial.println("Ambulance in path 4 Cleared");
  return;
}

void SignalFunc1()
{
ultra_sonic_values();
EMERGENCY();
if(E1)
{
  sub1();
}
if(E2)
{
  sub2();
}
if(E3)
{
  sub3();
}
if(E4)
{
  sub4();
}
if(S1>=T){
  Serial.println("No VEHICLES-1");
return;
}
if(S1<T && S1<50)
{
  Serial.println("High Density-1");
  reddelay=3000;
}
digitalWrite(signal1[2], HIGH);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], HIGH);
delay(reddelay);
reddelay = 700;
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], HIGH);
digitalWrite(signal1[0], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], HIGH);
digitalWrite(signal2[0], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], HIGH);
delay(yellowdelay);
}

void SignalFunc2()
{
ultra_sonic_values();
EMERGENCY();
if(E1)
{
  sub1();
}
if(E2)
{
  sub2();
}
if(E3)
{
  sub3();
}
if(E4)
{
  sub4();
}
if(S2>=T){
  Serial.println("No VEHICLES-2");
return;
}
if(S2<T && S2<50)
{
  Serial.println("High Density-2");
  reddelay=3000;
}
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal2[2], HIGH);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], HIGH);
delay(reddelay);
reddelay = 700;
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], HIGH);
digitalWrite(signal2[0], LOW);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], HIGH);
digitalWrite(signal3[0], LOW);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], HIGH);
delay(yellowdelay);
}

void SignalFunc3()
{
ultra_sonic_values();
EMERGENCY();
if(E1)
{
  sub1();
}
if(E2)
{
  sub2();
}
if(E3)
{
  sub3();
}
if(E4)
{
  sub4();
}
if(S3>=T){
  Serial.println("No VEHICLES-3");
return;
}
if(S3<T && S3<50)
{
  Serial.println("High Density-3");
  reddelay=3000;
}
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal3[2], HIGH);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], LOW);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], HIGH);
delay(reddelay);
reddelay = 700;
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], HIGH);
digitalWrite(signal3[0], LOW);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], HIGH);
digitalWrite(signal4[0], LOW);
delay(yellowdelay);
}

void SignalFunc4()
{
ultra_sonic_values();
EMERGENCY();
if(E1)
{
  sub1();
}
if(E2)
{
  sub2();
}
if(E3)
{
  sub3();
}
if(E4)
{
  sub4();
}
if(S4>=T){
  Serial.println("No VEHICLES-4");
return;
}
if(S4<T && S4<50)
{
  Serial.println("High Density-4");
  reddelay=3000;
}
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], LOW);
digitalWrite(signal1[0], HIGH);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal4[2], HIGH);
digitalWrite(signal4[1], LOW);
digitalWrite(signal4[0], LOW);
delay(reddelay);
reddelay = 700;
digitalWrite(signal1[2], LOW);
digitalWrite(signal1[1], HIGH);
digitalWrite(signal1[0], LOW);
digitalWrite(signal2[2], LOW);
digitalWrite(signal2[1], LOW);
digitalWrite(signal2[0], HIGH);
digitalWrite(signal3[2], LOW);
digitalWrite(signal3[1], LOW);
digitalWrite(signal3[0], HIGH);
digitalWrite(signal4[2], LOW);
digitalWrite(signal4[1], HIGH);
digitalWrite(signal4[0], LOW);
delay(yellowdelay);
}

void loop() {
    SignalFunc1();
    SignalFunc2();
    SignalFunc3();
    SignalFunc4();
}
