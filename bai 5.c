#include <stdio.h>

int main() {
    FILE *file;
    int n;
    char line[256];  // Mang de luu moi dong nhap vào

    // Mo tep de ghi du lieu (tao moi neu chua co)
    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt de ghi.\n");
        return 1;
    }
    // Nhap so dong can ghi vao tep
    printf("Nhap vao so dong: ");
    scanf("%d", &n);
    getchar(); // Ðoc ky tu newline con sot lqi
    // Nhap va ghi noi dung tung dong vao tep
    for (int i = 0; i < n; i++) {
        printf("Nhap dong thu %d: ", i + 1);
        fgets(line, sizeof(line), stdin); // Ðoc mot dong tu nguoi dung
        fprintf(file, "%s", line); // Ghi dong vao tep
    }
    // Ðong tep sau khi ghi xong
    fclose(file);

    // Mo lai tep de doc va in noi dung
    file = fopen("bt05.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt de doc.\n");
        return 1;
    }
    // Ðoc va in tung dong trong tep
    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

