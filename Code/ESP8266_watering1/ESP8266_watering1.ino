int HUMI = 4; 
int sense_Pin = 0; //模拟引脚A0连接传感器输入

float value = 0;
void setup() {
  Serial.begin(9600);
  pinMode(HUMI, OUTPUT);
  pinMode(sense_Pin, INPUT);
  digitalWrite(HUMI, HIGH);
  delay(500);
}
void loop() {

  Serial.print("MOISTURE LEVEL:");
  value = analogRead(sense_Pin);
  Serial.println(value);
  if(value>750)
  {
      digitalWrite(HUMI, LOW);
  }
  else
  {
    digitalWrite(HUMI, HIGH);
    }
  delay(1000);
}
