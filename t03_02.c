#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Untuk fungsi alokasi memori dinamis seperti malloc dan free
#include <string.h> // Disertakan sesuai permintaan, meskipun tidak digunakan secara langsung

int main() {
    // 1. Deklarasi Variabel
    int n;                 // Jumlah nilai tugas mahasiswa
    int i;                 // Variabel loop counter
    int *grades;           // Pointer untuk array dinamis yang akan menyimpan nilai tugas
    long long total_sum = 0; // Untuk menjumlahkan seluruh nilai, menggunakan long long untuk antisipasi nilai besar
    double average;        // Untuk menyimpan nilai rata-rata dengan presisi desimal
    int count_above_average = 0; // Untuk menghitung jumlah mahasiswa di atas atau sama dengan rata-rata

    // 2. Membaca nilai 'n' dari baris pertama input
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Gagal membaca jumlah nilai (n).\n");
        return 1; // Keluar dengan kode error
    }

    // Validasi: n harus positif
    if (n <= 0) {
        fprintf(stderr, "Error: Jumlah nilai (n) harus merupakan bilangan positif.\n");
        return 1; // Keluar dengan kode error
    }

    // 3. Alokasi memori dinamis untuk menyimpan 'n' nilai tugas
    grades = (int *)malloc(n * sizeof(int));
    if (grades == NULL) { // Periksa jika alokasi memori gagal
        fprintf(stderr, "Error: Gagal mengalokasikan memori.\n");
        return 1; // Keluar dengan kode error
    }

    // 4. Membaca 'n' nilai tugas dan menjumlahkannya
    for (i = 0; i < n; i++) {
        if (scanf("%d", &grades[i]) != 1) {
            fprintf(stderr, "Error: Gagal membaca nilai tugas ke-%d.\n", i + 1);
            free(grades); // Bebaskan memori sebelum keluar
            return 1; // Keluar dengan kode error
        }
        // Validasi: nilai tugas antara 0-100
        if (grades[i] < 0 || grades[i] > 100) {
            fprintf(stderr, "Error: Nilai tugas ke-%d harus antara 0 dan 100.\n", i + 1);
            free(grades); // Bebaskan memori sebelum keluar
            return 1; // Keluar dengan kode error
        }
        total_sum += grades[i];
    }

    // 5. Menghitung nilai rata-rata
    // Pastikan pembagian floating-point dengan melakukan type casting
    average = (double)total_sum / n;

    // 6. Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (i = 0; i < n; i++) {
        if (grades[i] >= average) {
            count_above_average++;
        }
    }

    // 7. Menampilkan hasil sesuai format yang diminta
    printf("%lld\n", total_sum);      // Jumlah seluruh nilai
    printf("%.2f\n", average);        // Nilai rata-rata dengan 2 digit presisi
    printf("%d\n", count_above_average); // Banyaknya mahasiswa di atas atau sama dengan rata-rata

    // 8. Membebaskan memori yang telah dialokasikan secara dinamis
    free(grades);
    grades = NULL; // Praktik baik untuk mengatur pointer ke NULL setelah membebaskan memori

    return 0; // Mengindikasikan program berjalan sukses
}
