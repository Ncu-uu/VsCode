//编写c语言程序解决：N是一个四位数，它的9倍恰好是其反序数(例如:1234的反序数是4321)，求N的值。
#include<stdio.h>

int main()
{
    int n;
    for(n=1000;n<10000;n++)
    {
        if(n*9==((n%10)*1000+(n/10%10)*100+(n/100%10)*10+n/1000))
        {
            printf("N=%d\n\n",n);
        }
    }
    return 0;
}