// Arduino Master HC-05 Code

int joystickX = A0;  // X-axis of joystick connected to A0
int joystickY = A1;  // Y-axis of joystick connected to A1

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);  // Default baud rate for HC-05
}

bool flash = false;
void loop() {
  int xValue = analogRead(joystickX); // Read X-axis for servo control
  int yValue = analogRead(joystickY); // Read Y-axis for ESC control
  
  if (yValue < 550) {
    yValue = 550;
  }
  
  int angle = map(xValue, 0, 1023, 0, 180);  // Map Y-axis to ESC speed (0-180 range)  // Map X-axis to servo angle
  int speed = map(yValue, 550, 1023, 90, 180);  // Map Y-axis to ESC speed (0-180 range)
  Serial.write(255);
  delay(25);
  Serial.write(angle);
  delay(25);
  Serial.write(254);
  delay(25);
  Serial.write(speed);
  delay(25);

  flash = !flash;
  if (flash) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
    
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
}
