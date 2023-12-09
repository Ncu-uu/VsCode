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