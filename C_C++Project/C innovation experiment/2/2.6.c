//编写一个程序，输出100-500之间全部素数的和
#include<stdio.h>

int main(){
    int i,j,sum=0;
    for(i=100;i<=500;i++){
        for(j=2;j<i;j++){
            if(i%j==0)break;
        }
        if(j==i)sum+=i;
    }
    printf("100-500之间全部素数的和为%d\n\n\n",sum);
    return 0;
}