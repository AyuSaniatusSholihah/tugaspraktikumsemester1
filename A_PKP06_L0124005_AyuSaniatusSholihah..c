#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 100

typedef struct {
    char *judul;
    char *penulis;
    int tahunTerbit;
    char *penerbit;
} Buku;

typedef struct {
    Buku **koleksiBuku;
    int jumlahBuku;
} Perpustakaan;

// Fungsi untuk membuat buku baru
Buku *buatBuku() {
    Buku *bukuBaru = (Buku *)malloc(sizeof(Buku));
    bukuBaru->judul = (char *)malloc(MAX_STRING_SIZE);
    bukuBaru->penulis = (char *)malloc(MAX_STRING_SIZE);
    bukuBaru->penerbit = (char *)malloc(MAX_STRING_SIZE);

    printf("Masukkan Judul Buku: ");
    fgets(bukuBaru->judul, MAX_STRING_SIZE, stdin);
    bukuBaru->judul[strcspn(bukuBaru->judul, "\n")] = '\0';

    printf("Masukkan Nama Penulis: ");
    fgets(bukuBaru->penulis, MAX_STRING_SIZE, stdin);
    bukuBaru->penulis[strcspn(bukuBaru->penulis, "\n")] = '\0';

    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &bukuBaru->tahunTerbit);
    getchar(); // membersihkan newline

    printf("Masukkan Nama Penerbit: ");
    fgets(bukuBaru->penerbit, MAX_STRING_SIZE, stdin);
    bukuBaru->penerbit[strcspn(bukuBaru->penerbit, "\n")] = '\0';

    return bukuBaru;
}

// Fungsi untuk menampilkan data buku
void tampilkanBuku(Buku *buku) {
    printf("Judul Buku  : %s\n", buku->judul);
    printf("Penulis     : %s\n", buku->penulis);
    printf("Tahun Terbit: %d\n", buku->tahunTerbit);
    printf("Penerbit    : %s\n", buku->penerbit);
}

// Fungsi untuk menambahkan buku ke perpustakaan
void tambahBuku(Perpustakaan *perpustakaan) {
    perpustakaan->koleksiBuku = realloc(perpustakaan->koleksiBuku, (perpustakaan->jumlahBuku + 1) * sizeof(Buku *));
    perpustakaan->koleksiBuku[perpustakaan->jumlahBuku] = buatBuku();
    perpustakaan->jumlahBuku++;
    printf("Buku berhasil ditambahkan!\n\n");
}

// Fungsi untuk mencari buku berdasarkan judul
void cariBuku(Perpustakaan *perpustakaan) {
    char judulCari[MAX_STRING_SIZE];
    printf("Masukkan judul buku yang ingin dicari: ");
    fgets(judulCari, MAX_STRING_SIZE, stdin);
    judulCari[strcspn(judulCari, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < perpustakaan->jumlahBuku; i++) {
        if (strcmp(perpustakaan->koleksiBuku[i]->judul, judulCari) == 0) {
            printf("\nBuku ditemukan:\n");
            tampilkanBuku(perpustakaan->koleksiBuku[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Buku tidak ditemukan.\n");
    }
}

// Fungsi untuk menghapus buku berdasarkan judul
void hapusBuku(Perpustakaan *perpustakaan) {
    char judulHapus[MAX_STRING_SIZE];
    printf("Masukkan judul buku yang ingin dihapus: ");
    fgets(judulHapus, MAX_STRING_SIZE, stdin);
    judulHapus[strcspn(judulHapus, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < perpustakaan->jumlahBuku; i++) {
        if (strcmp(perpustakaan->koleksiBuku[i]->judul, judulHapus) == 0) {
            free(perpustakaan->koleksiBuku[i]->judul);
            free(perpustakaan->koleksiBuku[i]->penulis);
            free(perpustakaan->koleksiBuku[i]->penerbit);
            free(perpustakaan->koleksiBuku[i]);

            for (int j = i; j < perpustakaan->jumlahBuku - 1; j++) {
                perpustakaan->koleksiBuku[j] = perpustakaan->koleksiBuku[j + 1];
            }
            perpustakaan->jumlahBuku--;
            perpustakaan->koleksiBuku = realloc(perpustakaan->koleksiBuku, perpustakaan->jumlahBuku * sizeof(Buku *));
            printf("Buku berhasil dihapus!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Buku tidak ditemukan.\n");
    }
}

// Fungsi untuk menampilkan seluruh buku dalam perpustakaan
void tampilkanSemuaBuku(Perpustakaan *perpustakaan) {
    if (perpustakaan->jumlahBuku == 0) {
        printf("Tidak ada buku dalam perpustakaan.\n");
    } else {
        printf("\n=== Daftar Buku di Perpustakaan ===\n");
        for (int i = 0; i < perpustakaan->jumlahBuku; i++) {
            printf("\nBuku %d:\n", i + 1);
            tampilkanBuku(perpustakaan->koleksiBuku[i]);
        }
    }
}

// Fungsi untuk membersihkan semua memori
void hapusPerpustakaan(Perpustakaan *perpustakaan) {
    for (int i = 0; i < perpustakaan->jumlahBuku; i++) {
        free(perpustakaan->koleksiBuku[i]->judul);
        free(perpustakaan->koleksiBuku[i]->penulis);
        free(perpustakaan->koleksiBuku[i]->penerbit);
        free(perpustakaan->koleksiBuku[i]);
    }
    free(perpustakaan->koleksiBuku);
}

int main() {
    Perpustakaan perpustakaan = {NULL, 0};
    int pilihan;

    do {
        printf("\n=== Menu Perpustakaan ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Cari Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Tampilkan Semua Buku\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        getchar(); // membersihkan newline

        switch (pilihan) {
            case 1:
                tambahBuku(&perpustakaan);
                break;
            case 2:
                cariBuku(&perpustakaan);
                break;
            case 3:
                hapusBuku(&perpustakaan);
                break;
            case 4:
                tampilkanSemuaBuku(&perpustakaan);
                break;
            case 5:
                printf("Keluar dari program.\n");
                hapusPerpustakaan(&perpustakaan);
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);

    return 0;
}
