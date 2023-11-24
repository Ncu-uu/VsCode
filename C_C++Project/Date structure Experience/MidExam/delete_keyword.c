#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMENT 10    //线性表存储空间的分配增量

typedef struct {
    int* elem;          //存储空间基址
    int length;         //当前长度
    int listsize;       //当前分配的存储容量
} SeqList;

//初始化一个空的顺序表L
void Init_SeqList(SeqList *L) {
    L -> elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int)); //分配空间
    if (!L -> elem) exit(-1);                               //存储分配失败
    L -> length = 0;                                        //空表长度为0
    L -> listsize = LIST_INIT_SIZE;                         //初始存储容量
}

//在顺序表L的第i个元素之前插入新的元素e，i的合法值为1<=i<=L.length+1
void Insert_SeqList(SeqList *L, int i, int e) {
    if (i<1 || i>L -> length + 1) return;               //插入位置不合法
    if (L -> length >= L -> listsize) {                 //存储空间已满，增加空间
        int* newbase;
        newbase = (int*)realloc(L -> elem, (L -> listsize + LISTINCREMENT) * sizeof(int*));
        if (!newbase) exit(-1);           //存储分配失败
        L -> elem = newbase;                       //新基址
        L -> listsize += LISTINCREMENT;            //增加存储容量
    }
    int *q,*p;
    q = &(L -> elem[i - 1]);                       //q为插入位置
    for (p = &(L -> elem[L -> length - 1]);p >= q;p--) 
        *(p + 1) = *p;                          //插入位置及之后的元素后移
    *q = e;                                     //插入e
    L -> length++;                                 //表长度增加1
}

//在线性表L中删除第i个元素
void Delete_SeqList(SeqList *L, int i){
    if (i < 1 || i > L -> length) return;    //删除位置不合法
    int *p,*q;
    p = &(L -> elem[i - 1]);                       	//p为被删除元素位置
    q = L -> elem + L -> length - 1;                  //q为表尾元素位置
    for (++p;p <= q;p++) *(p - 1) = *p;           //被删除元素之后的元素前移
    L -> length--;                                 //表长度减1
}

//已知长度为n的顺序表A（不可以使用数组），使用顺序存储结构。编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，用于删除顺序表中所有值为key的数据元素。请编写相应程序，并举出实例运行。
void DeleteAllKey(SeqList *L, int key) {
    int i = 1;
    while (i <= L -> length) {
        if (L -> elem[i - 1] == key) {
            Delete_SeqList(L, i);
        } else {
            i++;
        }
    }
}

//  测试
int main(){
    SeqList L;
    Init_SeqList(&L);
    Insert_SeqList(&L, 1, 1);
    Insert_SeqList(&L, 2, 2);
    Insert_SeqList(&L, 3, 3);
    Insert_SeqList(&L, 4, 1);
    Insert_SeqList(&L, 5, 2);
    Insert_SeqList(&L, 6, 3);
    Insert_SeqList(&L, 7, 1);
    Insert_SeqList(&L, 8, 2);
    Insert_SeqList(&L, 9, 3);
    printf("原始顺序表：");
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.elem[i - 1]);
    }
    printf("\n");
    DeleteAllKey(&L, 1);
    printf("删除所有值为1的元素后:");
    for (int i = 1; i <= L.length; i++) {
        printf("%d ", L.elem[i - 1]);
    }
    printf("\n");
}