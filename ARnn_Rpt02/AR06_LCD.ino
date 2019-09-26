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

int blinkNumber = 0;

 void setup()
{
  // 9600 bps로 시리얼 통신 설정
  Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.  
  delay(500);

}

void loop() {
 
// 시리얼 통신으로 입력 받은 데이터가 있는지를 검사하여
// 데이터가 있을 경우에 if문 안의 명령어를 실행
  if(Serial.available()){    
     char val = Serial.read();
    
    // 입력된 값이 0~9의 숫자인지를 판단
    if(isDigit(val)){
     // val은 ASCII 코드값이므로 숫자로 바꿔주기 위하여 
     // '0'의 아스키 코드값을 빼줌
     // blinkNumber에는 실제 숫자가 저장된다.
      blinkNumber = (val - '0');
    }   
  // val 변수에 시리얼 통신값 읽어오기
  lcd.setCursor(0,0);

  lcd.write(Serial.read()); 

  
  }
  
  

for(char i=0;i < blinkNumber;i++){
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
  
}
blinkNumber = 0;
}


