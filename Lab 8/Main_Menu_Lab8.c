#include <stdio.h>
#include <string.h>

// Định nghĩa struct SinhVien
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// Khai báo nguyên mẫu hàm (Function Prototypes)
void xoaBoDem();
void loaiBoXuongDong(char s[]);
void nhapXuatDanhSach(struct SinhVien ds[], int *n);
void sapXepTheoDiem(struct SinhVien ds[], int n);
void timKiemTheoMSSV(struct SinhVien ds[], int n);
void xuatHocBongTheoNganh(struct SinhVien ds[], int n);

void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void loaiBoXuongDong(char s[]) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

// --- Bài 1: Nhập và xuất danh sách sinh viên ---
void nhapXuatDanhSach(struct SinhVien ds[], int *n) {
    printf("\n--- CHUC NANG 1: NHAP VA XUAT DANH SACH SINH VIEN ---\n");
    printf("Nhap so luong sinh vien (toi da 50): ");
    scanf("%d", n);

    if (*n <= 0 || *n > 50) {
        printf("So luong sinh vien khong hop le!\n");
        *n = 0;
        return;
    }

    for (int i = 0; i < *n; i++) {
        printf("\nNhap thong tin sinh vien thu [%d]:\n", i + 1);
        printf("MSSV: ");
        xoaBoDem();
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        loaiBoXuongDong(ds[i].mssv);

        printf("Ten SV: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        loaiBoXuongDong(ds[i].tenSV);

        printf("Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        loaiBoXuongDong(ds[i].nganhHoc);

        do {
            printf("Diem TB (0.0 - 10.0): ");
            scanf("%f", &ds[i].diemTB);
            if (ds[i].diemTB < 0.0f || ds[i].diemTB > 10.0f) {
                printf("Diem khong hop le, vui long nhap lai!\n");
            }
        } while (ds[i].diemTB < 0.0f || ds[i].diemTB > 10.0f);
    }

    printf("\n=== DANH SACH SINH VIEN ===\n");
    for (int i = 0; i < *n; i++) {
        printf("Sinh vien thu [%d]:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n", ds[i].diemTB);
    }
}

// --- Bài 2: Sắp xếp sinh viên theo điểm tăng dần ---
void sapXepTheoDiem(struct SinhVien ds[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap danh sach sinh vien truoc.\n");
        return;
    }

    printf("\n--- CHUC NANG 2: SAP XEP SINH VIEN THEO DIEM TANG DAN ---\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTB > ds[j].diemTB) {
                struct SinhVien svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("\n=== DANH SACH SAU KHI SAP XEP ===\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien thu [%d]:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n", ds[i].diemTB);
    }
}

// --- Bài 3: Tìm kiếm sinh viên theo MSSV ---
void timKiemTheoMSSV(struct SinhVien ds[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap danh sach sinh vien truoc.\n");
        return;
    }

    char mssvTim[50];
    printf("\n--- CHUC NANG 3: TIM KIEM SINH VIEN THEO MSSV ---\n");
    printf("Nhap MSSV can tim: ");
    xoaBoDem();
    fgets(mssvTim, sizeof(mssvTim), stdin);
    loaiBoXuongDong(mssvTim);

    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssvTim) == 0) {
            printf("Tim thay sinh vien:\n");
            printf("MSSV: %s\n", ds[i].mssv);
            printf("Ten SV: %s\n", ds[i].tenSV);
            printf("Nganh hoc: %s\n", ds[i].nganhHoc);
            printf("Diem TB: %.2f\n", ds[i].diemTB);
            timThay = 1;
            break;
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien co MSSV: %s\n", mssvTim);
    }
}

// --- Bài 4: Xuất sinh viên nhận học bổng theo ngành ---
void xuatHocBongTheoNganh(struct SinhVien ds[], int n) {
    if (n == 0) {
        printf("\nDanh sach rong! Vui long nhap danh sach sinh vien truoc.\n");
        return;
    }

    printf("\n--- CHUC NANG 4: XUAT SINH VIEN NHAN HOC BONG THEO NGANH ---\n");
    
    int coHocBong = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0f) {
            coHocBong = 1;
            break;
        }
    }

    if (!coHocBong) {
        printf("Khong co sinh vien nao dat hoc bong.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0f) {
            // Kiểm tra xem ngành học này đã được in ở các vị trí trước chưa
            int daIn = 0;
            for (int k = 0; k < i; k++) {
                if (ds[k].diemTB >= 8.0f && strcmp(ds[k].nganhHoc, ds[i].nganhHoc) == 0) {
                    daIn = 1;
                    break;
                }
            }

            // Nếu ngành chưa được in, tiến hành in nhóm theo ngành
            if (!daIn) {
                printf("Nganh: %s\n", ds[i].nganhHoc);
                for (int j = 0; j < n; j++) {
                    if (ds[j].diemTB >= 8.0f && strcmp(ds[j].nganhHoc, ds[i].nganhHoc) == 0) {
                        printf("- %s - %s - Diem TB: %.2f\n", ds[j].mssv, ds[j].tenSV, ds[j].diemTB);
                    }
                }
            }
        }
    }
}

int main() {
    struct SinhVien ds[50];
    int n = 0;
    int luaChon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 8              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien               |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan           |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV                   |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh        |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapXuatDanhSach(ds, &n);
                break;
            case 2:
                sapXepTheoDiem(ds, n);
                break;
            case 3:
                timKiemTheoMSSV(ds, n);
                break;
            case 4:
                xuatHocBongTheoNganh(ds, n);
                break;
            case 5:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon lai tu 1 den 5.\n");
                break;
        }
    } while (luaChon != 5);

    return 0;
}