#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  

const int LM35Pin = 0;
const int CdSPin = 1;

void setup() {
  
  // 16X2 LCD 모듈 설정하고 백라이트를 켠다.
  lcd.init(); // LCD 설정
  lcd.backlight();

  // 메세지를 표시한다.
  lcd.print("ex 6.3");
  lcd.setCursor(0,1);
  lcd.print("Checking Temp.");
      
  // 3초동안 메세지를 표시한다.
  delay(3000);

  // 모든 메세지를 삭체한 뒤
  // 숫자를 제외한 부분들을 미리 출력시킨다.

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Illuminance: ");
  lcd.setCursor(0,1);
  lcd.print("Temp. is");

  //LCD 문자표에서 '°' 기호를 직접 써준다
  lcd.setCursor(13,1);
  lcd.write(B11011111);
  lcd.setCursor(14,1);
  lcd.print("C");
   
}

void loop(){
  int adcValue1; // 실제 센서로부터 읽은 값 (0~1023)
  int adcValue2;
  int illuminance;
  long temp; // 현재의 온도
    

  adcValue1 = analogRead(CdSPin);
  adcValue2 = analogRead(LM35Pin);
  illuminance = map(adcValue1, 0, 1023, 100, 0);
  temp = (adcValue2 * 500L) / 1023;


  lcd.setCursor(12,0);
  lcd.print("      "); 
  lcd.setCursor(12,0);
  lcd.print(illuminance);

  lcd.setCursor(10,1);
  lcd.print("   ");  
  lcd.setCursor(10,1);
  lcd.print(temp);
  delay(2000); 
}
