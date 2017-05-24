/* Trigga Fingga v.0.1
 *  
 *  This code just counts the amounts of 
 *  times a button has been pressed
 *  
 *  this code was inpart inspired by the debounce example
 */

//pins in use 
const int btnPin = 7;
const int latchPin = 2;// pin 12 of the 74HC595 blue
const int clockPin = 4;// pin 14 of the 74HC595 orange
const int dataPin = 3;// pin 11 of the 74HC595 green

//state trackers
int btnState;
int lastBtnState = LOW;

//press tracker
int cout = 0;
const int MAXCOUT = 10;
int show[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};

//timers
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  pinMode(btnPin, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT);

  //Set the display to zero
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 63);
  digitalWrite(latchPin, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(btnPin);

  if (reading != lastBtnState){
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != btnState) {
      btnState = reading;
      
      if (btnState == HIGH) {
        cout++;
        setDisplayTo(show[cout]);
        if (cout >= MAXCOUT){
          cout = 0;
          setDisplayTo(show[cout]);
        }
      }
    }
  }

  lastBtnState = reading;
}

void setDisplayTo(int numb) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, numb);
  digitalWrite(latchPin, HIGH);
}

