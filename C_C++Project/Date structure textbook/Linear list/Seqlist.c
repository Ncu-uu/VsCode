#include <stdio.h>
#include <stdlib.h>

//定义抽象数据类型函数状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status; 
typedef int ElemType;

//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的分配增量
#define MAXSIZE 100         //顺序表的最大长度

typedef struct{
    ElemType *elem;         //存储空间基址
    int length;             //当前长度
}SeqList;

Status InitList_Sq(SeqList *L){
    //构造一个空的线性表L
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);    //存储分配失败
    L->length = 0;                  //空表长度为0
    return OK;
}

int main(int argc, char const *argv[])
{
    SeqList L;

    return 0;
}
