#define ONBOARD_LED 2

void setup() {
  pinMode(ONBOARD_LED, OUTPUT);
  Serial.begin(115200); // Open the serial port at 115200 bps
  Serial.write("connected");
  
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read(); // Read the received character

    if (receivedChar == '1') {
      digitalWrite(ONBOARD_LED, HIGH); // Turn the LED on
      Serial.write(receivedChar);
      delay(1000);
    } else {
      digitalWrite(ONBOARD_LED, LOW); // Turn the LED off
      Serial.write(receivedChar);
    }
  }
}

