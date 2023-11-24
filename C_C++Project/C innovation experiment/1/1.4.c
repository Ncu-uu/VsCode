//编程实现找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小。也可能没有鞍点。
#include<stdio.h>

int main()
{
    int i,j,k,row=0,colum=0,max,min,a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,5}};
    for(i=0;i<=2;i++)
    {
        max=a[i][0];
        for(j=0;j<=3;j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                row=i;
                colum=j;
            }
        min=a[0][colum];
        for(k=0;k<=2;k++)
            if(a[k][colum]<min)
                min=a[k][colum];
        if(max==min)
        {
            printf("鞍点为:a[%d][%d]\n",row,colum);
            printf("值为:%d\n",max);
            break;
        }
    }
    if(i>2)
        printf("no\n");
    return 0;
}
