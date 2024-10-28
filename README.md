# ESP32 microcontroller to the Led Strip WS3231

This program is designed to check the communication between an ESP32 with WS3231.

## Installation
Untuk menjalankan ESP32 pada Visual Studio Code (VSCode) dengan PlatformIO, Anda dapat mengikuti langkah-langkah berikut:

- _Install PlatformIO Extension_
Pastikan Anda telah menginstal ekstensi PlatformIO pada VSCode. Anda dapat menginstalnya dari Marketplace VSCode.
- _Buat Proyek Baru_
Buka VSCode, buka menu PlatformIO, dan pilih "New Project". Pilih board "ESP32" dan pilih framework yang ingin Anda gunakan (misalnya, Arduino, ESP-IDF).
- _Konfigurasi PlatformIO_
Setelah membuat proyek, buka file platformio.ini di proyek Anda dan pastikan konfigurasi board, framework, dan port serial telah benar.
- _Tulis Kode_
Tulis kode program ESP32 Anda dalam file src/main.cpp atau file lainnya sesuai kebutuhan.
- _Kompilasi dan Upload_
Gunakan menu PlatformIO atau shortcut keyboard untuk kompilasi _(Ctrl+Alt+B)_ dan upload program ke ESP32 _(Ctrl+Alt+U)_.
- _Monitor Serial_
Setelah upload selesai, Anda dapat membuka monitor serial untuk melihat output dari ESP32. Gunakan menu PlatformIO atau shortcut keyboard _Ctrl+Alt+M_.

Dengan mengikuti langkah-langkah di atas, Anda dapat menjalankan program ESP32 Anda pada VSCode menggunakan PlatformIO dengan mudah. Jika Anda mengalami masalah atau membutuhkan bantuan tambahan, jangan ragu untuk bertanya!

### Usage
- Connect the ESP32 microcontroller to the Led Strip WS3231
- Upload the program to the ESP32 using PlatformIO.
- Open the serial monitor to view the communication status.
- The program will perform a single reading from the sensor and display the temperature and humidity values.
- Once the reading is complete, the program will send a message indicating that the data is no longer being read.

### Contributing
Contributions to this project are welcome. Feel free to fork the repository and submit pull requests.

### License
This project is licensed under the MIT License - see the LICENSE file for details.

### Contact
For any questions or feedback regarding this project. 
Please contact sangapanpanjaitan@gmail.com


**Free Software, Hell Yeah!**
