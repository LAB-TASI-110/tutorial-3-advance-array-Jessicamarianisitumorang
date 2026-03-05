#include <stdio.h>   // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h>  // Diperlukan untuk fungsi umum, meskipun tidak secara eksplisit digunakan di sini
#include <string.h>  // Diperlukan untuk manipulasi string, meskipun tidak secara eksplisit digunakan di sini

int main() {
    int n;           // Variabel untuk menyimpan jumlah data
    long long sum = 0; // Variabel untuk menyimpan jumlah total nilai, menggunakan long long untuk mencegah overflow
    int currentValue;  // Variabel untuk menyimpan nilai data yang sedang dibaca
    
    // Membaca input n (jumlah data)
    // Diasumsikan input selalu valid dan n >= 1
    scanf("%d", &n);
    
    // Membaca n baris nilai bilangan bulat sebagai data
    // Diasumsikan nilai antara 0-100
    for (int i = 0; i < n; i++) {
        scanf("%d", &currentValue);
        sum += currentValue; // Menambahkan nilai saat ini ke total
    }
    
    // Menghitung rata-rata
    // Menggunakan (double)sum untuk melakukan pembagian floating-point
    double average = (double)sum / n;
    
    // Mencetak jumlah seluruh nilai pada baris pertama
    printf("%lld\n", sum);
    
    // Mencetak nilai rata-rata dengan dua digit presisi di belakang koma pada baris kedua
    printf("%.2f\n", average);
    
    return 0; // Mengindikasikan program berjalan sukses
}
