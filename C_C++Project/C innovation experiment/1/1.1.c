#include<stdio.h>

int main()
{
    float a,b,c;
    printf("please input two number：");
    scanf("%f%f",&a,&b);
    if(a<b)c=a;
    else c=b;
    printf("the smaller is %f\n",c);
    return 0;
}