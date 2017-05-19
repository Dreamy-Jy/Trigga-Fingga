/* Trigga Fingga v.0.1
 *  
 *  This code just counts the amounts of 
 *  times a button has been pressed
 *  
 *  this code was inpart inspired by the debounce example
 */

//pins in use 
const int btnPin = 2;

//state trackers
int btnState;
int lastBtnState = LOW;

//press tracker
int cout = 0;
//timers
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
  pinMode(btnPin, INPUT);
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
        Serial.println(cout);
      }
    }
  }
/*  if (btnState != lastBtnState){
    if (btnState == HIGH){
      cout++;
      Serial.println(cout);
    } 
  }
*/  
  lastBtnState = reading;
}
