#include <stdio.h>
#define PI 3.14159
int main () {
float chieuDai, chieuRong;
float banKinh;
float chuViCN, dienTichCN;
float chuViTron, dienTichTron;
printf("Nhap chieu dai: ");
scanf("%f", &chieuDai);
printf("Nhap chieu rong: ");
scanf("%f", &chieuRong);
chuViCN = (chieuDai + chieuRong) * 2;
dienTichCN = chieuDai * chieuRong;
printf("Chu vi hinh chu nhat: %.2f\n", chuViCN);
printf("Dien tich hinh chu nhat: %.2f\n", dienTichCN);
printf("Nhap ban kinh: ");
scanf("%f", &banKinh);
chuViTron = 2 * PI * banKinh;
dienTichTron = PI * banKinh * banKinh;
printf("Chu vi hinh tron: %.2f\n", chuViTron);
printf("Dien tich hinh tron: %.2f\n", dienTichTron);
return 0;
}