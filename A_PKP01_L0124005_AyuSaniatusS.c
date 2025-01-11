#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tampilkanMenu() {
    printf("\n======= Menu Toko STambah Jaya Sport ========\n");
    printf("1. Beli raket (Rp 200000)\n");
    printf("2. Beli jersey (Rp 100000)\n");
    printf("3. Beli bola (Rp 250000)\n");
    printf("4. Cek Saldo\n");
    printf("5. Keluar\n");
    printf("Pilih menu (pisahkan dengan koma jika lebih dari satu): ");
}

void beliBarang(int pilihan, int *saldo, int raket, int jersey, int bola) {
    switch (pilihan) {
        case 1: 
            if (*saldo >= raket) {
                *saldo -= raket;
                printf("Anda berhasil membeli raket.\n");
            } else {
                printf("Saldo anda tidak cukup untuk membeli raket.\n");
            }
            break;
        case 2: 
            if (*saldo >= jersey) {
                *saldo -= jersey;
                printf("Anda berhasil membeli jersey.\n");
            } else {
                printf("Saldo anda tidak cukup untuk membeli jersey.\n");
            }
            break;
        case 3: 
            if (*saldo >= bola) {
                *saldo -= bola;
                printf("Anda berhasil membeli bola.\n");
            } else {
                printf("Saldo anda tidak cukup untuk membeli bola.\n");
            }
            break;
        case 4:
            printf("Saldo anda saat ini: Rp %d\n", *saldo);
            break;
        case 5: 
            printf("Terima kasih telah berbelanja!\n");
            printf("Saldo akhir anda: Rp %d\n", *saldo);
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
    }
}

int main() {
    int saldo = 500000; 
    int raket = 200000, jersey = 100000, bola = 250000; 
    char input[100]; 
    char *token; 

    while (1) {
        tampilkanMenu();
        scanf("%s", input);

        token = strtok(input, ",");
        while (token != NULL) {
            int pilihan = atoi(token); 
            beliBarang(pilihan, &saldo, raket, jersey, bola); 
            token = strtok(NULL, ","); 
        }

        printf("Saldo akhir anda: Rp %d\n", saldo); 
    }

    return 0;
}
