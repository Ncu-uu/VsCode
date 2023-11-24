#include <stdio.h>

#define ROW 3
#define COL 4

int main() {
    int a[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int i, j, k, flag;

    for (i = 0; i < ROW; i++) {
        int max = a[i][0];
        int col = 0;
        for (j = 1; j < COL; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                col = j;
            }
        }
        flag = 1;
        for (k = 0; k < ROW; k++) {
            if (a[k][col] < max) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("鞍点为:a[%d][%d]\n", i, col);
            printf("值为:%d\n",max);
            break;
        }
    }
    if (!flag) {
        printf("该二维数组中没有鞍点\n");
    }

    return 0;
}
