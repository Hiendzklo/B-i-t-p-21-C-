#include <stdio.h>

int main() {
    char chuoi[1000];
    FILE *file;

    // Mo file o che do ghi
    file = fopen("bt01.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de ghi.\n");
        return 1;
    }
    // Nhap chuoi tu nguoi dung
    printf("Nhap mot chuoi bat ky: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    // Ghi chuoi vao file
    fprintf(file, "%s", chuoi);
    fclose(file);
    printf("Ghi chuoi vao file bt01.txt thanh cong.\n");
}

