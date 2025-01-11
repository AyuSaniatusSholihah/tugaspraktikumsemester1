//L0124005_Ayu Saniatus Sholihah
#include <stdio.h>
#include <math.h>  // Library untuk sqrt dan pow

// Fungsi untuk operasi aritmatika dasar (+, -, *, /)
void operasi_aritmatika(char operator, double angka1, double angka2) {
    double hasil;

    switch (operator) {
        case '+':
            hasil = angka1 + angka2;  // Penjumlahan
            printf("Hasil: %.2f + %.2f = %.2f\n", angka1, angka2, hasil);
            break;
        case '-':
            hasil = angka1 - angka2;  // Pengurangan
            printf("Hasil: %.2f - %.2f = %.2f\n", angka1, angka2, hasil);
            break;
        case '*':
            hasil = angka1 * angka2;  // Perkalian
            printf("Hasil: %.2f * %.2f = %.2f\n", angka1, angka2, hasil);
            break;
        case '/':
            if (angka2 != 0) {
                hasil = angka1 / angka2;  // Pembagian
                printf("Hasil: %.2f / %.2f = %.2f\n", angka1, angka2, hasil);
            } else {
                printf("Error: Pembagian dengan nol tidak valid.\n");  // Penanganan pembagian dengan nol
            }
            break;
        default:
            printf("Operator tidak valid untuk operasi aritmatika.\n");  // Pesan jika operator tidak valid
    }
}

// Fungsi untuk menghitung akar kuadrat
void hitung_sqrt(double angka) {
    if (angka >= 0) {
        double hasil = sqrt(angka);  // Menghitung akar kuadrat
        printf("Hasil sqrt(%.2f) = %.2f\n", angka, hasil);
    } else {
        printf("Error: Akar kuadrat dari angka negatif tidak valid.\n");  // Penanganan untuk angka negatif
    }
}

// Fungsi untuk menghitung pangkat
void hitung_pow(double basis, double eksponen) {
    double hasil = pow(basis, eksponen);  // Menghitung pangkat
    printf("Hasil %.2f^%.2f = %.2f\n", basis, eksponen, hasil);
}

int main() {
    char operator;
    double angka1, angka2;

    // Input bilangan pertama
    printf("Masukkan bilangan pertama: ");
    scanf("%lf", &angka1);

    // Input operator
    printf("Masukkan operator (+, -, *, /, s untuk sqrt, p untuk pow): ");
    scanf(" %c", &operator);

    if (operator == 's') {
        // Jika operator adalah 's' untuk sqrt, hanya memerlukan 1 angka
        hitung_sqrt(angka1);  // Memanggil fungsi untuk menghitung akar kuadrat
    } else if (operator == 'p') {
        // Jika operator adalah 'p' untuk pow, perlu input bilangan kedua
        printf("Masukkan bilangan kedua (eksponen): ");
        scanf("%lf", &angka2);
        hitung_pow(angka1, angka2);  // Memanggil fungsi untuk menghitung pangkat
    } else if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
        // Input bilangan kedua untuk operasi aritmatika
        printf("Masukkan bilangan kedua: ");
        scanf("%lf", &angka2);
        operasi_aritmatika(operator, angka1, angka2);  // Memanggil fungsi untuk operasi aritmatika dengan 2 angka
    } else {
        printf("Operator tidak valid.\n");  // Pesan jika operator tidak valid
    }

    return 0;  // Mengembalikan 0 untuk menandakan program selesai
}
