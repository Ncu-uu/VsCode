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
    L = new LNode;      // 生成新结点作为头结点，用头指针L指向头结点
    L -> next = NULL;   // 头结点的指针域置空
    return OK;
}

// 头插法建立单链表
Status createLinkListHead(LinkList &L, int n){
    L = new LNode;
    L -> next = NULL;
    for(int i = 0; i < n; i++){
        LNode *p = new LNode;
        scanf("%d", &p -> data);
        p -> next = L -> next;
        L -> next = p;
    }
    return OK;
}

// 尾插法建立单链表
Status createLinkListTail(LinkList &L, int n){
    L = new LNode;
    L -> next = NULL;
    LNode *r = L;
    for(int i = 0; i < n; i++){
        LNode *p = new LNode;
        scanf("%d", &p -> data);
        p -> next = NULL;
        r -> next = p;
        r = p;
    }
    return OK;
}

// 取值
Status getElem(LinkList L, int i, ElemType &e){
    // 根据序号i，用e返回L中第i个数据元素的值
    LNode *p = L -> next;
    int j = 1;
    while(p && j < i){
        p = p -> next;
        j++;
    }
    if(!p || j > i) return ERROR;
    e = p -> data;
    return OK;
}