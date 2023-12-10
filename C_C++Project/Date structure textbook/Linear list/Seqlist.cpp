#include <stdio.h>
#include <stdlib.h>

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

// 线性表的顺序存储结构最大长度
#define MAXSIZE 100         //顺序表的最大长度

typedef struct{
    ElemType *elem;         //存储空间基址
    int length;             //当前长度
}SeqList;

// 构造一个空的线性表L
Status initSeqList(SeqList &L){
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);     //存储分配失败
    L.length = 0;                   //空表长度为0
    return OK;
}

// 判断是否为空表
BOOL isEmpty(SeqList L){
    if(L.length == 0) return TRUE;
    else return FALSE;
}

// 判断是否为满表
BOOL isFull(SeqList L){
    if(L.length == MAXSIZE) return TRUE;
    else return FALSE;
}

// 求线性表的长度
int getLength(SeqList L){
    return L.length;
}

// 根据指定的位置序号i，获取第i个元素的值
Status getElem(SeqList L, int i, ElemType &e){
    if(i < 1 || i > L.length) return ERROR; // 判断i的范围是否有效，若无效则返回ERROR
    e = L.elem[i-1];                        // 将第i个元素的值赋给e
    return OK;      //时间复杂度为O(1)
}

// 根据指定的元素值e，查找顺序表中第一个与e相等的元素。
// 若找到，则返回该元素在表中的位置序号，否则返回0
int locateElem(SeqList L, ElemType e){
    int i;
    for(i = 0; i < L.length; i++){
        if(L.elem[i] == e) return i+1; // 若找到，则返回该元素在表中的位置i+1
    }
    return 0;
}                                       // 时间复杂度为O(n)

// 在顺序表的第i个位置插入元素e
Status insertSeqList(SeqList &L, int i, ElemType e){
    if(i < 1 || i > L.length+1) return ERROR; // 判断i的范围是否有效，若无效则返回ERROR
    if(L.length == MAXSIZE) return ERROR;     // 判断存储空间是否已满，若满则返回ERROR
    for(int j = L.length; j >= i; j--){
        L.elem[j] = L.elem[j-1];              // 将第i个位置及之后的元素后移
    }
    L.elem[i-1] = e;                          // 将新元素e赋值给第i个位置
    L.length++;                               // 表长加1
    return OK;                                // 时间复杂度为O(n)
}

// 删除顺序表中第i个位置的元素
Status deleteSeqList(SeqList &L, int i){
    if(i < 1 || i > L.length) return ERROR;   // 判断i的范围是否有效，若无效则返回ERROR
    for(int j = i; j <= L.length - 1; j++){
        L.elem[j-1] = L.elem[j];              // 将第i个位置之后的元素前移
    }
    L.length--;                               // 表长减1
    return OK;                                // 时间复杂度为O(n)
}
