#include <stdio.h>

void tinhTrungBinhSoChan(void);
void kiemTraNguyenTo(void);
void kiemTraChinhPhuong(void);

int main(void) {
    int chon;

    do {
        printf("\n+--------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 4             |\n");
        printf("+--------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2    |\n");
        printf("| 2. Kiem tra So nguyen to                         |\n");
        printf("| 3. Kiem tra So chinh phuong                      |\n");
        printf("| 0. Thoat chuong trinh                            |\n");
        printf("+--------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (0-3): ");

        if (scanf("%d", &chon) != 1) {
            printf("Du lieu nhap khong hop le!\n");
            return 1;
        }

        switch (chon) {
            case 1:
                tinhTrungBinhSoChan();
                break;
            case 2:
                kiemTraNguyenTo();
                break;
            case 3:
                kiemTraChinhPhuong();
                break;
            case 0:
                printf("Da thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon tu 0 den 3.\n");
        }

    } while (chon != 0);

    return 0;
}

void tinhTrungBinhSoChan(void) {
    int min, max, i;
    int tong = 0, bienDem = 0;
    double trungBinh;

    printf("Nhap min va max: ");
    if (scanf("%d%d", &min, &max) != 2) {
        printf("Du lieu nhap khong hop le!\n");
        return;
    }

    if (min > max) {
        printf("Khong co so nao chia het cho 2 trong khoang da nhap! (truong hop min > max)\n");
        return;
    }

    for (i = min; i <= max; i++) {
        if (i % 2 == 0) {
            tong += i;
            bienDem++;
        }
    }

    if (bienDem == 0) {
        printf("Khong co so nao chia het cho 2 trong khoang da nhap!\n");
    } else {
        trungBinh = (double)tong / bienDem;
        printf("Tong cac so chia het cho 2: %d\n", tong);
        printf("So luong cac so chia het cho 2: %d\n", bienDem);
        printf("Trung binh cong: %.2f\n", trungBinh);
    }
}

void kiemTraNguyenTo(void) {
    int x, i;
    int laNguyenTo = 1;

    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1) {
        printf("Du lieu nhap khong hop le!\n");
        return;
    }

    if (x < 2) {
        laNguyenTo = 0;
    } else {
        for (i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }
    }

    if (laNguyenTo) {
        printf("[%d] la so nguyen to.\n", x);
    } else {
        printf("[%d] khong phai la so nguyen to.\n", x);
    }
}

void kiemTraChinhPhuong(void) {
    int x, i;
    int laChinhPhuong = 0;

    printf("Nhap so nguyen x: ");
    if (scanf("%d", &x) != 1) {
printf("Du lieu nhap khong hop le!\n");
        return;
    }

    if (x >= 0) {
        for (i = 0; i <= x / (i + 1); i++) {
            if (i * i == x) {
                laChinhPhuong = 1;
                break;
            }
        }
    }

    if (laChinhPhuong) {
        printf("[%d] la so chinh phuong.\n", x);
    } else {
        printf("[%d] khong phai la so chinh phuong.\n", x);
    }
}
