#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h>  // Untuk malloc dan free (alokasi memori dinamis)
#include <limits.h>  // Untuk INT_MAX dan INT_MIN (inisialisasi min/max)
#include <string.h>  // Disertakan sesuai permintaan, meskipun tidak digunakan secara langsung

int main() {
    int n;
    
    // 1. Membaca jumlah nilai (n) yang akan dimasukkan
    // Pastikan n adalah bilangan positif. Program akan mengasumsikan input valid.
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Jumlah mahasiswa (n) harus bilangan positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Alokasi memori dinamis untuk menyimpan nilai-nilai tugas
    // Menggunakan int* karena kita menyimpan array integer
    int *scores = (int *)malloc(n * sizeof(int));
    
    // Periksa jika alokasi memori gagal
    if (scores == NULL) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori.\n");
        return 1; // Keluar dengan kode error
    }

    double sum = 0.0;          // Menggunakan double untuk sum agar presisi dalam perhitungan rata-rata
    int min_score = INT_MAX;   // Inisialisasi dengan nilai integer maksimum
    int max_score = INT_MIN;   // Inisialisasi dengan nilai integer minimum

    // 2. Membaca n baris nilai tugas, menghitung total, min, dan max
    for (int i = 0; i < n; i++) {
        int current_score;
        if (scanf("%d", &current_score) != 1) {
            fprintf(stderr, "Error: Input nilai tidak valid.\n");
            free(scores); // Bebaskan memori sebelum keluar
            return 1;
        }

        // Validasi nilai antara 0-100
        if (current_score < 0 || current_score > 100) {
            fprintf(stderr, "Error: Nilai tugas harus antara 0 dan 100.\n");
            free(scores); // Bebaskan memori sebelum keluar
            return 1;
        }

        scores[i] = current_score; // Simpan nilai ke array
        sum += current_score;      // Tambahkan ke total
        
        // Perbarui nilai minimum dan maksimum
        if (current_score < min_score) {
            min_score = current_score;
        }
        if (current_score > max_score) {
            max_score = current_score;
        }
    }

    // 3. Menghitung rata-rata nilai
    double average_score = sum / n;

    // 4. Menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    int count_above_avg = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average_score) {
            count_above_avg++;
        }
    }

    // 5. Menampilkan keluaran yang diharapkan
    printf("%.0f\n", sum);                    // Jumlah seluruh nilai (tanpa desimal)
    printf("%.2f\n", average_score);          // Nilai rata-rata dengan 2 digit presisi
    printf("%d\n", count_above_avg);         // Banyaknya mahasiswa di atas/sama dengan rata-rata
    printf("%d\n", max_score - min_score);   // Rentang nilai (maksimum - minimum)

    // Penting: Bebaskan memori yang dialokasikan secara dinamis
    free(scores);
    scores = NULL; // Praktik baik untuk menghindari dangling pointer

    return 0; // Program berakhir dengan sukses
}
