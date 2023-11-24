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

//定义线性表的单链表存储结构
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

// 在带头结点的单链表L中第i个位置之前插入元素e
Status Insert_L(LinkList &L, int i, ElemType e){
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1){
		p = p->next;
		j++; 									//寻找第i-1个结点
	} 
	 	
									
	if (!p || j > i - 1) 
		return ERROR;							//插入位置不合法，i<1或者i>L.length+1
	LinkList s;
	s = (LinkList)malloc(sizeof(LNode));		//生成新结点
	s->data = e;s->next = p->next;p->next = s;	//插入L中
	return OK;
}

//在带头结点的单链表L中删除第i个元素，并由e返回删除元素的值
Status Delete_L(LinkList &L,int i,ElemType &e){
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1){
		p = p->next;j++;						//寻找第i个结点，并令p指向其前驱
	}				
	if (!(p->next) || j > i - 1) 
		return ERROR;							//删除位置不合法
	LinkList q;
	q = p->next;p->next = q->next;
	e = q->data;free(q);						//删除并释放结点
	return OK;
}

//归并两个有序递增单链表La，Lb，合并之后的单链表Lc依然有序递增
void Merge_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	LinkList pa = La->next,pb = Lb->next,pc;
	Lc = pc = La;								//用La的头结点作为Lc的头结点
	while (pa && pb){
		if (pa->data <= pb->data){
			pc->next = pa;pc = pa;pa = pa->next;
		}
		else{
			pc->next = pb;pc = pb;pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;					//插入剩余段
	free(Lb);									//释放Lb的头结点
}

//从表尾到表头逆向建立单链表L，逆位序输入n个元素的值，建立带表头结点的单链表L
void CreateList_L_Reverse(LinkList &L,int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;								//先建立一个带头结点的单链表
	for (int i = n;i > 0;i--){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));	//生成新结点
		scanf("%d", &p->data);					//输入元素值
		p->next = L->next;						//插入到表头
		L->next = p;							//每次均在头结点之后插入元素，时间复杂度为O(n)
	}
}

//从表头到表尾正向建立单链表L，正位序输入n个元素的值，建立带表头结点的单链表L
void Create_L_Positive(LinkList &L,int n){
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;								//先建立一个带头结点的单链表
	LinkList r = L;								//r为表尾指针
	for (int i = 0;i < n;i++){
		LinkList p;
		p = (LinkList)malloc(sizeof(LNode));	//生成新结点
		scanf("%d", &p->data);					//输入元素值
		r->next = p;							//插入到表尾
		r = p;									//r指向新的表尾结点
	}
	r->next = NULL;								//尾结点指针置空
}

//单链表的整表删除
Status Clear_L(LinkList &L){
	LinkList p,q;
	p = L->next;								//p指向第一个结点
	while (p){									//没到表尾
		q = p->next;							//q指向下一个结点
		free(p);								//释放p
		p = q;									//p指向下一个结点
	}
	L->next = NULL;								//头结点指针域置空
	return OK;
}

//单链表的就地逆置
void Reverse_L(LinkList &L){
	LinkList p = L->next,q;
	L->next = NULL;								//将L的头结点指针域置空
	while (p){
		q = p->next;							//q指向p的后继结点
		p->next = L->next;						//将p结点插入到头结点之后
		L->next = p;
		p = q;									//p指向下一个结点
	}
}

//打印带头单链表L
void Print_L(LinkList &L){
	LinkList p = L->next;
	while (p){
		printf("%d ", p->data);
		p = p->next;
	}
}


int main() {

	//测试单链表的插入与删除
	 printf("\n开始测试单链表的插入与删除。\n\n");
	 LinkList L;
	 printf("请输入单链表L的元素个数:");
	 int n;
	 scanf("%d", &n);
	 printf("请输入%d个元素用于顺序创建单链表L:", n);
	 Create_L_Positive(L, n);
	 printf("单链表L为:");
	 Print_L(L);
	 int i,e,x,y;
	 printf("\n\n请输入要删除的元素位置:");
	 scanf("%d", &x);
	 Delete_L(L,x,y);
	 printf("删除的元素为:%d",y);
	 printf("\n删除后,链表为:");
	 Print_L(L);
	 printf("\n\n请依次输入插入单链表的位置与元素:");
	 scanf("%d", &i);
	 scanf("%d", &e);
	 Insert_L(L, i, e);
	 printf("插入后,链表为:");
	 Print_L(L);
	 printf("\n\n测试完毕.\n\n");

	// 测试单链表的顺序与逆序创建以及两个升序链表的归并
	printf("\n开始测试单链表的顺序与逆序创建以及两个升序链表的归并。\n\n");
	LinkList L1,L2,L3;
	printf("请输入单链表L1的元素个数:");
	int n1;
	scanf("%d", &n1);
	printf("请输入%d个元素用于顺序创建单链表L1:", n1);
	Create_L_Positive(L1, n1);
	printf("请输入单链表L2的元素个数:");
	int n2;
	scanf("%d", &n2);
	printf("请输入%d个元素用于逆序创建单链表L2:", n2);
	CreateList_L_Reverse(L2, n2);
	printf("\n单链表L1为:");
	Print_L(L1);
	printf("\n单链表L2为:");
	Print_L(L2);
	Merge_L(L1,L2,L3);
	printf("\n归并后的链表为:");
	Print_L(L3);
	printf("\n\n测试完毕.\n\n");
	return 0;
}
