//输入三个字符串，要求找出最大者，完成程序。
#include <stdio.h>
#include <string.h>
int main()
{
    char max[20];
    char str[3][20];
    int i;
    for (i = 0; i < 3; i++)
    gets(str[i]);
    if(strcmp(str[0],str[1])>0) strcpy(max,str[0]);
    else strcpy(max,str[1]);
    if(strcmp(max,str[2])<0) strcpy(max,str[2]);
    printf("\nthe largest string is %s\n",max);
    return 0;
}