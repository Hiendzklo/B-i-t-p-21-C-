#include <stdio.h>

int main() {
    char kyTuDauTien;
    FILE *file;

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de doc.\n");
        return 1;
    }
    // Ðoc ky tu dau tien tu file
    kyTuDauTien = fgetc(file);
    // Kiem tra neu file rong
    if (kyTuDauTien == EOF) {
        printf("File rong.\n");
    } else {
        printf("Ky tu dau tien trong file: %c\n", kyTuDauTien);
    }

    fclose(file);
}

