#include <stdio.h>

// Enum untuk nama lampu
typedef enum {
    MERAH = 0,
    KUNING = 1,
    HIJAU = 2
} Lampu;

// Bitmask untuk status lampu lalu lintas (3 bit)
unsigned char statusLampu = 0x0;

// Fungsi untuk menampilkan status lampu dalam bentuk biner
void tampilkanStatusBinary(unsigned char status) {
    printf("Status Binary: ");
    for (int i = 2; i >= 0; i--) {
        printf("%d", (status >> i) & 1);
    }
    printf("\n");
}

// Fungsi untuk menampilkan status setiap lampu
void tampilkanStatusLampu() {
    printf("Lampu Merah: %s\n", (statusLampu & (1 << MERAH)) ? "ON" : "OFF");
    printf("Lampu Kuning: %s\n", (statusLampu & (1 << KUNING)) ? "ON" : "OFF");
    printf("Lampu Hijau: %s\n", (statusLampu & (1 << HIJAU)) ? "ON" : "OFF");
}

// Fungsi untuk menghidupkan lampu menggunakan operasi bitwise OR
void hidupkanLampu(Lampu lampu) {
    statusLampu |= (1 << lampu);
    printf("Lampu %s dihidupkan.\n", (lampu == MERAH) ? "Merah" : (lampu == KUNING) ? "Kuning" : "Hijau");
}

// Fungsi untuk mematikan lampu menggunakan operasi bitwise AND dan NOT
void matikanLampu(Lampu lampu) {
    statusLampu &= ~(1 << lampu);
    printf("Lampu %s dimatikan.\n", (lampu == MERAH) ? "Merah" : (lampu == KUNING) ? "Kuning" : "Hijau");
}

int main() {
    int pilihanAksi, pilihanLampu;

    while (1) {
        // Tampilkan status lampu dalam bentuk biner dan ON/OFF
        printf("\n=== Sistem Pengelolaan Lampu Lalu Lintas ===\n");
        tampilkanStatusBinary(statusLampu);
        tampilkanStatusLampu();

        // Pilihan aksi
        printf("\nPilih aksi:\n");
        printf("1. Hidupkan lampu\n");
        printf("2. Matikan lampu\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihanAksi);

        if (pilihanAksi == 3) {
            printf("Keluar dari sistem.\n");
            break;
        }

        // Pilihan lampu
        printf("\nPilih lampu:\n");
        printf("0. Lampu Merah\n");
        printf("1. Lampu Kuning\n");
        printf("2. Lampu Hijau\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihanLampu);

        if (pilihanLampu < 0 || pilihanLampu > 2) {
            printf("Pilihan lampu tidak valid.\n");
            continue;
        }

        // Jalankan aksi berdasarkan pilihan
        if (pilihanAksi == 1) {
            hidupkanLampu((Lampu)pilihanLampu);
        } else if (pilihanAksi == 2) {
            matikanLampu((Lampu)pilihanLampu);
        } else {
            printf("Pilihan aksi tidak valid.\n");
        }
    }

    return 0;
}
