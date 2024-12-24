#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    float price;
    char category[30];
};

int main() {
    struct Book books[100];
    int count = 0;
    FILE *file;
    int choice;

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Nhap thong tin sach thu %d:\n", i + 1);
                    printf("Ma sach: ");
                    scanf("%d", &books[i].id);
                    getchar();
                    printf("Ten sach: ");
                    fgets(books[i].name, sizeof(books[i].name), stdin);
                    books[i].name[strcspn(books[i].name, "\n")] = '\0';
                    printf("Tac gia: ");
                    fgets(books[i].author, sizeof(books[i].author), stdin);
                    books[i].author[strcspn(books[i].author, "\n")] = '\0';
                    printf("Gia tien: ");
                    scanf("%f", &books[i].price);
                    getchar();
                    printf("The loai: ");
                    fgets(books[i].category, sizeof(books[i].category), stdin);
                    books[i].category[strcspn(books[i].category, "\n")] = '\0';
                }
                break;
            case 2:
                file = fopen("books.bin", "wb");
                if (file == NULL) {
                    printf("Khong the mo file de ghi\n");
                    break;
                }
                fwrite(&count, sizeof(int), 1, file);
                fwrite(books, sizeof(struct Book), count, file);
                fclose(file);
                printf("Da luu thong tin sach vao file\n");
                break;
            case 3:
                file = fopen("books.bin", "rb");
                if (file == NULL) {
                    printf("Khong the mo file de doc\n");
                    break;
                }
                fread(&count, sizeof(int), 1, file);
                fread(books, sizeof(struct Book), count, file);
                fclose(file);
                printf("Da lay thong tin sach tu file\n");
                break;
            case 4:
                if (count == 0) {
                    printf("Khong co thong tin sach de hien thi\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("Sach thu %d:\n", i + 1);
                        printf("Ma sach: %d\n", books[i].id);
                        printf("Ten sach: %s\n", books[i].name);
                        printf("Tac gia: %s\n", books[i].author);
                        printf("Gia tien: %.2f\n", books[i].price);
                        printf("The loai: %s\n", books[i].category);
                    }
                }
                break;
            case 5:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 5);
}

