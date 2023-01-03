// Define pins for the relay module control pins
const int IN1 = 2; // For Pump 1
const int IN2 = 3; // For Pump 2
const int IN3 = 4; // For Pump 3
const int IN4 = 5; // For Pump 4

// Define pins for input for each moisture sensor
const int Pin1 = A0; // For Sensor 1
const int Pin2 = A1; // For Sensor 2
const int Pin3 = A2; // For Sensor 3
const int Pin4 = A3; // For Sensor 4

// CHANGE ME - Define thresholds for each moisture sensor. This will depend on how moist the soil needs to be for your particular plant. Calibrate EACH sensor.
float THRESHOLD1 = 750; // For Sensor 1
float THRESHOLD2 = 750; // For Sensor 2
float THRESHOLD3 = 750; // For Sensor 2
float THRESHOLD4 = 750; // For Sensor 2

void setup() {
  Serial.begin(9600);
  
  // Set output pins as outputs
  pinMode(IN1, OUTPUT); // For Pump 1
  pinMode(IN2, OUTPUT); // For Pump 2
  pinMode(IN3, OUTPUT); // For Pump 3
  pinMode(IN4, OUTPUT); // For Pump 4
  
  // Set input pins as inputs
  pinMode(Pin1, INPUT); // For Sensor 1
  pinMode(Pin2, INPUT); // For Sensor 2
  pinMode(Pin3, INPUT); // For Sensor 2
  pinMode(Pin4, INPUT); // For Sensor 2
  
  // Set output pins to high initially. HIGH = OFF ; LOW = ON
  digitalWrite(IN1, HIGH); // For Pump 1
  digitalWrite(IN2, HIGH); // For Pump 2
  digitalWrite(IN3, HIGH); // For Pump 3
  digitalWrite(IN4, HIGH); // For Pump 4
  delay(500);
}

void loop() {
  // Read values from moisture sensors
  float value1 = analogRead(Pin1);
  float value2 = analogRead(Pin2);
  float value3 = analogRead(Pin3);
  float value4 = analogRead(Pin4);
  
  // Check value from moisture sensor 1 and control output accordingly
  Serial.print("MOISTURE LEVEL on pin ");
  Serial.print(Pin1);
  Serial.print(": ");
  Serial.println(value1);
  if (value1 > THRESHOLD1) {
    digitalWrite(IN1, LOW);
  } else {
    digitalWrite(IN1, HIGH);
  }
  
  // Check value from moisture sensor 2 and control output accordingly
  Serial.print("MOISTURE LEVEL on pin ");
  Serial.print(Pin2);
  Serial.print(": ");
  Serial.println(value2);
  if (value2 > THRESHOLD2) {
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN2, HIGH);
  }
  
  // Check value from moisture sensor 3 and control output accordingly
  Serial.print("MOISTURE LEVEL on pin ");
  Serial.print(Pin3);
  Serial.print(": ");
  Serial.println(value3);
  if (value3 > THRESHOLD3) {
    digitalWrite(IN3, LOW);
  } else {
    digitalWrite(IN3, HIGH);
  }
  
  // Check value from moisture sensor 4 and control output accordingly
  Serial.print("MOISTURE LEVEL on pin ");
  Serial.print(Pin4);
  Serial.print(": ");
  Serial.println(value4);
  if (value4 > THRESHOLD4) {
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN4, HIGH);
  }
  
  Serial.println();
  delay(3600000); //Wait 1 hour before checking the sensors again.
}
