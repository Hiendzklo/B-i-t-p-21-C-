#include <stdio.h>

int main() {
    char dongDauTien[100];
    FILE *file;

    // Mo file o che do doc
    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de doc.\n");
        return 1;
    }
    // Ðoc dong dau tien tu file
    if (fgets(dongDauTien, sizeof(dongDauTien), file) != NULL) {
        printf("Dong dau tien trong file: %s\n", dongDauTien);
    } else {
        printf("File rong hoac khong co noi dung.\n");
    }
    fclose(file);
}

