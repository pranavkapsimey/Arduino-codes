/*#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 33, 34);

int x = 128;  // start from right side

void setup() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB10_tr);
}

void loop() {
  u8g2.clearBuffer();
  u8g2.drawStr(x, 35, "PRANAV IS GOD");
  u8g2.sendBuffer();

  x--;  // move text left

  if (x < -120) x = 128;  // reset back to right when fully gone

  delay(10);
}*/
#include <U8g2lib.h>
#include <Wire.h>
#include <stdlib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 33, 34);

int x = 64, y = 32;
int speedX = rand()%10, speedY = 2;
int size = 12;  // square size

void setup() {
  u8g2.begin();
}

void loop() {
  x += speedX;
  y += speedY;
  
  // bounce off walls
  if (x <= 0 || x + size >= 128) speedX = -speedX;
  if (y <= 0 || y + size >= 64)  speedY = -speedY;

  u8g2.clearBuffer();
  u8g2.drawFrame(0, 0, 128, 64);   // border
  u8g2.drawBox(x, y, size, size+3);  // square
  u8g2.sendBuffer();

  delay(20);
}