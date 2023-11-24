//建立一个有三个结点的链表（静态链表），并进行输出。

#include<stdio.h>
#define NULL 0
struct student
{
    int num;
    float score;
    struct student *next;
};

int main()
{
    struct student a,b,c,*head,*p;
    a.num=99101;a.score=89.5;
    b.num=99103;b.score=90;
    c.num=99107;c.score=85;
    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    p=head;
    printf("\n\n\n");
    do
    {
        printf("%ld %5.1f\n",p->num,p->score);
        p=p->next;
    } while(p!=NULL);
    printf("\n\n\n");
    return 0;
}