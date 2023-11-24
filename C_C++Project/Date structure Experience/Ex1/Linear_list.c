#include <stdio.h>
#include <stdlib.h>

// 定义顺序存储结构线性表结构体
typedef struct {
    int *data; // 存储数据的数组指针
    int length; // 顺序表长度
    int capacity; // 顺序表容量
} SeqList;

// 初始化一个空的顺序表L，该表预定义大小为defcapacity
int Init_SeqList(SeqList *L, int defcapacity) {
    L -> data = (int *)malloc(sizeof(int) * defcapacity);
    if(!L -> data) return -1;
    L -> length = 0;
    L -> capacity = defcapacity;
    return 1;
}

//在顺序表L的第i个元素之前插入新的元素e，i的合法值为1<=i<=L.length+1
int Insert_SeqList(SeqList *L, int i, int e){
    // 插入位置不合法
    if(i < 1 || i > L -> length + 1) return 0;

    // 线性表已满,增加分配
    if(L -> length >= L -> capacity) {
        int *newbase = (int *)realloc(L -> data, sizeof(int) * (L -> capacity + 1));
        //若分配失败，退出程序
        if(!newbase) 
        {
            printf("内存分配失败！\n");
            exit(0);
        }
        // 将表的数组指针指向新的基址
        L -> data = newbase;
        // 增加表的容量
        L -> capacity += 1;
    }

    // 将第i个元素及之后的元素后移一位
    int *q = &(L -> data[i - 1]);//q为插入位置地址
    
    for (int *p = &(L -> data[L->length - 1]); p >= q; --p)//p为最后一个元素地址
    {
        *(p + 1) = *p;
    }

    // 不用指针，将第i个元素及之后的元素后移一位
    // for(int j = L -> length; j >= i; j--){
    //     L -> data[j] = L -> data[j - 1];
    // }

    // 插入元素
    *q = e;
    //  L -> data[i - 1] = e;

    //表长加1
    L -> length++;

    return 1;
}

//在线性表L中删除第i个元素，并用e返回其值。i的合法值为1<=i<=L.length
int Delete_SeqList(SeqList *L, int i, int *e){
    // 删除位置不合法
    if(i < 1 || i > L -> length) return 0;

    int *p = &(L -> data[i - 1]);//删除位置地址
    *e = *p;//用e返回被删除的元素值
    int *q = &(L -> data[L -> length - 1]);//最后一个元素地址
    // 将第i个元素之后的元素前移一位
    for(; p < q; p++){
        *p = *(p + 1);
    }

    //表长减1
    L -> length--;
    return 1;
}

//输出顺序表
void Print_SeqList(SeqList *L){
    printf("顺序表为：\n");
    for(int i = 0; i < L -> length; i++){
        printf("%d ", L -> data[i]);
    }
    printf("\n");
}


//定义链表结构体
typedef struct LNode{
    int data;//存储数据的变量
    struct LNode *next;//指向下一个节点的指针
}LNode,*LinkList;

//初始化有头空链表
int Init_LinkList(LinkList head){
    head = (LinkList)malloc(sizeof(LNode));
    if(head == NULL) return -1;
    head -> next = NULL;
    return 0;
}

//在链表第i个位置插入元素e
int Insert_LinkList(LinkList head, int i, int e){
    //插入位置不合法
    if(i < 1) return -1;
    int j = 0;
    LinkList p = head;//p指向头结点
    //寻找第i-1个节点
    while(p != NULL && j < i - 1){
        p = p -> next;
        j++;
    }
    //插入位置不合法
    if(p == NULL) return 0;
    //创建新节点
    LinkList s = (LinkList)malloc(sizeof(LNode));
    if(s == NULL) return -1;
    s -> data = e;
    //将新节点插入到链表中
    s -> next = p -> next;
    p -> next = s;
    return 1;
}

//删除链表第i个位置的元素，并用e返回其值
int Delete_LinkList(LinkList head, int i, int *e){
    //删除位置不合法
    if(i < 1) return -1;
    int j = 0;
    LinkList p = head;//p指向头结点
    //寻找第i-1个节点
    while(p != NULL && j < i - 1){
        p = p -> next;
        j++;
    }
    //删除位置不合法
    if(p == NULL) return 0;
    //删除节点
    LinkList q = p -> next;
    p -> next = q -> next;
    *e = q -> data;
    free(q);
    return 1;
}

//输出有头链表
void Print_LinkList(LinkList head){
    printf("链表为：\n");
    LinkList p = head -> next;
    while(p != NULL){
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

//将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
LinkList Merge_LinkList(LinkList head1, LinkList head2){
    LinkList head = (LinkList)malloc(sizeof(LNode));
    if(head == NULL) return NULL;
    head -> next = NULL;
    LinkList p = head1 -> next;
    LinkList q = head2 -> next;
    LinkList r = head;
    while(p != NULL && q != NULL){
        if(p -> data <= q -> data){
            r -> next = p;
            p = p -> next;
        }else{
            r -> next = q;
            q = q -> next;
        }
        r = r -> next;
    }
    if(p != NULL){
        r -> next = p;
    }
    if(q != NULL){
        r -> next = q;
    }
    return head;
}

int main(){

    //测试顺序表
    // // printf("请输入顺序表表长：\n");
    // // int length;
    // // scanf("%d", &length);
    // SeqList L;
    // // Init_SeqList(&L, &length);
    // Init_SeqList(&L, 5);
    // // for(int i = 0; i < L.capacity; i++)
    // // {
    // //     printf("请输入第%d个元素：\n", i + 1);
    // //     int e;
    // //     scanf("%d", &e);
    // //     L.data[i] = e;
    // //     L.length++;
    // // }
    // for (int i = 1; i <= 5; i++) {
    //     Insert_SeqList(&L, i, i);
    // }
    // Print_SeqList(&L);
    // int e;
    // Delete_SeqList(&L, 3, &e);
    // printf("删除的元素为: %d\n", e);
    // Print_SeqList(&L);


    //测试链表
    LinkList head1;
    Init_LinkList(head1);
    for (int i = 1; i <= 5; i++)
    {
        Insert_LinkList(head1, i, i+1);
    }
    Print_LinkList(head1);

    // LinkList head2;
    // Init_LinkList(head2);
    // for (int i = 1; i <= 5; i++)
    // {
    //     Insert_LinkList(head2, i, i);
    // }
    // Print_LinkList(head2);
    // int e;
    // Delete_LinkList(head, 3, &e);
    // printf("删除的元素为: %d\n", e);
    // Print_LinkList(head);
    // for (int i = 5; i <= 10; i++)
    // {
    //     Insert_LinkList(head1, i-5, i);
    // }
    // Print_LinkList(head1);



    return 0;
}

