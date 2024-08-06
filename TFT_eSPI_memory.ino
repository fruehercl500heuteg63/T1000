
#include <SPI.h>
#include <TFT_eSPI.h>
// Load GIF library
#include <AnimatedGIF.h>
AnimatedGIF gif;

// Example AnimatedGIF library images
#include "mblogo100x100.h"

#define SCLK_PIN GPIO_NUM_18
#define MOSI_PIN GPIO_NUM_23

#define DC_PIN GPIO_NUM_16
#define CS_PIN GPIO_NUM_5
#define RST_PIN GPIO_NUM_17

//Color definitions 
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define Green   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


TFT_eSPI tft = TFT_eSPI();

#define imageWidth 100
#define imageHeight 100

#define GIF_IMAGE mblogo100x100

#define NORMAL_SPEED

void setup(void) {
  Serial.begin(115200);
  Serial.println("ESP32 is starting up");

  Serial.println("TFT screen initialising");
  tft.begin();

  #ifdef USE_DMA
  tft.initDMA();
  #endif

  tft.fillScreen(BLACK);
  gif.begin(BIG_ENDIAN_PIXELS);

  Serial.println("Image has been rendered onto screen");
}

void loop()
{
  // Put your main code here, to run repeatedly:
  if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw))
  {
    Serial.printf("Successfully opened GIF; Canvas size = %d x %d\n", gif.getCanvasWidth(), gif.getCanvasHeight());
    tft.startWrite(); // The TFT chip select is locked low
    while (gif.playFrame(true, NULL))
    {
      yield();
    }
    gif.close();
    tft.endWrite(); // Release TFT chip select for other SPI devices
  }
}

