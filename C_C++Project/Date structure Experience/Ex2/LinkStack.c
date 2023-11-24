#include <stdio.h>
#include <stdbool.h>
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
#define STACK_INIT_SIZE 100     //顺序栈存储空间的初始分配量
#define STACKINCREMENT 10       //顺序栈存储空间的分配增量

// 定义链栈结构体
typedef struct SNode {
    ElemType data;
    struct SNode *next;
} SNode, *LinkStack;

// 初始化链栈
Status Init_LinkStack(LinkStack *s) {
    *s = NULL;
    return OK;
}

// 判断链栈是否为空






