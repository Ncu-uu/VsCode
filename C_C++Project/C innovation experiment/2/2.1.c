//以下程序能判断任意年份是否是闰年
#include<stdio.h>

int main(){
    int year,leap;
    scanf("%d",&year);
    if(year%4==0&&year%100!=0||year%400==0)leap=1;
    else leap=0;
    if(leap)printf("%d is",year);
    else printf("%d is not",year);
    printf(" a leap year.\n");
    return 0;
}