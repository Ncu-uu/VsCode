//用选择法对数组中10个整数按由小到大排序。编写sort(int array[ ],int n)函数实现此功能。
#include <stdio.h>
void sort(int array[],int n)
{
    int i,j,k,t;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(array[j]<array[k])
            {
                k=j;
            }
        }
        if(i!=k)
        {
            t=array[k];array[k]=array[i];array[i]=t;
        }   
    }
}

int main()
{
    int a[10],i;
    printf("enter the array:\n");
    for(i=0;i<10;i++)
    scanf("%d",&a[i]);
    sort(a,10);
    printf("the sorted numbers:\n");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    printf("\n\n\n\n");
    return 0;

    
}

