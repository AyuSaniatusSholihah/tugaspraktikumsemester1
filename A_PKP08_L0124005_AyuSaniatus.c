#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AGENDA 100

// Struct to represent an agenda item
typedef struct {
    char name[100];
    int hour;
    int minute;
} Agenda;

// Function to add an agenda to the file
void tambahAgenda(const char *fileName) {
    FILE *fp = fopen(fileName, "a"); // Open file in append mode
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    Agenda agenda;
    
    // Input agenda details
    printf("Masukkan nama agenda: ");
    fgets(agenda.name, sizeof(agenda.name), stdin);
    agenda.name[strcspn(agenda.name, "\n")] = 0; // Remove the newline character

    printf("Masukkan waktu agenda (jam menit, contoh 12 30): ");
    scanf("%d  %d", &agenda.hour, &agenda.minute);
    getchar(); // Clean buffer

    // Save agenda to the file
    fprintf(fp, "%s %02d : %02d\n", agenda.name, agenda.hour, agenda.minute);
    fclose(fp);
    printf("Agenda berhasil ditambahkan!\n");
}

// Function to display all agendas
void tampilkanAgenda(const char *fileName) {
    FILE *fp = fopen(fileName, "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char line[200];
    printf("\nDaftar Agenda:\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

// Function to delete an agenda from the file
void hapusAgenda(const char *fileName) {
    FILE *fp = fopen(fileName, "r");  // Open the original file in read mode
    FILE *temp = fopen("temp.txt", "w"); // Create a temporary file to save updated data
    if (fp == NULL || temp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    char agendaName[100];
    int hour, minute;
    
    printf("Masukkan nama agenda yang ingin dihapus: ");
    fgets(agendaName, sizeof(agendaName), stdin);
    agendaName[strcspn(agendaName, "\n")] = 0;  // Remove newline

    printf("Masukkan waktu agenda yang ingin dihapus (jam menit, contoh 12 30): ");
    scanf("%d : %d", &hour, &minute);
    getchar();  // Clean buffer

    char line[200];
    int found = 0;
    
    // Copy all lines except the one to delete to the temporary file
    while (fgets(line, sizeof(line), fp)) {
        char name[100];
        int h, m;
        
        // Parse the line to extract the agenda details
        sscanf(line, "%99s %d %d", name, &h, &m);
        
        // If the name and time don't match, keep the agenda in the temp file
        if (strcmp(name, agendaName) != 0 || h != hour || m != minute) {
            fputs(line, temp);
        } else {
            found = 1;  // Mark as found
        }
    }

    fclose(fp);
    fclose(temp);

    // If agenda was found and deleted, replace the original file with the temporary one
    if (found) {
        remove(fileName);
        rename("temp.txt", fileName);
        printf("Agenda berhasil dihapus.\n");
    } else {
        printf("Agenda tidak ditemukan.\n");
        remove("temp.txt");
    }
}

// Function to load agendas from a file
void muatAgenda(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Gagal membuka file untuk memuat agenda.\n");
        return;
    }

    Agenda agenda;
    printf("\nAgenda yang dimuat dari file:\n");
    while (fscanf(fp, "%99s %d %d", agenda.name, &agenda.hour, &agenda.minute) != EOF) {
        printf("%s %02d:%02d\n", agenda.name, agenda.hour, agenda.minute);
    }
    fclose(fp);
}

int main() {
    int pilihan;
    const char *fileName = "agenda.txt"; // File to store agendas

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Agenda\n");
        printf("2. Tampilkan Semua Agenda\n");
        printf("3. Hapus Agenda\n");
        printf("4. Muat Agenda dari File\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        getchar(); // Clean buffer

        switch (pilihan) {
            case 1:
                tambahAgenda(fileName);  // Add agenda
                break;
            case 2:
                tampilkanAgenda(fileName); // Display all agendas
                break;
            case 3:
                hapusAgenda(fileName);  // Delete an agenda
                break;
            case 4:
                muatAgenda(fileName);  // Load agendas from file
                break;
            case 5:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
