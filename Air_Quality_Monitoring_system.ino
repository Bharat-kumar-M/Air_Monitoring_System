#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop(){
  delay(50);
  int value=analogRead(A0);

  lcd.setCursor(0,0);
  lcd.print("Air quality=");
  lcd.print(value);
  Serial.println(value);

  if(value<100){
    lcd.setCursor(0,0);
    lcd.print("Air quality=");
    lcd.print(value);
    lcd.print("  ");
    lcd.setCursor(1,1);
    lcd.print("Excellent");
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  else if(value<=150){
    lcd.setCursor(1,1);
    lcd.print("Excellent   ");
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  else if(value<=250){
    lcd.setCursor(1,1);
    lcd.print("Good        ");
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  else if(value<=450){
    lcd.setCursor(1,1);
    lcd.print("Moderate    ");
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  }
  else if(value>450 && value<=700){
    lcd.setCursor(1,1);
    lcd.print("Poor !      ");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
  }
  else if(value>700 && value<1000){
    lcd.setCursor(1,1);
    lcd.print("Harmful !!  ");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
  }
  else{
    lcd.setCursor(1,1);
    lcd.print("Dangerous !!");
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
  }

}
