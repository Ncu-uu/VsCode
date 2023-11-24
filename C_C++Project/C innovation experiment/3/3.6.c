#include <stdio.h>

int main() {
    int num, max = 0, count = 0;
    printf("请输入一个整数：");
    scanf("%d", &num);
    while (num > 0) {
        int digit = num % 10;
        if (digit == 0) {
            count++;
        } else if (digit > max) {
            max = digit;
        }
        num /= 10;
    }
    printf("0的个数为:%d\n", count);
    printf("最大的数字为:%d\n", max);
    return 0;
}
