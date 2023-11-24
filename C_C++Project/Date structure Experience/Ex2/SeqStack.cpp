#include<cstdio>
#include<cstdlib>

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

typedef struct{
    ElemType *base;             //存储空间基址,在构造之前和销毁之后，base的值为NULL
    ElemType *top;              //栈顶指针
    int stacksize;              //当前分配的存储容量，以元素为单位
}SeqStack;

//初始化一个空的顺序栈S
Status Init_SeqStack(SeqStack &S){
    S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //分配空间
    if (!S.base) exit(OVERFLOW);                    //存储分配失败
    S.top = S.base;                                 //栈顶指针等于栈底指针
    S.stacksize = STACK_INIT_SIZE;                  //初始存储容量
    return OK;
}

//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
Status GetTop_SeqStack(SeqStack S,ElemType &e){
    if (S.top == S.base) return ERROR;          //栈空
    e = *(S.top - 1);                           //栈顶元素赋给e
    return OK;
}

//插入元素e为新的栈顶元素
Status Push_SeqStack(SeqStack &S,ElemType e){
    if (S.top - S.base >= S.stacksize){         //栈满，追加存储空间
        S.base = (ElemType*)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base) exit(OVERFLOW);            //存储分配失败
        S.top = S.base + S.stacksize;           //栈顶指针指向新的栈顶位置
        S.stacksize += STACKINCREMENT;          //增加存储容量
    }
    *S.top++ = e;                               //插入新的栈顶元素
    return OK;
}
Status Push_SeqStack(SeqStack &S,char e){
    if (S.top - S.base >= S.stacksize){         //栈满，追加存储空间
        S.base = (ElemType*)realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base) exit(OVERFLOW);            //存储分配失败
        S.top = S.base + S.stacksize;           //栈顶指针指向新的栈顶位置
        S.stacksize += STACKINCREMENT;          //增加存储容量
    }
    *S.top++ = e;                               //插入新的栈顶元素
    return OK;
}

//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
Status Pop_SeqStack(SeqStack &S,ElemType &e){
    if (S.top == S.base) return ERROR;          //栈空
    e = *--S.top;                               //栈顶元素赋给e
    return OK;
}
Status Pop_SeqStack(SeqStack &S,char &e){
    if (S.top == S.base) return ERROR;          //栈空
    e = *--S.top;                               //栈顶元素赋给e
    return OK;
}

//打印栈
void Print_SeqStack(SeqStack S){
    ElemType *p = S.base;
    while (p != S.top){
        printf("%d ",*p++);
    }
    printf("\n");
}

//销毁顺序栈S，S不再存在
Status Destroy_SeqStack(SeqStack &S){
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}

//把S置为空栈
Status Clear_SeqStack(SeqStack &S){
    S.top = S.base;
    return OK;
}

//若栈S为空栈，则返回TRUE，否则返回FALSE
Status StackEmpty_SeqStack(SeqStack S){
    if (S.top == S.base) return TRUE;
    else return FALSE;
}

//返回S的元素个数，即栈的长度
int StackLength_SeqStack(SeqStack S){

}

//从栈底到栈顶依次对栈中每个元素调用函数visit(),一旦visit()失败，则操作失败
Status StackTraverse_SeqStack(SeqStack S,Status(*visit)(ElemType &)){

}

//对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
void conversion(int N){
    if (N == 0)
    {
        printf("0\n");
        return;
    }
    SeqStack S;
    Init_SeqStack(S);
    while (N){
        Push_SeqStack(S,N % 8);
        N /= 8;
    }
    // printf("转换后的八进制数为:");
    while (!StackEmpty_SeqStack(S)){
        Pop_SeqStack(S,N);
        printf("%d",N);
    }
    // while (S.top != S.base){
    //     printf("%d",*--S.top);
    // }
    printf("\n");
}

//行编辑程序：利用字符栈S，从终端接受一行并传送至调用过程的数据区
void LineEdit(){
    SeqStack S;
    Init_SeqStack(S);           //构造空栈S
    char ch,c;
    ch = getchar();            //从终端接收第一个字符
    while (ch != EOF)
    {
        while (ch != EOF && ch != '\n')
        {
            switch (ch)
            {
                case '#':Pop_SeqStack(S,c);break;  //仅当栈非空时退栈
                case '@':Clear_SeqStack(S);break;   //重置栈为空栈
                default:Push_SeqStack(S,ch);break;  //有效字符进栈，未考虑栈满情况
            }
            ch = getchar();//从终端接收下一个字符
        }
        //将从栈底到栈顶的栈内字符传送至数据区
        // Print_SeqStack(S);
        Clear_SeqStack(S);
        if (ch != EOF) ch = getchar();
    }
    Destroy_SeqStack(S);
}

int main(){

    //测试顺序栈
    // SeqStack S;
    // ElemType e;
    // Init_SeqStack(S);
    // for (int i = 1; i <= 10; i++)
    //     Push_SeqStack(S,i);
    // printf("初始化的栈为:");
    // Print_SeqStack(S);
    // printf("栈顶元素为:");
    // GetTop_SeqStack(S,e);
    // printf("%d\n",e);
    // printf("请输入新的栈顶元素:");
    // scanf("%d",&e);
    // Push_SeqStack(S,e);
    // printf("插入新的栈顶元素后的栈为:");
    // Print_SeqStack(S);
    // printf("进行删除栈顶元素操作。");
    // Pop_SeqStack(S,e);
    // printf("删除的元素为:%d\n",e);
    // printf("删除栈顶元素后的栈为:");
    // Print_SeqStack(S);

    //测试conversion函数
    // conversion(0);
    // conversion(1);
    // conversion(8);
    // conversion(9);
    // conversion(10);
    // conversion(100);
    // conversion(1348);

    //测试LineEdit函数
    // LineEdit();


    return 0;
}