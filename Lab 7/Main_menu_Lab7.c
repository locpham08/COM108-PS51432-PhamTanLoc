#include <stdio.h>
#include <string.h>
#include <ctype.h>

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

// Khai báo nguyên mẫu hàm (Function Prototypes)
void xoaBoDem();
void loaiBoXuongDong(char s[]);
void demNguyenAmPhuAm();
void dangNhap();
void sapXepChuoi();
void daoChuoi(char s[]);
void doiThapPhanSangHexa();

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

// --- Bài 1: Đếm nguyên âm và phụ âm của chuỗi ---
void demNguyenAmPhuAm() {
    char s[200];
    printf("\n--- CHUC NANG 1: DEM NGUYEN AM VA PHU AM CUA CHUOI ---\n");
    printf("Nhap chuoi: ");
    xoaBoDem();
    fgets(s, sizeof(s), stdin);
    loaiBoXuongDong(s);

    int nguyenAm = 0, phuAm = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower((unsigned char)s[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                nguyenAm++;
            } else {
                phuAm++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n", s, nguyenAm, phuAm);
}

// --- Bài 2: Đăng nhập bằng Username và Password (Ẩn ký tự) ---
void dangNhap() {
    char user[50], pass[50];
    int idx = 0;
    char ch;

    printf("\n--- CHUC NANG 2: DANG NHAP BANG USERNAME VA PASSWORD ---\n");
    printf("Nhap username: ");
    xoaBoDem();
    fgets(user, sizeof(user), stdin);
    loaiBoXuongDong(user);

    printf("Nhap password: ");
    while (1) {
        ch = getch();
        if (ch == '\r' || ch == '\n') { // Nhấn Enter
            pass[idx] = '\0';
            printf("\n");
            break;
        } else if (ch == 8 || ch == 127) { // Nhấn Backspace
            if (idx > 0) {
                idx--;
                printf("\b \b");
            }
        } else {
            if (idx < (int)sizeof(pass) - 1) {
                pass[idx++] = ch;
                printf("*");
            }
        }
    }

    if (strcmp(user, "admin") == 0 && strcmp(pass, "12345") == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

// --- Bài 3: Sắp xếp chuỗi theo thứ tự chữ cái ---
void sapXepChuoi() {
    char s[5][20];
    char temp[20];

    printf("\n--- CHUC NANG 3: SAP XEP CHUOI THEO CHU CAI ---\n");
    xoaBoDem();
    for (int i = 0; i < 5; i++) {
        printf("Nhap chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        loaiBoXuongDong(s[i]);
    }

    // Sắp xếp Bubble Sort / Lồng 2 vòng lặp
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("Cac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

// Hàm hỗ trợ đảo ngược chuỗi
void daoChuoi(char s[]) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

// --- Bài 4: Đổi số thập phân sang số thập lục phân (Hexa) ---
void doiThapPhanSangHexa() {
    long long n;
    printf("\n--- CHUC NANG 4: DOI SO THAP PHAN SANG THAP LUC PHAN ---\n");
    printf("Nhap so thap phan không am: ");
    scanf("%lld", &n);

    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    if (n == 0) {
        printf("So thap luc phan cua 0 la: 0\n");
        return;
    }

    long long tempN = n;
    char hexa[100] = "";
    char traCuu[] = "0123456789ABCDEF";
    int idx = 0;

    while (tempN > 0) {
        int du = tempN % 16;
        hexa[idx++] = traCuu[du];
        tempN /= 16;
    }
    hexa[idx] = '\0';

    daoChuoi(hexa);
    printf("So thap luc phan cua %lld la: %s\n", n, hexa);
}

int main() {
    int luaChon;

    do {
        printf("\n+---------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB 7              |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi              |\n");
        printf("| 2. Dang nhap bang Username va Password            |\n");
        printf("| 3. Sap xep chuoi theo chu cai                     |\n");
        printf("| 4. Doi so thap phan sang thap luc phan            |\n");
        printf("| 5. Thoat chuong trinh                             |\n");
        printf("+---------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                dangNhap();
                break;
            case 3:
                sapXepChuoi();
                break;
            case 4:
                doiThapPhanSangHexa();
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