
//  pins
const int buzzrPin = 8;
const int butnPin = 7;

// states
int buzzrState = LOW;
int butnState = LOW;
int lastButnState = LOW;



void setup() {
  // put your setup code here, to run once:
  pinMode(buzzrPin, OUTPUT);
  pinMode(butnPin, INPUT);
  Serial.begin(9600);
  playSound();
}

void loop() {
  // put your main code here, to run repeatedly:
  butnState = digitalRead(butnPin);

  if (butnState != lastButnState) {
    if (butnState == HIGH) {
      Serial.println("pressed");
      playSound();
    } else {
      Serial.println("not pressed should hear no sound");
    }

    delay(50);
  } else {
    Serial.println("not pressed should hear no sound");
  }

  lastButnState = butnState;

  
}

void playSound() {
  tone(buzzrPin,311);
  delay(1000);
  noTone(buzzrPin);
}
