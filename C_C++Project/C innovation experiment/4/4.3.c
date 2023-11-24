//将一个数组中的值按照逆序重新存放。例如，原来顺序为6，5，4，3，2。要求改为2，3，4，5，6。

#define LEN 10
#include<stdio.h>
int main()
{
    int a[LEN],b[LEN],i,j;
    for(i=0;i<LEN;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0,j=LEN-1;i<LEN;i++,j--)
    {
        b[j]=a[i];
    }
    for(i=0;i<LEN;i++)
    a[i]=b[i];
    for(i=0;i<LEN;i++)
    printf("%d ",a[i]);
    printf("\n\n\n\n");
    return 0;
}