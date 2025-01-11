#include <stdio.h>

int main() {
    // Harga tetap untuk setiap produk
    float price1 = 2000;
    float price2 = 4500;
    float price3 = 9000;
    float price4 = 4490;
    float price5 = 6800;

    // Variabel untuk menyimpan jumlah unit yang terjual
    int quantity1, quantity2, quantity3, quantity4, quantity5;
    
    // Variabel untuk diskon dan harga akhir
    float diskon, harga_akhir;

    // Memasukkan jumlah unit yang terjual untuk setiap produk
    printf("Masukkan jumlah produk 1 yang terjual: ");
    scanf("%d", &quantity1);

    printf("Masukkan jumlah produk 2 yang terjual: ");
    scanf("%d", &quantity2);

    printf("Masukkan jumlah produk 3 yang terjual: ");
    scanf("%d", &quantity3);

    printf("Masukkan jumlah produk 4 yang terjual: ");
    scanf("%d", &quantity4);

    printf("Masukkan jumlah produk 5 yang terjual: ");
    scanf("%d", &quantity5);

    // Menghitung total penjualan untuk setiap produk
    float total1 = price1 * quantity1;
    float total2 = price2 * quantity2;
    float total3 = price3 * quantity3;
    float total4 = price4 * quantity4;
    float total5 = price5 * quantity5;

    // Menghitung total keseluruhan penjualan
    float total_harga = total1 + total2 + total3 + total4 + total5;

    // Menampilkan total penjualan untuk setiap produk dan total keseluruhan
    printf("\nTotal penjualan untuk setiap produk:\n");
    printf("Produk 1: Rp%.2f\n", total1);
    printf("Produk 2: Rp%.2f\n", total2);
    printf("Produk 3: Rp%.2f\n", total3);
    printf("Produk 4: Rp%.2f\n", total4);
    printf("Produk 5: Rp%.2f\n", total5);

    printf("\nTotal keseluruhan penjualan: Rp%.2f\n", total_harga);

    // Cek apakah total harga lebih dari 100.000 untuk diskon
    if (total_harga > 100000) {
        diskon = total_harga * 0.10;  // Menghitung diskon 10%
        harga_akhir = total_harga - diskon;
        printf("Anda mendapatkan diskon 10%% sebesar Rp%.2f\n", diskon);
    } else {
        harga_akhir = total_harga;
        printf("Tidak ada diskon.\n");
    }

    // Menampilkan harga akhir
    printf("Harga akhir yang harus dibayar: Rp%.2f\n", harga_akhir);

    return 0;
}
