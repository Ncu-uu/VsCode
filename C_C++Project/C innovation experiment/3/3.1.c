//统计100以内的全部素数个数并逐个输出。
#include<math.h>
#include<stdio.h>

int main()
{
    int m,k,i,num=0;
    printf("2 ");
    for(m=3;m<100;m+=2)
    {   k=sqrt(m);
        for(i=2;i<=k;i++)
            if(m%i==0)break;
        if(i>k){printf("%d ",m);num++;}
    }
    if(num%10==0)printf("\n");
    printf("\n\n\n");
    return 0;
}