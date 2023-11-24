//编写程序：从键盘输入三个数，让它们代表三条线段的长度。请写一个判断这三条线段所组成的三角形属于什么类型（不等边、等腰、等边或不能构成三角形）的C语言程序。
#include <stdio.h>
int main(){
    int a,b,c;
    printf("enter three numbers:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a){
        if(a==b&&b==c)printf("等边三角形\n");
        else if(a==b||b==c||a==c)printf("等腰三角形\n");
        else printf("不等边三角形\n");
    }
    else printf("不能构成三角形\n");
    return 0;
}