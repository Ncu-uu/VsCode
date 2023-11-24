//为了使电文保密，往往按照一定规律将其转换成密码，收报人再按照约定的规律将其译回原文。例如有以下规律：将A变成E，a变成e，即变成其后第4个字母，W变成A，X变成B，Y变成C，Z变成D。任意输入一个字符串对其加密，完成程序。

 #include <stdio.h>
int main()
{ 
    char c;
    printf("please input a string::");
    while((c=getchar())!='\n')
    { 
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')
        {c=c+4;
        if(c>'Z'&&c<='Z'+4||c>'z')
            c=c-26;
        }
        printf("%c",c);
    }
    printf("\n\n");
    return 0;
}

// #include<stdio.h>
// int main()
// {
// 	char c;
// 	c=getchar();
// 	while(c!='\n')
// 	{
// 		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
// 		{
// 			if((c>='W'&&c<='Z')||(c>='w'&&c<='z')) c=c-22;
// 			else c=c+4;
// 		}
// 		printf("%c",c);
// 		c=getchar();
// 	}
// 	printf("\n");
// 	return 0;
// }
