#define ONBOARD_LED 2

const int bootButtonPin = 0;
bool buttonPressed = false;


void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.begin(115200); 
  Serial.write("connected");
  pinMode(bootButtonPin, INPUT_PULLUP); 
}

void loop() {
  if (digitalRead(bootButtonPin) == LOW) {
    if (!buttonPressed) {
      digitalWrite(ONBOARD_LED, HIGH);
      buttonPressed = true; 
    }
  } else {
    buttonPressed = false; 
    digitalWrite(ONBOARD_LED, LOW); 
  }

  
  if (Serial.available()) {
    char receivedChar = Serial.read(); 

    if (receivedChar == '1') {
      digitalWrite(ONBOARD_LED, HIGH); 
      Serial.write(receivedChar);
      delay(1000);
    } else {
      digitalWrite(ONBOARD_LED, LOW); 
      Serial.write(receivedChar);
    }
  }
}
