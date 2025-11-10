#define LED1 13
#define LED2 16
#define BUTTON 17

bool state = false; 
TaskHandle_t TaskButton; 

void TaskPushButton(void *pvParameters) {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  while (true) {
    if (digitalRead(BUTTON) == LOW) { 
      state = !state; 
      digitalWrite(LED1, state);
      digitalWrite(LED2, !state);
      vTaskDelay(300 / portTICK_PERIOD_MS);  
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Menjalankan PushButton di Core 1...");

 xTaskCreatePinnedToCore(TaskPushButton, "TaskButton", 4096, NULL, 1, &TaskButton, 1);
}

void loop() {
  Serial.println("Loop utama berjalan...");
  delay(1000);
}
