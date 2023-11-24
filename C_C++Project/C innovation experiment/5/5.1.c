//通过指针实现按序输出任意两个整数，完成程序。
#include <stdio.h>

int main()
{
    int *p,*p1,*p2,a,b;
    scanf("%d,%d",&a,&b);
    p1=&a;
    p2=&b;
    if(a<b)
    {
        p=p1;
        p1=p2;
        p2=p;
    }
    printf("\na=%d,b=%d\n",a,b);
    printf("the max is %d,the min is %d\n\n\n",*p1,*p2);
    return 0;
}