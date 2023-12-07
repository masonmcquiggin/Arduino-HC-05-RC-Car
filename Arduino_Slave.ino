// Arduino Slave Module Code

#include <Servo.h>
Servo myservo; // Create servo object
Servo esc; // Create ESC object
int servoPin = 9; // Servo connected to pin 9
int escPin = 10; // ESC connected to pin 10

void setup() {
  myservo.attach(servoPin); // Attach the servo on pin 9
  esc.attach(escPin); // Attach the ESC on pin 10
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Default baud rate for HC-05
}

bool flash = true;
void loop() {
  if (Serial.available() >= 2) {
    if (flash) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
    flash = !flash;

    int task = Serial.read();
    Serial.print("Received task: ");
    Serial.println(task);
    if (task == 255) {
      int angle = Serial.read(); // Read angle value for servo
      myservo.write(angle); // Set servo position
      Serial.print("Servo target: ");
      Serial.println(angle);
    } else if (task == 254) {
      int speed = Serial.read(); // Read speed value for ESC
      esc.write(speed); // Set ESC speed
      Serial.print("Motor speed: ");
      Serial.println(speed);
    }
  }
}
