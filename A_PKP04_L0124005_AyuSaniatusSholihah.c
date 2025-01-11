#include <stdio.h>

// Array menyimpan daftar nama siswa
char *nama_siswa[] = {
    "Adrian", "Annisa", "Aprillia", "Arga", "Ayu", 
    "Kevin", "Anjas", "Putra", "Nugraha", "Adit"
};

// Array menyimpan nilai siswa
int nilai_siswa[] = {
    65, 85, 86, 59, 90, 
    55, 89, 67, 75, 51
};

// Variabel jumlah siswa (panjang dari array nama_siswa dan nilai_siswa)
int jumlah_siswa = 10; 

// Passing grade: Nilai minimal untuk lulus (digunakan untuk pengecekan kelulusan)
int passing_grade = 60;  

// Fungsi untuk menentukan grade huruf siswa berdasarkan nilai
char tentukan_grade(int nilai) {
    if (nilai >= 85) {
        return 'A';  // Grade A untuk nilai >= 85
    } else if (nilai >= 70) {
        return 'B';  // Grade B untuk nilai >= 70
    } else if (nilai >= 60) {
        return 'C';  // Grade C untuk nilai >= 60
    } else {
        return 'D';  // Grade D untuk nilai < 60
    }
}

// Fungsi untuk menampilkan pesan motivasi berdasarkan grade huruf
void pesan_motivasi(char grade) {
    switch (grade) {
        case 'A':
            printf("Excellent! Pertahankan prestasimu!\n");
            break;
        case 'B':
            printf("Bagus! Kamu bisa mencapai lebih tinggi!\n");
            break;
        case 'C':
            printf("Tidak buruk, tapi masih bisa lebih baik.\n");
            break;
        case 'D':
            printf("Jangan menyerah! Teruslah berusaha untuk lebih baik.\n");
            break;
    }
}

// Fungsi untuk mengecek status kelulusan siswa berdasarkan nilai
void cek_kelulusan(int nilai) {
    if (nilai >= passing_grade) {
        printf("Status: Lulus\n");
    } else {
        printf("Status: Tidak Lulus\n");
    }
}

// Fungsi untuk menampilkan daftar siswa
void tampilkan_daftar_siswa() {
    printf("Daftar siswa:\n");
    for (int i = 0; i < jumlah_siswa; i++) {
        printf("%d. %s\n", i + 1, nama_siswa[i]);  // Menampilkan nomor absen dan nama siswa
    }
}

// Fungsi untuk menampilkan informasi siswa berdasarkan absen (nomor siswa)
void cek_siswa(int absen) {
    if (absen >= 1 && absen <= jumlah_siswa) {
        int index = absen - 1;  // Menyesuaikan dengan indeks array

        printf("\nSiswa: %s\n", nama_siswa[index]);
        printf("Nilai Mata Kuliah Konsep Pemrograman: %d\n", nilai_siswa[index]);

        int pilihan;
        do {
            printf("\nPilih opsi:\n");
            printf("1. Cek Kelulusan\n");
            printf("2. Cek Grade\n");
            printf("3. Cek Absen Siswa Lain\n");
            printf("4. Keluar\n");
            printf("Masukkan pilihan: ");
            scanf("%d", &pilihan);

            switch (pilihan) {
                case 1:
                    cek_kelulusan(nilai_siswa[index]);
                    break;
                case 2: {
                    char grade = tentukan_grade(nilai_siswa[index]);
                    printf("Grade: %c\n", grade);
                    pesan_motivasi(grade);
                    break;
                }
                case 3: {
                    // Menampilkan daftar siswa sebelum meminta input
                    tampilkan_daftar_siswa();  
                    printf("\nMasukkan nomor absen siswa yang ingin dicek: ");
                    scanf("%d", &absen);
                    cek_siswa(absen);  // Memanggil fungsi ini lagi untuk absen lain
                    break;
                }
                case 4:
                    printf("Keluar dari opsi.\n");
                    break;
                default:
                    printf("Pilihan tidak valid. Silakan coba lagi.\n");
            }
        } while (pilihan != 4);  // Ulangi menu sampai memilih keluar
    } else {
        printf("Absen tidak valid. Silakan coba lagi.\n");
    }
}

int main() {
    int absen;

    // Menampilkan daftar siswa
    tampilkan_daftar_siswa();

    // Meminta pengguna memasukkan nomor absen siswa yang ingin dicek
    printf("\nMasukkan nomor absen siswa yang ingin dicek nilai mata kuliah konsep pemrograman: ");
    scanf("%d", &absen);

    // Memeriksa siswa berdasarkan nomor absen yang dipilih
    cek_siswa(absen);

    return 0;
}
