#include<stdio.h>
#include<stdlib.h>

// 定义抽象数据类型函数状态代码
#define BOOL int
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status; 
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// 初始化链表
Status initLinkList(LinkList &L){
    L = new LNode;
}
