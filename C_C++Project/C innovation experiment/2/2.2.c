//递增的牛群：若一头小母牛，从第四年开始每年生一头母牛，按此规律，第n年时有多少头母牛。
#include<stdio.h>

int main()
{
    int i,year,f,f1,f2,f3;
    printf("enter year.");
    scanf("%d",&year);
    for(i=1;i<=year;i++)
    {
        if(i<4)f=f1=f2=f3=1;
        else{f=f1+f3;f3=f2;f2=f1;f1=f;}
        printf("i=%2d,n=%3d\n",i,f);
    }
    
    return 0;
}

// #include <stdio.h>
// main()
// {
// 	int n,i,f1=1,f2=1,f3=1,f4,t;
// 	scanf("%d",&n);
// 	for (i=4;i<=n;i++)
// 	{
// 		f4=f1+f3;
// 		f1=f2;
// 		f2=f3;
// 	    f3=f4;
		
// 	}
// 	printf("%d",f4);
 
// }