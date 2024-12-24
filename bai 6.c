#include <stdio.h>

int main() {
    FILE *sourceFile, *destFile;
    char ch;

    // Mo file bt01.txt de doc
    sourceFile = fopen("bt01.txt", "r");
    if (sourceFile == NULL) {
        printf("Khong the mo file bt01.txt de doc.\n");
        return 1;
    }
    // Mofile bt06.txt de ghi
    destFile = fopen("bt06.txt", "w");
    if (destFile == NULL) {
        printf("Khong the mo file bt06.txt de ghi.\n");
        fclose(sourceFile); // Ð?m b?o dóng file ngu?n
        return 1;
    }
    // Sao chep noi dung tu bt01.txt sang bt06.txt
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile); // Ghi t?ng ký t? vào bt06.txt
    }
    printf("Sao chep thanh cong tu bt01.txt sang bt06.txt.\n");
    // Ðong ca hai file sau khi hoan thanh
    fclose(sourceFile);
    fclose(destFile);
}

