/*
 예제 3.2
 I2C를 이용한 LCD 출력
*/

// I2C 통신 라이브러리 설정
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정 PCF8574:0x27, PCF8574A:0x3F
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address:0x27, 16X2 LCD, 0x3F



  const int inputPin = 2;
  long startTime = 0;
  long swCountTimer = 0;
  void setup() {

  
    pinMode(inputPin, INPUT_PULLUP);
    Serial.begin(9600);
    lcd.init();
    lcd.clear();
    lcd.backlight();
    delay(250);
    
  }
  
 

   
  



  // Open Serial Monitor, Type to display 표시
  

  


void loop()
{
  // 시리얼 통신 수신 값이 있을 때
  if (digitalRead(inputPin)==LOW) {	
    
    startTime = millis();
    while(digitalRead(inputPin)==LOW);
     // 커서를 좌측 상단으로
    swCountTimer = millis()-startTime;
    // "Message from PC" 출력
    delay(100);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AR02 time span");
    lcd.setCursor(0,1);
    lcd.print(swCountTimer);
    lcd.print(" ms");

    
    
  };
}
