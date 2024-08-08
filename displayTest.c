#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS        5
#define TFT_RST       17
#define TFT_DC        16

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.init(240, 280); // Initialisiere mit der Displaygröße
  tft.setRotation(1); // Setze die Rotation falls nötig
  tft.fillScreen(ST77XX_BLACK); // Fülle den Bildschirm mit Schwarz
  tft.setTextColor(ST77XX_WHITE); // Setze die Textfarbe auf Weiß
  tft.setTextSize(2); // Setze die Textgröße
  tft.setCursor(10, 10); // Setze den Cursor auf Position (10, 10)
  tft.print("Hallo Welt!"); // Zeige den Text an
}

void loop() {
  // Hier kann weiterer Code hinzugefügt werden
}
