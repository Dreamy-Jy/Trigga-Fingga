/*
  Shift Register Example
for 74HC595 shift register

This sketch turns reads serial input and uses it to set the pins
of a 74HC595 shift register.

Hardware:
* 74HC595 shift register attached to pins 2, 3, and 4 of the Arduino,
as detailed below.
* LEDs attached to each of the outputs of the shift register

Created 22 May 2009
Created 23 Mar 2010
by Tom Igoe

*/

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 2;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 4;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 3;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);
}

void loop() {
  
  //0
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 63);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //1
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 6);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //2
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 91);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //3
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 79);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //4
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 102);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //5
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 109);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //6
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 125);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //7
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 7);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //8
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 127);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //9
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 103);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  //E
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 121);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  delay(100);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 121);
  digitalWrite(latchPin, HIGH);
  delay(1000);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  delay(100);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 121);
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
