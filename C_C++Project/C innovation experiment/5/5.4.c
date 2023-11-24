//输入下面链表的建立程序，调试运行，给出运行的结果。
#include<stdio.h>
#include<stdlib.h>

struct LNode
{
    int data;
    struct LNode *next;
};

struct LNode * creat(int n)
{
    int i;
    struct LNode *head,*p1,*p2;
    /*head用来标记链表，p1总是用来指向新分配的内存空间，p2总是指向尾结点，并通过p2来链入新分配的结点*/
    int a;
    head=NULL;
    for(i=1;i<=n;i++)
    {
        p1=(struct LNode *)malloc(sizeof(struct LNode));

        printf("请输入链表中第%d个数：",i);
        scanf("%d",&a);
        p1->data=a;
        if(head==NULL)
        {
            head=p1;
            p2=p1;
        }
        else
        {
            p2->next=p1;
            p2=p1;
        }
        p2->next=NULL;
    }
    return head;
}

int main()
{
    int n;
    struct LNode *q;
    printf("请输入链表的长度：");
    scanf("%d",&n);
    q=creat(n);
    printf("\n链表中的数据：\n");
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n\n\n");
}
