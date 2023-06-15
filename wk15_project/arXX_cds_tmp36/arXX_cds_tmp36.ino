//  temperature & lux

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define TMP36_INPUT 0
#define CDS_INPUT 1
LiquidCrystal_I2C lcd(0x27,16,2);  

Servo motor1;

int led1 = 2;
int led2 = 3;
int buzzerPin = 4;
int servoMotorPin = 5;

int motorAngle;
int motorAngleOld;

void setup() {
  motor1.attach(servoMotorPin,600,2400);
  Serial.begin(9600);  
  pinMode(buzzerPin,OUTPUT);
  lcd.init();     // LCD 설정
  lcd.backlight();
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Illuminance:");
  lcd.setCursor(0,1);
  lcd.print("Temp. is ");

  //LCD 문자표에서 '°' 기호를 직접 써준다
  lcd.setCursor(13,1);
  lcd.write(B11011111);
   
   // '°' 기호 문자코드
  lcd.setCursor(14,1);  
  lcd.print("C");  // 'C'를 표시한다.
}

void loop() {
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting that reading to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));

  motorAngle = map(tempC,15,35,0,180);
  motor1.write(motorAngle);
//  Serial.print("ARnn,");
  Serial.print(tempC);
  Serial.print(",");
  Serial.println(lux);

  lcd.setCursor(12,0);
  lcd.print("    "); 
  // ADC 값을 표시한다  
  lcd.setCursor(12,0);
  lcd.print(lux);

  // 전에 표시했던 내용을 지운다.  
  lcd.setCursor(10,1);
  lcd.print("   ");
  // 온도를 표시한다  
  lcd.setCursor(10,1);
  lcd.print(tempC);

  if (tempC <= 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  if(lux >100){
    Melody();
  }

  
  delay(1000);
}
void Melody() {
  tone(buzzerPin, 523);  // 도
  delay(200);
  tone(buzzerPin, 587);  // 레
  delay(200);
  tone(buzzerPin, 659);  // 미
  delay(200);
  noTone(buzzerPin);
  delay(200);
}
//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10.0;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}

