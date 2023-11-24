#include<cstdlib>
#include<cstdio>

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

// 定义顺序存储结构线性表结构体
typedef struct {
	ElemType* elem;     //存储空间基址
	int length;         //当前长度
	int listsize;       //当前分配的存储容量
}SeqList;

//初始化一个空的顺序表L
Status Init_SeqList(SeqList &L) {
    //构造一个空的线性表L
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType)); //分配空间
	if (!L.elem) exit(OVERFLOW);                 //存储分配失败
	L.length = 0;                                //空表长度为0
	L.listsize = LIST_INIT_SIZE;                 //初始存储容量
	return OK;
}

//在顺序表L的第i个元素之前插入新的元素e，i的合法值为1<=i<=L.length+1
Status Insert_SeqList(SeqList &L, int i, ElemType e) {
	if (i<1 || i>L.length + 1) return ERROR;    //插入位置不合法
	if (L.length >= L.listsize) {               //存储空间已满，增加空间
		ElemType* newbase;
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType*));
		if (!newbase) exit(OVERFLOW);           //存储分配失败
		L.elem = newbase;                       //新基址
		L.listsize += LISTINCREMENT;            //增加存储容量
	}
	ElemType *q,*p;
	q = &(L.elem[i - 1]);                       //q为插入位置
	for (p = &(L.elem[L.length - 1]);p >= q;p--) 
        *(p + 1) = *p;                          //插入位置及之后的元素后移
	*q = e;                                     //插入e
	L.length++;                                 //表长度增加1
	return OK;
}

//在线性表L中删除第i个元素，并用e返回其值。i的合法值为1<=i<=L.length
Status Delete_SeqList(SeqList &L, int i,ElemType &e) {
	if (i < 1 || i > L.length) return ERROR;    //删除位置不合法
	ElemType *p,*q;
	p = &(L.elem[i - 1]);                       //p为被删除元素位置
	e = *p;                                     //被删除元素的值赋给e
	q = L.elem + L.length - 1;                  //q为表尾元素位置
	p++;
	for (;p <= q;p++) 
        *(p - 1) = *p;                          //被删除元素之后的元素左移
	L.length--;                                 //表的长度减1
	return OK;
}

//输出线性表L中的元素
Status Print_SeqList(SeqList &L) {
	// printf("顺序表中的元素为：\n");
	for (int i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
	return OK;
}

//销毁线性表L
Status Destroy_SeqList(SeqList &L) {
	free(L.elem);                               //释放存储空间
	L.elem = NULL;                              //存储指针置空
	L.length = 0;                               //长度置0
	L.listsize = 0;                             //存储容量置0
	return OK;
}
//将线性表L重置为空表
Status Clear_SeqList(SeqList &L) {
	L.length = 0;                               //长度置0
	return OK;
}

//判断线性表L是否为空表
Status Empty_SeqList(SeqList L) {
	if (L.length == 0) return TRUE;             //为空表
	else return FALSE;                          //不为空表
}

//返回线性表L的长度
int Length_SeqList(SeqList L) {
	return L.length;
}

//用e返回线性表L中第i个元素的值。i的合法值为1<=i<=L.length
Status GetElem_SeqList(SeqList L, int i, ElemType &e) {
	if (i<1 || i>L.length) return ERROR;        //i值不合法
	e = L.elem[i - 1];                          //将第i个元素的值赋给e
	return OK;
}

//返回线性表L中第一个与e满足关系compare()的元素的位序，若这样的元素不存在，则返回值为0
int LocateElem_SeqList(SeqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	int i = 1;                                  //i的初值为第一个元素的位序
	ElemType *p = L.elem;                       //p的初值为第一个元素的存储位置
	while (i <= L.length && !(*compare)(*p++, e)) 
		++i;                                    //顺序向后扫描，直到满足关系为止
	if (i <= L.length) return i;                //找到满足关系的元素的位序
	else return 0;                              //找不到满足关系的元素，返回0
}

//用pre_e返回cur_e的前驱
Status PriorElem_SeqList(SeqList L, ElemType cur_e, ElemType &pre_e) {
	int i = 2;                                  //i的初值为第二个元素的位序
	ElemType *p = L.elem + 1;                   //p的初值为第二个元素的存储位置
	while (i <= L.length && *p != cur_e) {      //顺序向后扫描，直到找到cur_e为止
		p++;i++;
	}
	if (i > L.length) return ERROR;             //找不到cur_e
	else {
		pre_e = *--p;                           //找到cur_e，返回它的前驱
		return OK;
	}
}

//用next_e返回cur_e的后继
Status NextElem_SeqList(SeqList L, ElemType cur_e, ElemType &next_e) {
	int i = 1;                                  //i的初值为第一个元素的位序
	ElemType *p = L.elem;                       //p的初值为第一个元素的存储位置
	while (i < L.length && *p != cur_e) {       //顺序向后扫描，直到找到cur_e为止
		p++;i++;
	}
	if (i == L.length) return ERROR;            //找不到cur_e
	else {
		next_e = *++p;                          //找到cur_e，返回它的后继
		return OK;
	}
}

//依次对L的每个元素调用函数visit()。一旦visit()失败，则操作失败
Status TraverseList_SeqList(SeqList L, Status(*visit)(ElemType &)) {
	ElemType *p = L.elem;                       //p的初值为第一个元素的存储位置
	int i = 1;                                  //i的初值为第一个元素的位序
	while (i <= L.length) {                     //顺序向后扫描，直到表尾
		if (!(*visit)(*p++)) return ERROR;      //调用visit()，若失败则操作失败
		i++;
	}
	return OK;
}

int main() {
	// 测试顺序表
	printf("\n开始测试顺序表。\n\n");
    printf("请输入顺序表表长：");
    int inputlength;
    scanf("%d", &inputlength);
    SeqList L;
    Init_SeqList(L);
    for(int i = 0; i < inputlength; i++){
        printf("\n请输入第%d个元素：", i + 1);
        int e;
        scanf("%d", &e);
        L.elem[i] = e;
		L.length++;
    }
	printf("\n顺序表为：");
    Print_SeqList(L);
    int e,x;
	printf("\n请输入要删除的元素的位置：");
	scanf("%d", &x);
    Delete_SeqList(L, x, e);
    printf("删除的元素为: %d\n", e);
	printf("删除后，顺序表为：");
    Print_SeqList(L);
    int i,j;
	printf("\n请依次输入要插入的元素的位置和值：");
	scanf("%d", &i);
	scanf("%d", &j);
	Insert_SeqList(L, i, j);
	printf("插入后，顺序表为：");
	Print_SeqList(L);
	printf("\n测试完毕.\n\n");
	return 0;
}
