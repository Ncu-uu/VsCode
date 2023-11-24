//从一个三行四列的矩阵中找出最小的那个元素的值，以及它所在的行号和列号

#include<stdio.h>

int main()
{
    int i,j,row=0,colum=0,min;
    int a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
    min=a[0][0];
    for(i=0;i<=2;i++)
        for(j=0;j<=3;j++)
            if(a[i][j]<min)
            {
                min=a[i][j];
                row=i;
                colum=j;
            }
    printf("min=%d\nrow=%d\ncolum=%d\n",min,row,colum);
    return 0;
}
