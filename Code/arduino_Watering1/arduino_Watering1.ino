int IN1 = 2;
int Pin1 = A0; 
float value1 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  
  digitalWrite(IN1, HIGH);
  delay(500);
}
void loop() {
  Serial.print("MOISTURE LEVEL:");
  value1 = analogRead(Pin1);
  Serial.println(value1);
  if(value1>750)
  {
      digitalWrite(IN1, LOW);
  }
  else
  {
    digitalWrite(IN1, HIGH);
    }
    Serial.println();
  delay(1000);
}
