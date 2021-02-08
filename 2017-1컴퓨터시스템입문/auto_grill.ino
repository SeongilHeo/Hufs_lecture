include<Servo.h>
Servo myservo;
 
const int TMP36_pin = A0;//tmp
int led =8;
int push_sw =2;
void setup() 
{
   myservo.attach(12);
  pinMode(led, OUTPUT);
  pinMode(push_sw, INPUT);
  myservo.write(0);
  delay(1000);
}
void loop() {
  int sensorValue = analogRead(TMP36_pin);//pmp값 
  float mVoltage = sensorValue*50000.0/1024.0;
  float temp = (mVoltage -500)/10.0;
  int push_sw_state = digitalRead(push_sw);//버튼 상태
  Serial.println(push_sw_state);
  digitalWrite (led,push_sw_state);//버튼 누르면 led켜짐
   if(temp >= 60)//온도가 20도 이상
   {
      tone(7,1000,500);
       delay(1000);
       noTone(7);
   }
  delay(10000);
  digitalWrite(led,LOW);
   Serial.println(push_sw_state);
  if(push_sw_state == HIGH)
  {
    for(int i =0; i<=90; i+=10)
    {
      myservo.write(i);
    }
    delay(5000);
 }
  myservo.write(0);
 delay(1000);
}
