//打印形状为直角三角形的九九表
#include <stdio.h>
int main()
{
    int i,j,k;
    printf(" *");
    for(i=1;i<10;i++)
        printf("%4d",i);
    printf("\n");
    for(j=1;j<10;j++)
    {
        printf("%2d",j);
        for(k=1;k<=j;k++)
            printf("%4d",j*k);
        printf("\n");
    }
    return 0;
}