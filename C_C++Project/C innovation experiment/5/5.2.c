//设有三个候选人，每次输入一个得票的候选人的名字，要求最后输出各人的得票结果，完成程序。

#include <stdio.h>
#include <string.h>
struct person
{
    char name[20];
    int count;
}candidate[3]={"Li",0,"Zhang",0,"Wang",0};

int main()
{
    int i,j;
    char inputname[20];
    for(i=1;i<=10;i++)
    {
        scanf("%s",inputname);
        for(j=0;j<3;j++)
        {
            if(strcmp(inputname,candidate[j].name)==0)
            // if(inputname==candidate[j].name)
            {
                // candidate[j].count++;
                candidate[j].count=candidate[j].count+1;
            }

        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("%5s:%d\n",candidate[i].name,candidate[i].count);
    }
    return 0;
}