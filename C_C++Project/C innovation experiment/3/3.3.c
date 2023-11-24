
int Len=100;

void del_str(char a[],char b[],int n)
{
    int i,j=0;
    for(i=0;i<Len;i++)
    {
        if(i != n-1)
        {
            b[j] = a[i]; 
            j++;
            b[j] = '\0';
        }
    }
    
    
}
#include<stdio.h>
int main() {
    char str1[100],str2[100];
    int n;
    printf("enter the string:");

    gets(str1);
    printf("enter the position of the string deleted:");
    scanf("%d",&n);
    del_str(str1,str2,n);
    printf("the new string is:%s\n",str2);

    // for (int i = 0; i < 100 ; i++)
    // {
    //     printf("%c ",str2[i]);
    // }
    // printf("\n");
    
    
}