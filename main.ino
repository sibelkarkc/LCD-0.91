#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // 0.91 inç OLED genişlik
#define SCREEN_HEIGHT 32 // 0.91 inç OLED yükseklik

#define I2C_SDA 8
#define I2C_SCL 9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  
  // ESP32-S3 için I2C pinlerini başlat
  Wire.begin(I2C_SDA, I2C_SCL);

  // SSD1306 ekranı 0x3C adresinde başlat
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 ekran bulunamadi! Baglantilari kontrol et.");
    for (;;); // Hata varsa burada bekle
  }

  display.clearDisplay();
  display.setTextSize(2);              // Yazı boyutu
  display.setTextColor(SSD1306_WHITE); // Tek renkli (sarı) ekranda WHITE kullanılır
  display.setCursor(10, 8);            // Başlangıç koordinatı (x, y)
  display.println("IOT ATOLYESI");
  display.display();                   // Yazıyı ekrana yansıt
}

void loop() {
}
