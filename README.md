# Oled Display Video Player
Oled Display Video Player (128x32 128x64 minioled display video player)
<img width="977" height="736" alt="Ekran görüntüsü 2025-09-06 010759" src="https://github.com/user-attachments/assets/ac11bea8-76e6-44f3-951d-af2d3423f40d" />
<!--<img width="980" height="736" alt="Ekran görüntüsü 2025-09-06 010541" src="https://github.com/user-attachments/assets/0c460dec-d323-41ac-a817-f369d9752f33" />-->


Bu proje, bilgisayardan seçilen bir videoyu **OpenCvSharp** kullanarak işleyip seri port üzerinden mikrodenetleyiciye (Arduino vb.) gönderen bir **WPF uygulamasıdır**. Uygulama, videoyu belirli boyuta ölçekler, siyah-beyaz formatına dönüştürür ve OLED/LED ekranlarda gösterilebilecek şekilde byte dizisine çevirir.

---

## 🚀 Özellikler

- 🎬 Video dosyası seçme veya sürükle-bırak ile ekleme
- 🖼️ Canlı ön izleme (işlenen kareleri WPF penceresinde gösterir)
- ⚡ Dinamik threshold ile farklı ışık koşullarında daha net görüntü
- 🔄 Seri port üzerinden kare bazlı veri gönderme
- 💾 İsteğe bağlı işlenmiş kareleri PNG olarak `frames_out` klasörüne kaydetme
- 🔌 Bağlantı kontrolü (seri port bağlanmadan işlem başlamaz)

---

## 🛠️ Kullanılan Teknolojiler

- **.NET WPF (C#)**
- [OpenCvSharp4](https://github.com/shimat/opencvsharp) (video işleme)
- **System.IO.Ports** (seri iletişim)
- **MVVM benzeri yapı**:  
  - `SerialManager.cs` → Seri port bağlantısı yönetimi  
  - `VideoManager.cs` → Video işleme ve gönderme yönetimi  

---

## ⚙️ Kurulum
 ```bash
1. Bu repoyu klonlayın veya indirin.
2. Visual Studio ile açın.
3. NuGet paketlerini yükleyin:
  
   Install-Package OpenCvSharp4
   Install-Package OpenCvSharp4.runtime.win


4. Uygulamayı build edin.
````
---

## ▶️ Kullanım

1. **Seri port bağlanın**: Port seçip “Bağlan” butonuna basın.
2. **Video seçin**:

   * Dosya seçme butonuyla
   * Veya sürükle-bırak ile
3. **Başlat** butonuna basın.

   * Uygulama kareleri işler ve seri porta gönderir.
   * Aynı zamanda ön izlemede işlenen kareyi görebilirsiniz.

---

## 🔧 Geliştirme Notları

* Video boyutu şu an sabit: **128x64 piksel**
* FPS: **8 kare/sn**
* Başlangıç paketleri: `0xAA 0x55`
* Byte dizisi OLED/LED sürücünüzün beklediği formata göre düzenlenmiştir.

---

## 📜 Lisans


---
