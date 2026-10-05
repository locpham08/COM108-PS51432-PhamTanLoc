#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Ham ho tro xoa bo nho dem ban phim
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ==========================================
// CHUC NANG 1: KIEM TRA SO NGUYEN[cite: 6]
// ==========================================
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int laSoChinhPhuong(int n) {
    if (n < 0) return 0;
    int sq = (int)sqrt(n);
    return (sq * sq == n);
}

void chucNang1() {
    printf("\n--- CHUC NANG 1: KIEM TRA SO NGUYEN ---\n");
    float x;
    printf("Nhap vao so x: ");
    if (scanf("%f", &x) != 1) {
        printf("Du lieu nhap khong hop le!\n");
        clearBuffer();
        return;
    }
    
    if (x == (int)x) {
        int n = (int)x;
        printf("-> %.0f la so nguyen.\n", x);
        
        if (laSoNguyenTo(n)) {
            printf("-> %d la so nguyen to.\n", n);
        } else {
            printf("-> %d khong phai la so nguyen to.\n", n);
        }
        
        if (laSoChinhPhuong(n)) {
            printf("-> %d la so chinh phuong.\n", n);
        } else {
            printf("-> %d khong phai la so chinh phuong.\n", n);
        }
    } else {
        printf("-> %g khong phai la so nguyen (la so thuc).\n", x);
    }
}

// ==========================================
// CHUC NANG 2: UOC SO CHUNG & BOI SO CHUNG[cite: 6]
// ==========================================
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int timBCNN(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / timUCLN(a, b);
}

void chucNang2() {
    printf("\n--- CHUC NANG 2: TIM UCLN VA BCNN ---\n");
    int x, y;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);
    printf("Nhap so nguyen y: ");
    scanf("%d", &y);
    
    printf("-> Uoc so chung lon nhat (UCLN) cua %d va %d la: %d\n", x, y, timUCLN(x, y));
    printf("-> Boi so chung nho nhat (BCNN) cua %d va %d la: %d\n", x, y, timBCNN(x, y));
}

// ==========================================
// CHUC NANG 3: TINH TIEN QUAN KARAOKE[cite: 5]
// ==========================================
void chucNang3() {
    printf("\n--- CHUC NANG 3: TINH TIEN QUAN KARAOKE ---\n");
    int gioBatDau, gioKetThuc;
    printf("Nhap gio bat dau (12 - 23): ");
    scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12 - 23): ");
    scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio khong hop le! Quan chi hoat dong tu 12h den 23h va gio ket thuc phai lon hon gio bat dau.\n");
        return;
    }

    int soGio = gioKetThuc - gioBatDau;
    double tongTien = 0;

    if (soGio <= 3) {
        tongTien = soGio * 150000;
    } else {
        tongTien = 3 * 150000 + (soGio - 3) * 150000 * 0.7; // Giam 30% tu gio thu 4[cite: 5]
    }

    // Giam them 10% neu bat dau trong khoang 14h - 17h[cite: 5]
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tongTien *= 0.9;
    }

    printf("-> Tong tien phai thanh toan: %.0f VND\n", tongTien);
}

// ==========================================
// CHUC NANG 4: TINH TIEN DIEN[cite: 4]
// ==========================================
void chucNang4() {
    printf("\n--- CHUC NANG 4: TINH TIEN DIEN ---\n");
    double kWh;
    printf("Nhap so kWh dien su dung: ");
    scanf("%lf", &kWh);

    if (kWh < 0) {
        printf("So kWh khong duoc nho hon 0!\n");
        return;
    }

    double tongTien = 0;
    if (kWh <= 50) {
        tongTien = kWh * 1678; // Bac 1[cite: 4]
    } else if (kWh <= 100) {
        tongTien = 50 * 1678 + (kWh - 50) * 1734; // Bac 2[cite: 4]
    } else if (kWh <= 200) {
        tongTien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014; // Bac 3[cite: 4]
    } else if (kWh <= 300) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536; // Bac 4[cite: 4]
    } else if (kWh <= 400) {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834; // Bac 5[cite: 4]
    } else {
        tongTien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927; // Bac 6[cite: 4]
    }

    printf("-> So tien dien phai tra: %.0f dong\n", tongTien);
}

// ==========================================
// CHUC NANG 5: DOI TIEN[cite: 4]
// ==========================================
void chucNang5() {
    printf("\n--- CHUC NANG 5: CHUC NANG DOI TIEN ---\n");
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1}; // Cac menh gia[cite: 4]
    int n = sizeof(menhGia) / sizeof(menhGia[0]);
    int tien;

    printf("Nhap vao so tien can doi: ");
    scanf("%d", &tien);

    if (tien <= 0) {
        printf("So tien phai lon hon 0!\n");
        return;
    }

    printf("-> So to tien doi duoc:\n");
    for (int i = 0; i < n; i++) {
        int soTo = tien / menhGia[i];
        if (soTo > 0) {
            printf("   - %d to %d\n", soTo, menhGia[i]);
            tien %= menhGia[i];
        }
    }
}

// ==========================================
// CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG TRA GOP[cite: 3]
// ==========================================
void chucNang6() {
    printf("\n--- CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG TRA GOP ---\n");
    double soTienVay;
    printf("Nhap so tien muon vay (VND): ");
    scanf("%lf", &soTienVay);

    if (soTienVay <= 0) {
        printf("So tien vay phai lon hon 0!\n");
        return;
    }

    double gocPhaiTra = soTienVay / 12; // Tra trong 12 thang[cite: 3]
    double soTienConLai = soTienVay;

    printf("\n| %-7s | %-15s | %-15s | %-15s | %-15s |\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "So tien con lai");
    printf("----------------------------------------------------------------------------------------\n");

    for (int kyHan = 1; kyHan <= 12; kyHan++) {
        double laiPhaiTra = soTienConLai * 0.05; // Lai suat 5%/thang[cite: 3]
        double soTienPhaiTra = laiPhaiTra + gocPhaiTra;
        soTienConLai -= gocPhaiTra;
        if (soTienConLai < 0) soTienConLai = 0;

        printf("| %-7d | %-15.0f | %-15.0f | %-15.0f | %-15.0f |\n", 
               kyHan, laiPhaiTra, gocPhaiTra, soTienPhaiTra, soTienConLai);
    }
}

// ==========================================
// CHUC NANG 7: VAY TIEN MUA XE[cite: 2]
// ==========================================
void chucNang7() {
    printf("\n--- CHUC NANG 7: XAY DUNG CHUONG TRINH VAY TIEN MUA XE ---\n");
    double phanTramVay;
    printf("Nhap %% vay toi da (vi du nhap 80 cho 80%%): "); //[cite: 2]
    scanf("%lf", &phanTramVay);

    if (phanTramVay <= 0 || phanTramVay > 100) {
        printf("Phan tram vay khong hop le!\n");
        return;
    }

    double giaTriXe = 500000000.0 / (phanTramVay / 100.0); // Co dinh khoan vay 500 trieu[cite: 2]
    double tienTraLanDau = giaTriXe - 500000000.0;
    
    int thoiHanVayNam = 24; // 24 nam[cite: 2]
    int tongSoThang = thoiHanVayNam * 12; // 288 thang
    double laiSuatNam = 0.072; // 7.2%/nam[cite: 2]
    double laiSuatThang = laiSuatNam / 12.0;

    double gocPhaiTraHangThang = 500000000.0 / tongSoThang;
    double tienPhaiTraThangDau = gocPhaiTraHangThang + (500000000.0 * laiSuatThang);

    printf("-> Gia tri xe uoc tinh: %.0f VND\n", giaTriXe);
    printf("-> So tien phai tra lan dau (tra truoc): %.0f VND\n", tienTraLanDau);
    printf("-> So tien phai tra thang dau tien: %.0f VND\n", tienPhaiTraThangDau);
    printf("-> Tien goc co dinh hang thang: %.0f VND (Lai giam dan theo du no thuc te)\n", gocPhaiTraHangThang);
}

// ==========================================
// CHUC NANG 8: SAP XEP THONG TIN SINH VIEN[cite: 2]
// ==========================================
typedef struct {
    char hoTen[50];
    float diem;
    char hocLuc[20];
} SinhVien;

void xepLoaiHocLuc(SinhVien *sv) {
    if (sv->diem >= 9.0) strcpy(sv->hocLuc, "Xuat sac"); //[cite: 2]
    else if (sv->diem >= 8.0) strcpy(sv->hocLuc, "Gioi"); //[cite: 2]
    else if (sv->diem >= 6.5) strcpy(sv->hocLuc, "Kha"); //[cite: 2]
    else if (sv->diem >= 5.0) strcpy(sv->hocLuc, "Trung binh"); //[cite: 2]
    else strcpy(sv->hocLuc, "Yeu"); //[cite: 2]
}

void chucNang8() {
    printf("\n--- CHUC NANG 8: SAP XEP THONG TIN SINH VIEN ---\n");
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    clearBuffer();

    if (n <= 0) {
        printf("So luong sinh vien phai lon hon 0!\n");
        return;
    }

    SinhVien ds[n];
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf(" - Ho va ten: ");
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = 0; // Xoa ky tu xong dong
        
        printf(" - Diem: ");
        scanf("%f", &ds[i].diem);
        clearBuffer();

        xepLoaiHocLuc(&ds[i]);
    }

    // Sap xep giam dan theo diem[cite: 2]
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\n--- DANH SACH SINH VIEN DA SAP XEP (GIAM DAN THEO DIEM) ---\n");
    printf("%-25s | %-10s | %-15s\n", "Ho va ten", "Diem", "Hoc luc");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-25s | %-10.1f | %-15s\n", ds[i].hoTen, ds[i].diem, ds[i].hocLuc);
    }
}

// ==========================================
// CHUC NANG 9: GAME FPOLY-LOTT (2/15)[cite: 1]
// ==========================================
void chucNang9() {
    printf("\n--- CHUC NANG 9: GAME FPOLY-LOTT (2/15) ---\n");
    int so1, so2;
    printf("Nhap so thu nhat (01 - 15): ");
    scanf("%d", &so1);
    printf("Nhap so thu hai (01 - 15): ");
    scanf("%d", &so2);

    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15) {
        printf("So nhap vao khong hop le! Vui long nhap tu 01 den 15.\n");
        return;
    }

    srand(time(NULL));
    int kq1 = rand() % 15 + 1; //[cite: 1]
    int kq2 = rand() % 15 + 1; //[cite: 1]

    printf("-> Ket qua he thong quay so: %02d - %02d\n", kq1, kq2);

    int trung = 0;
    if (so1 == kq1 || so1 == kq2) trung++;
    if (so2 == kq1 || so2 == kq2) trung++;

    if (trung == 2) {
        printf("-> Chuc mung ban da trung giai nhat!\n"); //[cite: 1]
    } else if (trung == 1) {
        printf("-> Chuc mung ban da trung giai nhi!\n"); //[cite: 1]
    } else {
        printf("-> Chuc ban may man lan sau!\n"); //[cite: 1]
    }
}

// ==========================================
// CHUC NANG 10: TINH TOAN PHAN SO[cite: 1]
// ==========================================
typedef struct {
    int tu;
    int mau;
} PhanSo;

void rutGon(PhanSo *ps) {
    int ucln = timUCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
    if (ps->mau < 0) {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
}

void inPhanSo(PhanSo ps) {
    rutGon(&ps);
    if (ps.mau == 1) {
        printf("%d", ps.tu);
    } else {
        printf("%d/%d", ps.tu, ps.mau);
    }
}

void chucNang10() {
    printf("\n--- CHUC NANG 10: TINH TOAN PHAN SO ---\n");
    PhanSo ps1, ps2;

    printf("Nhap phan so 1 (Tu va Mau): ");
    scanf("%d%d", &ps1.tu, &ps1.mau);
    printf("Nhap phan so 2 (Tu va Mau): ");
    scanf("%d%d", &ps2.tu, &ps2.mau);

    if (ps1.mau == 0 || ps2.mau == 0) {
        printf("Mau so phai khac 0!\n");
        return;
    }

    // Tong
    PhanSo tong = {ps1.tu * ps2.mau + ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    // Hieu
    PhanSo hieu = {ps1.tu * ps2.mau - ps2.tu * ps1.mau, ps1.mau * ps2.mau};
    // Tich
    PhanSo tich = {ps1.tu * ps2.tu, ps1.mau * ps2.mau};
    
    printf("\nKet qua tinh toan:\n"); //[cite: 1]
    printf(" - Tong: "); inPhanSo(tong); printf("\n");
    printf(" - Hieu: "); inPhanSo(hieu); printf("\n");
    printf(" - Tich: "); inPhanSo(tich); printf("\n");

    // Thuong
    if (ps2.tu == 0) {
        printf(" - Thuong: Khong the chia cho 0\n");
    } else {
        PhanSo thuong = {ps1.tu * ps2.mau, ps1.mau * ps2.tu};
        printf(" - Thuong: "); inPhanSo(thuong); printf("\n");
    }
}

// ==========================================
// MAN HINH MENU CHINH[cite: 6]
// ==========================================
int main() {
    int luaChon;
    do {
        printf("\n=======================================================\n");
        printf("                MENU MON NHAP MON LAP TRINH             \n");
        printf("=======================================================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va Boi so chung cua 2 so\n");
        printf("3. Chuong trinh tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT (2/15)\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("-------------------------------------------------------\n");
        printf("Xin moi chon chuc nang (0-10): ");
        
        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le! Vui long nhap so.\n");
            clearBuffer();
            continue;
        }

        switch (luaChon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh! Tam biet.\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon tu 0 den 10.\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}