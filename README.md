[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/DefVEV21)
## Kasus: Analisis Nilai Mahasiswa

Anda diminta membuat beberapa program C yang akan membantu menganalisis nilai tugas mahasiswa.

Setiap program akan membaca `n + 1` baris masukan dengan spesifikasi:

1. Baris pertama adalah sebuah bilangan bulat positif yang merepresentasikan jumlah nilai yang akan dimasukkan (`n`).
2. `n` baris berikutnya adalah bilangan bulat antara `0 - 100` yang merepresentasikan nilai tugas mahasiswa.

Contoh pola masukan:

```bash
5
60
75
80
55
90

```

### Tugas 1 (nilai_01.c, 30 points)

Buat program yang membaca `n` dan `n` buah nilai, lalu menampilkan:

1. Sebaris keluaran berisi **jumlah seluruh nilai**.
2. Sebaris keluaran berisi **nilai rata-rata** dari seluruh nilai, dengan **2 digit presisi** di belakang koma.

Format keluaran hanya berupa dua baris angka (tanpa teks tambahan).

Dengan contoh masukan di atas, contoh luaran yang diharapkan:

```bash
360
72.00

```

### Tugas 2 (nilai_02.c, 30 points)

Dengan melanjutkan pekerjaan Anda pada Tugas 1, modifikasi program sehingga setelah dua baris keluaran sebelumnya, program juga menampilkan:

3. Sebaris keluaran berisi **banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata**.

Masih menggunakan contoh masukan yang sama:

```bash
5
60
75
80
55
90

```

Contoh luaran yang diharapkan:

```bash
360
72.00
3

```

Penjelasan: rata-rata adalah `72.00`, nilai yang `>= 72` adalah `75`, `80`, dan `90` (total 3 mahasiswa).

### Tugas 3 (nilai_03.c, 40 points)

Dengan melanjutkan pekerjaan Anda pada Tugas 2, tambahkan satu baris keluaran lagi yang menampilkan **rentang nilai** (range), yaitu:

> nilai maksimum - nilai minimum

Spesifikasi lengkap keluaran untuk Tugas 3:

1. Baris pertama: jumlah seluruh nilai.
2. Baris kedua: nilai rata-rata dengan 2 digit presisi.
3. Baris ketiga: banyaknya nilai `>=` rata-rata.
4. Baris keempat: rentang nilai (maksimum - minimum).

Masih dengan contoh masukan yang sama:

```bash
5
60
75
80
55
90

```

Contoh luaran yang diharapkan:

```bash
360
72.00
3
35

```

Penjelasan: nilai maksimum adalah `90`, minimum `55`, sehingga rentang nilai adalah `90 - 55 = 35`.

---
