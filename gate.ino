/*
  Created by Maor Magori.
  This code presses a buttun on my gate remote.
*/
String command; // Command recieved by usb
#define buttonclick 7  // Pin 7 connected to Pin 13 of 4066 IC
int clickspeed = 200;  // Controls speed of button click

void setup() {
  Serial.begin(9600); 

  pinMode(buttonclick, OUTPUT);
  digitalWrite(buttonclick, LOW);

}

void loop() {

    if (Serial.available() > 0) {
      command = Serial.readStringUntil('\n');
  
      if (command == "open") {
        openGate();
      }
      if(command == "close") {
        closeGate();
      }
      else {
        Serial.write("Invalid command");
      }
    }
}

void openGate() {
  clickGateButton();
}

void closeGate(){
  clickGateButton();
  delay(clickspeed);
  clickGateButton();
}

void clickGateButton() {
  digitalWrite(buttonclick, HIGH);
  delay(clickspeed);
  digitalWrite(buttonclick, LOW);
}
