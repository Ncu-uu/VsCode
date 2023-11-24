//用起泡法对10个数排序（由小到大），完成程序。
#include <stdio.h>

int main()
{
    int a[10];
    int i,j,t;
    printf("input 10 numbers:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(i=0;i<9;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(a[j]>a[j+1])//如果前面的数比后面的数大，则交换
            {
                t=a[j];a[j]=a[j+1];a[j+1]=t;
            }
        }
    }
    printf("the sorted numbers:\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;

}