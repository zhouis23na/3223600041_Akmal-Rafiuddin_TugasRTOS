**Nama  :** Akmal Rafiuddin  
**NRP   :** 3223600041  
**Kelas :** 3 - D4 Teknik Komputer B  

---

## 📌 Deskripsi Tugas
Tugas ini bertujuan untuk:
1. **Menghubungkan semua peripheral ke ESP32.**  
2. **Membuat program untuk setiap I/O (Input/Output) secara terpisah.**  
3. **Menjalankan masing-masing I/O pada core yang berbeda** menggunakan fitur **dual-core ESP32 (Core 0 & Core 1)**.  
4. **Mendokumentasikan langkah percobaan** dengan gambar dan video, lalu menampilkan hasilnya di GitHub.

---

## ⚙️ Daftar Peripheral yang Digunakan
| No | Peripheral | Fungsi | Jenis I/O | Core yang Digunakan |
|----|-------------|---------|------------|---------------------|
| 1 | Oled | Menampilkan String atau nilai pembacaan | Output | Core 0 & Core 1 |
| 2 | LED | Indikator visual | Output | Core 0 & Core 1 |
| 3 | Buzzer | Menghasilkan bunyi sebagai alarm | Output | Core 0 & Core 1 |
| 4 | Push Button | Input kontrol manual dari user | Input | Core 0 & Core 1 |
| 5 | Potensiometer | Mengatur nilai analog | Input (ADC) | Core 0 & Core 1 |
| 6 | Encoder | Membaca posisi atau arah rotasi | Input digital | Core 0 & Core 1 |
| 7 | Stepper | Menggerakkan aktuator dengan kontrol langkah presisi | Output (PWM / GPIO) | Core 0 & Core 1 |
| 8 | Servo | Mengatur posisi sudut rotasi dengan sinyal PWM | Output (PWM) | Core 0 & Core 1 |

---

## 🔌 Langkah Percobaan

### 1. Persiapan Alat & Bahan
- ESP32 DevKit
- LED, Resistor 220Ω
- Push Button
- Buzzer
- Potensiometer
- Sensor Ultrasonik HC-SR04
- LCD I2C 16x2
- Breadboard & Kabel Jumper

### 2. Wiring Rangkaian
Berikut untuk wiring rangkaian: [Wiring rangkaian](https://drive.google.com/drive/folders/1QMOnyjjpayXEKps25HIhpetXByf-lNgA?usp=sharing)


### 3. Build dan Upload Program
1. Buka **Arduino IDE atau VS Code dengan PlatformIO**
2. Tuliskan program di Arduino IDE atau VS Code
3. Pilih board: **ESP32 Dev Module**
4. Pilih port COM yang sesuai 
5. Upload program ke ESP32

### 4. Hasil Pengujian
- Setiap peripheral berjalan **di core berbeda**
- LED dan LCD dikendalikan oleh **Core 0**
- Buzzer, potensiometer, dan sensor ultrasonik dikendalikan oleh **Core 1**
- Semua task berjalan **secara paralel (multitasking)** menggunakan RTOS bawaan ESP32 (FreeRTOS)

---

## 🎥 Dokumentasi Percobaan
Video hasil percobaan terdapat pada link berikut: [Video hasil percobaan](https://drive.google.com/drive/folders/1GL3IrCreWmmQWdM-XVMECljDturs_isI?usp=sharing)

---

## 🧵 Catatan Tambahan
- Semua task dijalankan menggunakan `xTaskCreatePinnedToCore()` untuk memanfaatkan dual-core ESP32.
- Setiap I/O diatur agar tidak saling mengganggu proses di core lainnya.

---

## 🏁 Kesimpulan
Pada beberapa percobaan yang telah saya lakukan, ESP32 berhasil mengoperasikan beberapa peripheral secara **paralel dan terdistribusi pada dua core**, menunjukkan kemampuan **real-time multitasking** yang efisien menggunakan **FreeRTOS**.

---
