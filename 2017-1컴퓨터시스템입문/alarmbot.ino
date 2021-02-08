#include <gfxfont.h>
#include <Servo.h>//서보 모터 헤더 파일
#include <swRTC.h>//시간 측정 헤더 파일
#include <Wire.h>//I2C device를 이용할 수 있도록 만든 함수
#include <Adafruit_GFX.h>//OLED LCD 그래픽 헤더 파일
#include <Adafruit_SSD1306.h>//OLED LCD 128X64 헤더 파일 
#include "pitches.h"//음계 헤더 파일

int Canonmelody[] = {
    NOTE_G7, 0, NOTE_E7, NOTE_F7, NOTE_G7, 0, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_B6, NOTE_A6, NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_E7,0, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_G6
    , NOTE_F6, NOTE_G6, NOTE_C7, NOTE_B6, NOTE_C7, NOTE_A6, 0, NOTE_C7, NOTE_B6, NOTE_A6, 0, NOTE_G6, NOTE_F6, NOTE_G6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, NOTE_C7, NOTE_A6, 0, NOTE_C7, NOTE_B6, NOTE_C7, 0,
    NOTE_B6, NOTE_C7, NOTE_B6, NOTE_A6, NOTE_B6, NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7,
};//캐논 음계 함수

int noteDurations[] = {
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6
};//캐논 박자  함수

int buzzer = 8;//버저 핀 변수선언
int button = 2;//스위치 핀 변수 선언

class AlarmBot //알람봇 클래스 선언
{
public:
  Adafruit_SSD1306 *display; //Adafruit에서 제공하는 클래스의 포인터 객체를 선언해준다
  Servo servo1; //서보 모터1
  Servo servo2; //서보 모터2
  int servo1pin, servo2pin; //서보 모터 1, 2 가 연결된 핀
  AlarmBot(Adafruit_SSD1306 *_display, int _servo1pin, int _servo2pin) 
  //클래스의 생성자에서 멤버 변수들을 초기화해준다
  {
    display = _display; 
    servo1pin = _servo1pin;
    servo2pin = _servo2pin;
  };

  void init() //화면에 알람 로봇의 기본 얼굴이 나오게 하는 함수
  {
    display->begin(SSD1306_SWITCHCAPVCC);
    display->clearDisplay(); //화면을 클리어함
    display->drawLine(display->width() * 2 / 6, display->height() * 4 / 5, display->width() * 4 / 6, display->height() * 4 / 5, WHITE); 
    //얼굴을 그리기 위해 drawLine함수를 불러와 해당 함수에 인자들을 넣어줌으로써 선을 그린다
    eyeClose(); //미리 정의한 눈을 감는 모션을 화면에 출력하는 함수를 호출
    servo1.attach(servo1pin); //서보모터1 연결
    servo2.attach(servo2pin); //서보모터2 연결
    servo1.write(90); //서보 모터가 90도를 유지하도록한다
    servo2.write(90);
    _x = 0;
    _y = 0;
    delay(1000); //1초 딜레이
    servo1.detach();
    servo2.detach();
  }

  void eyeClose() //눈을 감는 모션을 화면에 출력하는 함수
  {
    for (int i = 0; i < 10; i+=2) //총 5번을 도는 반복문. 천천히 눈이 감기도록 하기 위해 써주었다.
    {
      display->drawRoundRect(display->width() * 1 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, WHITE); 
      //drawRoundRect함수를 이용하여 for문 한바퀴 돌 때마다 다른 인자를 넣어주어 천천히 감기는 눈을 구현
      display->drawRoundRect(display->width() * 4 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, WHITE);
      display->display(); //display()함수를 써주어야만 화면에 출력된다
      delay(30);
      display->drawRoundRect(display->width() * 1 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, BLACK); 
      //하얀 색으로 칠한 부분을 출력 후 검은색으로 덮어씌워 점점 감기는 눈을 구현하였다.
      display->drawRoundRect(display->width() * 4 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, BLACK);
    }
    display->drawLine(display->width() * 4 / 5 - 5, display->height() / 3, display->width() * 4 / 5 + 5, display->height() / 3, WHITE);
    //눈이 모두 감긴 이후에는 -_- 이 모양이 되므로 이 때는 눈을 선으로 나타낸다.
    display->drawLine(display->width() * 1 / 5 - 5, display->height() / 3, display->width() * 1 / 5 + 5, display->height() / 3, WHITE); 
    display->display();
    display->drawLine(display->width() * 4 / 5 - 5, display->height() / 3, display->width() * 4 / 5 + 5, display->height() / 3, BLACK); 
    //눈을 감은 얼굴을 출력한 뒤 다음 출력에서 다시 검은색으로 덮어씌워 다른 출력이 보일 수 있도록 한다.
    display->drawLine(display->width() * 1 / 5 - 5, display->height() / 3, display->width() * 1 / 5 + 5, display->height() / 3, BLACK); 
  }

  void eyeOpen() //눈을 뜨는 모션을 화면에 출력하는 멤버 함수. 
  {
    for (int i = 10; i >= 0; i-=2) //천천히 눈을 뜨는 모션을 보여주기 위해 for문을 이용하였다.
    {
      display->drawRoundRect(display->width() * 1 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, WHITE); 
      display->drawRoundRect(display->width() * 4 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, WHITE); //drawRoundRect함수에 인자를 for문을 한 번 돌 때마다 다른 인자를 넣어줌으로서 천천히 눈이 뜨는 모션을 보여줌
      display->display();
      delay(30);
      display->drawRoundRect(display->width() * 1 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, BLACK); //스탑 모션으로 눈이 떠지는 걸 구현하기 위해 흰색으로 출력한 부분에 검은색으로 덮어씌워
      display->drawRoundRect(display->width() * 4 / 5 - 5, display->height() / 3 - 10 + i , 11, 22 - i * 2, 5 - i/2, BLACK); //다음 스탑모션에서 더 큰 RoundRectangle을 그려 눈이 점점 떠지는 것 처럼 구현하였다.
    }
  }
  void Blink() //눈이 깜박이는 모션을 구현한 함수
  {
    eyeClose(); //우선 눈을 감고
    delay(300); //0.3초 딜레이 후
    eyeOpen(); //눈을 다시 뜬다
  }

  void See(int x, int y) //서보 모터를 움직여 x, y에 따라 쳐다보는 시선이 달라지도록 하는 함수
  {
    servo1.attach(servo1pin); //각 서보모터를 연결한다
    servo2.attach(servo2pin);
    while (_x != x || _y != y) 
    //init에서 초기화한 _x, _y를 바탕으로, x와 _x가 다르거나, y와 _y가 다를 경우
    //while문 조건을 만족하여 반복문이 돌게 된다.
    {
      servo1.write(90 + (x != _x ? (x < 0 ? _x-- : _x++) : _x)); 
      //while문 안에서 _x 와 _y값이 바뀌고, 이후 다시 while문 조건을 비교하는 식으로
      servo2.write(90 + (y != _y ? (y < 0 ? _y-- : _y++) : _y)); 
      //_x와 x, _y와 y사이의 값의 조정이 일어난다
      delay(100/((x>_x?x-_x:_x-x)+(y>_y?y-_y:_y-y)+1));
    }
    servo1.detach();
    servo2.detach();
  }

private: //클래스의 private변수 _x, _y
  int _x = 0; 
  int _y = 0;
};

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);//SSD 1306 OLED LCD 전원 공급을 위한 함수 실정 
swRTC rtc;//시간함수 시작

AlarmBot AlarmBot(&display, 6, 7);

void setup() //Set-up 함수
{
  Serial.begin(9600);//전력량 공급

  display.begin();//OLED LCD 사용 설정
  display.clearDisplay();
  display.setTextSize(2);//텍스트 크기 설정
  display.setTextColor(WHITE);//LED 색 하얀색으로 설정

  pinMode(buzzer, OUTPUT);//버저 출력 인자로 설정
  pinMode(button, INPUT_PULLUP);//스위치: 풀업 저항 설정(Swith on: LOW, Switch off: HIGH)
  AlarmBot.init();
  delay(1000);
  AlarmBot.eyeOpen();//초기설정: 알람봇 display 상태(깨어있음)
  delay(1000);
}

void Set_lowThanTen(int time) {//흘러간 시간 측정함수
  display.setTextSize(2);//텍스트 크기 설정-2
  if(time < 10) {
    display.print("0");
    display.display();
    display.print(time%10);
    display.display();
  }
  else{
    display.print(time);
    display.display();}
}

void loop() 
{ 
  rtc.stopRTC();         //정지
  rtc.setTime(0,0,0);    //시간, 분, 초 초기화
  rtc.startRTC();        //시간 측정 시작
  int analogInput = analogRead(A0);//가변 저항 값을 analogRead 함수를 이용하여 analogInput 변수에 저장
  int minute;// minute 변수 선언-가변 저항을 통해 설정한 타이머 시간을 받아준다
  
  if((analogInput/34) > 0){//analogInput값을 34로 나눠 0~30까지 값을 만들수있도록 조정하였다.
    display.clearDisplay();
    while(1){
      analogInput = analogRead(A0);
      //가변 저항 값을 analogRead 함수를 이용하여 analogInput 변수에 저장
      //-while문을 이용해 가변저항이 변할때 마다 값을 출력할 수 있도록 설계
      display.setCursor(58,5);//출력 위치 설정
      display.setTextSize(2);//텍스트 크기 설정-2
      display.println(analogInput / 34);//analogInput을 34로 나눈 값을 출력
      display.setCursor(45,20);//출력 위치 설정
      display.setTextSize(1);//텍스트 크기 설정-1
      display.print("minutes");//minute 출력
      display.display();
      if(digitalRead(button)==LOW){//Switch-On이 되면 타이머 작동: while루프 break
        display.clearDisplay();
        minute = analogInput/34;//minute변수에 설정한 타이머 값 저장
        break;
      }
      display.clearDisplay();
    }

    AlarmBot.eyeClose();//알람봇 상태: 수면
    AlarmBot.See(0, 30);

    rtc.setTime(0,0,0);
    while(1){         
      display.setCursor(17,8);//1마이크로초 마다 현재시간을 LCD에 출력(위치 17,8)
      Set_lowThanTen(rtc.getHours());//흘러간 '시간' 출력 
      display.print(":");
      display.display();
      Set_lowThanTen(rtc.getMinutes());//흘러간 '분' 출력 
      display.print(":");
      display.display();
      Set_lowThanTen(rtc.getSeconds());//흘러간 '초' 출력

      display.clearDisplay();

      if(minute == rtc.getMinutes()){//타이머 음악 출력-'캐논 변주곡'
        for (int Note = 0; Note < 64; Note++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(8, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(8);
        }
        delay(1000);
        break;
      }
    }
    AlarmBot.init();
    AlarmBot.See(60, -50);
    AlarmBot.Blink();
    delay(1000);
    AlarmBot.See(-60, -50);
    delay(500);
    //깬 알람봇 좌우로 움직인다.
    AlarmBot.See(0, 0);
  }
  //깨어있는동안은 눈을 깜빡인다.
  AlarmBot.Blink();
  delay(4000);
}
