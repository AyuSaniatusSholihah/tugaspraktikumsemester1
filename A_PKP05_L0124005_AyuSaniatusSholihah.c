#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PPN 0.10 // PPN sebesar 10%
#define DISKON_THRESHOLD 200000 // Batas minimal diskon
#define DISKON 0.05 // Diskon sebesar 5%

// Fungsi untuk menghitung total harga per barang berdasarkan harga dan jumlahnya
// Menggunakan pointer dan pass by reference pada parameter int *total dan int *subtotal
void hitungTotal(int *total, int harga, int jumlah, int *subtotal) {
    *subtotal = harga * jumlah;  // Menghitung subtotal
    *total += *subtotal; // Menambahkan subtotal ke total
}

// Fungsi untuk menampilkan nota pembayaran
void tampilkanNota(int total, int uangDibayar, float ppn, float diskon, float totalBayar) {
    // Menampilkan nota dengan rincian lengkap
    printf("\n======== Tambah Jaya Sport and Musik ========\n");
    printf("Total Harga Barang: Rp %d\n", total);
    printf("PPN 10%%: Rp %.2f\n", ppn);
    if (diskon > 0) printf("Diskon 5%%: -Rp %.2f\n", diskon);
    printf("Total Bayar Setelah PPN dan Diskon: Rp %.2f\n", totalBayar);
    printf("Uang Dibayar: Rp %d\n", uangDibayar);

    if (uangDibayar >= (int)totalBayar) {
        int kembalian = uangDibayar - (int)totalBayar;
        printf("Kembalian: Rp %d\n", kembalian);
        printf("\nTerima kasih sudah belanja di sini!\n");
    } else {
        int kurang = (int)totalBayar - uangDibayar;
        printf("Maaf, uang Anda tidak cukup. Anda kurang Rp %d.\n", kurang);
    }
}

int main() {
    // Daftar barang yang tersedia beserta harga masing-masing
    char *barang[] = {"Raket", "Kok", "Sepatu", "Alat Pancing", "Jersey", "Gitar", "Drum", "Rebana", "Bass"};
    int harga[] = {150000, 50000, 300000, 250000, 150000, 600000, 800000, 400000, 500000};
    int pilihan, jumlah, total = 0, subtotal, uangDibayar;
    char input[100]; // String untuk menyimpan input pilihan barang

    printf("======== Tambah Jaya Sport and Musik ========\n");
    printf("Daftar Barang:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d. %s - Rp %d\n", i + 1, barang[i], harga[i]);
    }

    // Meminta input satu kali untuk semua barang yang dipilih
    printf("\nMasukkan nomor barang yang ingin dibeli (pisahkan dengan koma): ");
    scanf(" %[^\n]", input);  // Membaca input sebagai string hingga newline

    // Memecah input berdasarkan tanda koma
    char *token = strtok(input, ",");
    
    // Loop untuk memproses setiap nomor barang yang dipilih
    while (token != NULL) {
        pilihan = atoi(token); // Mengubah token menjadi integer
        
        if (pilihan >= 1 && pilihan <= 9) {
            printf("Masukkan jumlah barang untuk %s: ", barang[pilihan - 1]);
            scanf("%d", &jumlah);

            // Menghitung total harga untuk barang yang dipilih
            // Mengirimkan alamat variabel total dan subtotal ke fungsi hitungTotal untuk pass by reference
            hitungTotal(&total, harga[pilihan - 1], jumlah, &subtotal);
            
            // Menampilkan subtotal untuk barang yang dipilih
            printf("%s x %d = Rp %d\n", barang[pilihan - 1], jumlah, subtotal);
        } else {
            printf("Pilihan %d tidak valid, silakan masukkan nomor barang yang tersedia.\n", pilihan);
        }
        token = strtok(NULL, ","); // Mendapatkan token berikutnya
    }

    // Menghitung PPN, diskon, dan total bayar setelah PPN dan diskon
    float ppn = total * PPN;
    float diskon = (total > DISKON_THRESHOLD) ? total * DISKON : 0;
    float totalBayar = total + ppn - diskon;

    // Menampilkan total belanja setelah PPN dan diskon
    printf("\nTotal yang harus dibayar (termasuk PPN dan diskon jika berlaku): Rp %.2f\n", totalBayar);

    // Meminta input jumlah uang yang dibayarkan oleh pembeli
    printf("Masukkan jumlah uang yang dibayarkan: Rp ");
    scanf("%d", &uangDibayar);

    // Memanggil fungsi untuk menampilkan nota akhir dengan perincian lengkap
    tampilkanNota(total, uangDibayar, ppn, diskon, totalBayar);

    return 0;
}
