/*
 예제 9.1
 피에조 부저를 이용한 소리 출력  
*/

int buzzerPin = 9;
int songLength = 16;

const int inputPin1=2;
const int inputPin2=3;
const int inputPin3=4;


// 노래 데이터, 공백은 쉬는 구간을 나타낸다
// 음계: 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'
char notes[] = "cee egg dff abb ";
// 음의 길이, 노래 데이터와 맞춰 음의 길이를 설정한다.
int beats[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

// 노래의 빠르기를 설정한다.
int tempo = 200;

void setup() 
{
  // 부저핀을 출력으로 설정한다
  pinMode(buzzerPin, OUTPUT);
  pinMode(inputPin1, INPUT_PULLUP);
  pinMode(inputPin2, INPUT_PULLUP);
  pinMode(inputPin3, INPUT_PULLUP);
}


void loop(){
 if(digitalRead(inputPin1) == LOW){        //첫번째 키가 눌리면
    tone(buzzerPin, 262);                     //음계 '도'에 해당하는 음 재생 
  }
  else if(digitalRead(inputPin2) == LOW){  //두번째 키가 눌리면
    tone(buzzerPin, 330);                     //음계 '미'에 해당하는 음 재생 
  }
  else if(digitalRead(inputPin3) == LOW){   //세번째 키가 눌리면
    tone(buzzerPin, 392);                     //음계 '솔'에 해당하는 음 재생
  }
  else{
    noTone(buzzerPin);                        //버튼이 안눌러면 음 재생 중지
  }
}