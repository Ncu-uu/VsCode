//用四分之π的展开公式求π的近似值，直到最后一项的绝对值小于10-4为止。

#include<stdio.h>
#include<math.h>

int main()
{
    int s;
    float n,t,pi=0;
    t=n=s=1.0;
    while(fabs(t)>=1e-4)
    {
        pi=pi+t;
        n+=2;
        s=-s;
        t=s/n;
    }
    pi=pi*4;
    printf("pi=%f\n",pi);
    return 0;
}
