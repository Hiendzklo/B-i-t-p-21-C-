#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    FILE *file;
    int n, i;
    // Khoi tao mang sinh vien
    struct Student students[100];
    // Nhap so luong sinh vien
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    // Nhap thong tin sinh vien
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar(); // Ðoc bo ky tu newline sau khi nhap so
        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);  // Ð?c tên sinh viên
        // Xoa ky tu newline neu co trong ten
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }
    // Mo file students.txt de ghi thong tin sinh vien
    file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file students.txt\n");
        return 1;
    }
    // Ghi thong tin sinh vien vao file
    for (i = 0; i < n; i++) {
        fprintf(file, "%d,%s,%d\n", students[i].id, students[i].name, students[i].age);
    }
    printf("Thong tin sinh vien da duoc ghi vao file students.txt\n");
    fclose(file);
}

