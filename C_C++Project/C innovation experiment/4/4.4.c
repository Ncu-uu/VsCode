#include <stdio.h>

int main() {
    float arr[100];
    int n, i, j;
    float num;

    printf("请输入数组长度（不超过100）：");
    scanf("%d", &n);

    printf("请输入升序的浮点型数组：\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("请输入要插入的数字：");
    scanf("%f", &num);

    // 找到要插入的位置
    for (i = 0; i < n; i++) {
        if (num < arr[i]) {
            break;
        }
    }

    // 将数字插入到数组中
    for (j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = num;
    n++;

    printf("插入后的数组为：\n");
    for (i = 0; i < n; i++) {
        printf("%.2f  ", arr[i]);
    }
    printf("\n\n\n\n");

    return 0;
}
