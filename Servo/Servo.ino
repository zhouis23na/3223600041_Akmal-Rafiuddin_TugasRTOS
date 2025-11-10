#include <ESP32Servo.h>

Servo myServo;
TaskHandle_t ServoTaskHandle;

void ServoTask(void *pvParameters) {
  for (;;) {
    myServo.write(0);
    vTaskDelay(pdMS_TO_TICKS(2000));  

    myServo.write(90);
    vTaskDelay(pdMS_TO_TICKS(1000));

  }
}

void setup() {
  myServo.attach(5, 500, 2500);  

  xTaskCreatePinnedToCore(ServoTask, "ServoTask", 2048, NULL, 1, &ServoTaskHandle, 1  
  );
}

void loop() {
}