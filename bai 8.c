#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    FILE *file;
    int n = 0;
    struct Student students[100]; //Mang chua thong tin sinh vien

    // Mo file students.txt de doc
    file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file students.txt\n");
        return 1;
    }
    // Ðoc thong tin sinh vien tu file va luu vao mang
    while (fscanf(file, "%d,%49[^,],%d\n", &students[n].id, students[n].name, &students[n].age) == 3) {
        n++; // Tang so luong sinh vien da doc
        if (n >= 100) break; // Dung lai neu mang day
    }

    fclose(file);
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

