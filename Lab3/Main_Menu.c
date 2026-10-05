#include <stdio.h>
#include <math.h>

// Hàm cho Bài 2: Tính học lực sinh viên
void tinhHocLuc() {
    float diem;
    printf("\n--- TINH HOC LUC SINH VIEN ---\n");
    printf("Nhap vao diem so (0.0 - 10.0): ");
    
    if (scanf("%f", &diem) != 1) {
        printf("Diem so nhap vao khong hop le!\n");
        // Xóa bộ nhớ đệm bàn phím nếu nhập sai kiểu dữ liệu
        while (getchar() != '\n');
        return;
    }

    // Bắt lỗi đầu vào nằm ngoài khoảng 0.0 - 10.0
    if (diem < 0.0 || diem > 10.0) {
        printf("Diem so nhap vao khong hop le!\n");
    } else if (diem >= 9.0) {
        printf("Hoc luc: Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Hoc luc: Gioi\n");
    } else if (diem >= 6.5) {
        printf("Hoc luc: Kha\n");
    } else if (diem >= 5.0) {
        printf("Hoc luc: Trung binh\n");
    } else if (diem >= 3.5) {
        printf("Hoc luc: Yeu\n");
    } else {
        printf("Hoc luc: Kem\n");
    }
}

// Hàm cho Bài 3: Giải phương trình bậc hai
void giaiPTBacHai() {
    float a, b, c;
    printf("\n--- GIAI PHUONG TRINH BAC HAI ---\n");
    printf("Nhap vao 3 he so a, b, c: ");
    
    if (scanf("%f %f %f", &a, &b, &c) != 3) {
        printf("Du lieu nhap vào khong hop le!\n");
        while (getchar() != '\n');
        return;
    }

    if (a == 0) {
        // Trường hợp a = 0 -> phương trình bx + c = 0
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh co vo so nghiem.\n");
            } else {
                printf("Phuong trinh vo nghiem.\n");
            }
        } else {
            float x = -c / b;
            printf("Phuong trinh co nghiem duy nhat: x = %.2f\n", x);
        }
    } else {
        // Trường hợp a != 0 -> tính Delta
        float delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phuong trinh vo nghiem.\n");
        } else if (delta == 0) {
            float x = -b / (2 * a);
            printf("Phuong trinh co nghiem kep: x = %.2f\n", x);
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
    }
}

// Hàm cho Bài 4: Tính tiền điện tiêu thụ
void tinhTienDien() {
    float kwh;
    printf("\n--- TINH TIEN DIEN TIEU THU ---\n");
    printf("Nhap tong so kWh dien tieu thu trong thang: ");
    
    if (scanf("%f", &kwh) != 1 || kwh <= 0) {
        printf("So kWh phai la so duong va hop le!\n");
        while (getchar() != '\n');
        return;
    }

    double tongTien = 0.0;

    // Tính tiền điện theo phương pháp lũy tiến từng bậc
    if (kwh <= 50) {
        tongTien = kwh * 1678;
    } else if (kwh <= 100) {
        tongTien = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        tongTien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }

    printf("Tong tien dien phai tra: %.0f dong\n", tongTien);
}

// Hàm main chứa Menu chính điều khiển chương trình (Bài 1)
int main() {
    int luaChon;

    do {
        printf("\n===== MENU CHUONG TRINH LAB 3 =====\n");
        printf("1. Tinh hoc luc sinh vien\n");
        printf("2. Giai phuong trinh bac hai\n");
        printf("3. Tinh tien dien tieu thu\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); // Xóa bộ nhớ đệm
            continue;
        }

        switch (luaChon) {
            case 1:
                tinhHocLuc();
                break;
            case 2:
                giaiPTBacHai();
                break;
            case 3:
                tinhTienDien();
                break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long nhap lai.\n");
                break;
        }

    } while (luaChon != 0);

    return 0;
}