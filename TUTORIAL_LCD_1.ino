/*
   TUTORIAL LCD 1602 PADA ARDUINO
   MENGGUNAKAN I2C
   ---TEST FILE---

   Pinout LCD :
   SDA -> SDA
   SCL -> SCL
   VCC -> VCC
   GND -> GND
*/

#include <Wire.h>

#include <LiquidCrystal_I2C.h>
//set I2C address untuk Modul I2C LCD, beberapa modul menggunakan 0x3F atau 0x27

//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup()
{
  Serial.begin(115200);  // untuk penggunaan input serial monitor

  lcd.begin(16, 2);  // inisiasi lcd

  // ------- blink backlight 3x  -------------
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // nyalakan backlight

  //-------- Menulis karakter pada display LCD ------------------
  // NOTE: Posisi cursor : (KOLOM, BARIS) mulai dari 0
  lcd.setCursor(0, 0); //set cursor untuk mulai pada kolom 0 di baris 0
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0, 1); //set kolom 0 baris 1
  lcd.print("Helmi");

  delay(8000);

  lcd.clear(); //membersihkan layar
  lcd.setCursor(0, 0); 
  lcd.print("Use Serial Mon");
  lcd.setCursor(0, 1);
  lcd.print("Type to display");

}

//pada bagian loop, menangkap apa yang ditulis di seial monitor dan tampilkan ke lcd
void loop()
{
  if (Serial.available()) {//tunggu data dari input serial
    delay(100);
    lcd.clear();
    while (Serial.available() > 0) {
      lcd.write(Serial.read());//tulis ke lcd
    }
  }
}
