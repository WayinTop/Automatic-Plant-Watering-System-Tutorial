const int pumpRelay[4] = { 2, 3, 4, 5 };
const int moistureSensor[4] = { A0, A1, A2, A3 };
const int ON = LOW;
const int OFF = HIGH;

// Lower = wetter, 275 = completely wet, 600 = completely dry
const int moistureThreshold[4] = { 400, 400, 400, 400 };  // Adjust to each plant's needs

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 4; i++) {
    pinMode(pumpRelay[i], OUTPUT);
    digitalWrite(pumpRelay[i], OFF);  
    pinMode(moistureSensor[i], INPUT);
  }
  
  delay(500);
}

void loop() {
  int moistureLevel;  
  
  for(int i = 0; i < 4; i++) {
    moistureLevel = analogRead(moistureSensor[i]);

    Serial.print("MOISTURE LEVEL ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(moistureLevel);

    // If the soil is too dry, turn the pump on. 
    // Otherwise, turn the pump off
    if(moistureLevel > moistureThreshold[i]) {
      digitalWrite(pumpRelay[i], ON);
    } else {
      digitalWrite(pumpRelay[i], OFF);
    }
  }

  Serial.println();
  delay(1000);
}
