#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define I2C_ADDRESS   0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

TaskHandle_t TaskOLED;

void TaskOLED_Display(void *pvParameters) {
  Wire.begin(6, 7);  
  if (!display.begin(SSD1306_SWITCHCAPVCC, I2C_ADDRESS)) {
    Serial.println(F("OLED tidak terdeteksi!"));
    vTaskDelete(NULL);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  while (true) {
    display.clearDisplay();
    display.setCursor(0, 10);
    display.println("Hello from Core 1!");
    display.display();

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Menjalankan OLED di Core 1...");

  xTaskCreatePinnedToCore(TaskOLED_Display, "TaskOLED", 4096, NULL, 1, &TaskOLED, 1);
}
