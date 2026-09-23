#include <stdio.h>
int main() {
    float diemToan, diemLy, diemHoa, diemTB;
    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);
    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);
    printf(" Nhap diem Hoa: ");
    scanf("%f", &diemHoa);
    diemTB = (diemToan *3 + diemLy * 2 + diemHoa) /6;
    printf("Diem trung binh: %.2f\n", diemTB);
    return 0;
}