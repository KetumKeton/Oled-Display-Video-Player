//pyton v3 ile çalısır
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

#define LED_PIN 2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint8_t frameBuffer[1024];

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Hata varsa kilitlen
  }

  display.clearDisplay();
  display.display();

  // Açılışta kısa bir efekt
  display.invertDisplay(true);
  delay(100);
  display.invertDisplay(false);
  delay(100);
}

void loop() {

  // Başlangıç marker'ı (0xAA 0x55) bekle
  if (Serial.available() >= 2) {
    if (Serial.read() == 0xAA && Serial.read() == 0x55) {
      if(LED_PIN){
        digitalWrite(LED_PIN,LOW);
        }else{
          digitalWrite(LED_PIN,HIGH);
          }
      // Tam 1024 byte'ı al
      int count = 0;
      while (count < 1024) {
        if (Serial.available()) {
          frameBuffer[count++] = Serial.read();
        }
      }

      // Frame verisini direkt OLED buffer’a kopyala
      memcpy(display.getBuffer(), frameBuffer, 1024);

      // Ekranı güncelle
      display.display();
    }
  }
}
