#define LED1 4
#define LED2 5
#define LED3 8

TaskHandle_t TaskBlink;  

void TaskBlinkLED(void *pvParameters) {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  while (true) {
    digitalWrite(LED1, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED1, LOW);

    digitalWrite(LED2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED2, LOW);

    digitalWrite(LED3, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED3, LOW);

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Menjalankan Blink LED di Core 0...");

 xTaskCreatePinnedToCore(TaskBlinkLED, "TaskBlink", 4096, NULL, 1, &TaskBlink, 0);
}

void loop() {
  Serial.println("Loop utama berjalan di core lain...");
  delay(1000);
}
