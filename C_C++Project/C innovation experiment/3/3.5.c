#include <stdio.h>

int isprime(int n);

int main() {
    int n, i, flag = 0;
    printf("请输入一个大的偶数: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; ++i) {
        if (isprime(i) == 1) {
            if (isprime(n - i) == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        printf("%d cannot be expressed as the sum of two prime numbers.", n);
    }
    return 0;
}

int isprime(int n) {
    int i, flag = 1;
    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}
