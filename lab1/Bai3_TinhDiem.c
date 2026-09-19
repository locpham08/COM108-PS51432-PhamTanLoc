#include <stdio.h>

int main() {
    char mssv[] = "PS51432";
    char hoTen[] = "Pham Tan Loc";

    float diemToan = 8.0;
    float diemLy = 7.5;
    float diemHoa = 7.0;

    float diemTB = (diemToan * 2 + diemLy + diemHoa) / 4;

    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho va ten: %s\n", hoTen);
    printf("Diem trung binh: %.2f\n", diemTB);

    return 0;
}