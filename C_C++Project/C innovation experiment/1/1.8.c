//编程求1-20的阶乘和
#include<stdio.h>

int main()
{
    int i,j;
    long long int sum=0;
    long long int fac=1;
    for(i=1;i<=20;i++)
    {
        fac=1;
        for(j=1;j<=i;j++)
            fac=fac*j;
        sum=sum+fac;
    }
    printf("sum=%lld\n",sum);

    return 0;
}
