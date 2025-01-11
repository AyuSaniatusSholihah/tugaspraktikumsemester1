#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Activity {
    char name[100];
    struct Activity *next;
} Activity;

typedef struct Student {
    char name[100];
    char grade[10];
    float mathScore;
    float physicsScore;
    float chemistryScore;
    Activity *activityHead;
} Student;

void addStudent(Student **students, int *studentCount) {
    char name[100], grade[10];
    float math, physics, chemistry;

    printf("Masukkan nama siswa: ");
    scanf(" %[^\n]", name);

    // Cek apakah siswa sudah ada
    for (int i = 0; i < *studentCount; i++) {
        if (strcmp((*students)[i].name, name) == 0) {
            printf("Siswa dengan nama '%s' sudah ada dalam sistem.\n", name);
            return;
        }
    }

    printf("Masukkan kelas siswa: ");
    scanf("%s", grade);
    printf("Masukkan nilai Matematika: ");
    scanf("%f", &math);
    printf("Masukkan nilai Fisika: ");
    scanf("%f", &physics);
    printf("Masukkan nilai Kimia: ");
    scanf("%f", &chemistry);

    *students = (Student *)realloc(*students, (*studentCount + 1) * sizeof(Student));
    if (*students == NULL) {
        printf("Gagal menambahkan siswa baru (memori tidak cukup).\n");
        exit(EXIT_FAILURE);
    }

    strcpy((*students)[*studentCount].name, name);
    strcpy((*students)[*studentCount].grade, grade);
    (*students)[*studentCount].mathScore = math;
    (*students)[*studentCount].physicsScore = physics;
    (*students)[*studentCount].chemistryScore = chemistry;
    (*students)[*studentCount].activityHead = NULL;
    (*studentCount)++;
    printf("Siswa '%s' berhasil ditambahkan.\n", name);
}

void addActivityToStudent(Student *students, int studentCount) {
    char studentName[100], activityName[100];
    printf("Masukkan nama siswa untuk ditambahkan kegiatan: ");
    scanf(" %[^\n]", studentName);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, studentName) == 0) {
            printf("Masukkan nama kegiatan: ");
            scanf(" %[^\n]", activityName);

            Activity *newActivity = (Activity *)malloc(sizeof(Activity));
            if (newActivity == NULL) {
                printf("Memori tidak cukup untuk menambahkan aktivitas baru.\n");
                return;
            }
            strcpy(newActivity->name, activityName);
            newActivity->next = students[i].activityHead;
            students[i].activityHead = newActivity;
            printf("Kegiatan berhasil ditambahkan untuk siswa %s.\n", studentName);
            return;
        }
    }

    printf("Siswa dengan nama '%s' tidak ditemukan.\n", studentName);
}

void displayAllData(Student *students, int studentCount) {
    printf("\n=== Data Siswa Lengkap ===\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Nama: %s\n", students[i].name);
        printf("Kelas: %s\n", students[i].grade);
        printf("Nilai Matematika: %.2f\n", students[i].mathScore);
        printf("Nilai Fisika: %.2f\n", students[i].physicsScore);
        printf("Nilai Kimia: %.2f\n", students[i].chemistryScore);

        printf("Kegiatan Ekstrakurikuler:\n");
        Activity *current = students[i].activityHead;
        if (current == NULL) {
            printf("  Tidak ada kegiatan.\n");
        } else {
            while (current != NULL) {
                printf("  - %s\n", current->name);
                current = current->next;
            }
        }
        printf("----------------------------\n");
    }
}

int main() {
    Student *students = NULL;
    int studentCount = 0;
    int choice;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Tambahkan Siswa Baru\n");
        printf("2. Tambahkan Kegiatan Ekstrakurikuler\n");
        printf("3. Tampilkan Seluruh Data Siswa\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &studentCount);
                break;
            case 2:
                addActivityToStudent(students, studentCount);
                break;
            case 3:
                displayAllData(students, studentCount);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 4);

    // Membersihkan memori
    for (int i = 0; i < studentCount; i++) {
        Activity *current = students[i].activityHead;
        while (current != NULL) {
            Activity *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(students);

    return 0;
}
