#define BUZZER_PIN 9

TaskHandle_t TaskBuzzer; 

void TaskBuzzerTone(void *pvParameters) {
  pinMode(BUZZER_PIN, OUTPUT);

  while (true) {
    tone(BUZZER_PIN, 1000);               
    vTaskDelay(300 / portTICK_PERIOD_MS); 

    tone(BUZZER_PIN, 1500);             
    vTaskDelay(200 / portTICK_PERIOD_MS); 

    noTone(BUZZER_PIN);                  
    vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Menjalankan Buzzer di Core 0...");

 xTaskCreatePinnedToCore(TaskBuzzerTone, "TaskBuzzer", 4096, NULL, 1, &TaskBuzzer, 0
 );
}

void loop() {
  Serial.println("Loop utama berjalan di core lain...");
  delay(1000);
}
