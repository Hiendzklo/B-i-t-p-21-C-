#include <stdio.h>

int main() {
    char noiDung[100];
    FILE *file;

    // Mo file o che do ghi them
    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de ghi them.\n");
        return 1;
    }
    // Nhap chuoi can ghi them tu nguoi dung
    printf("Nhap noi dung can ghi them vao file: ");
    fgets(noiDung, sizeof(noiDung), stdin);
    // Ghi chuoi vao file
    fputs(noiDung, file);
    printf("Da ghi them noi dung vao file bt01.txt.\n");
    fclose(file);
}

