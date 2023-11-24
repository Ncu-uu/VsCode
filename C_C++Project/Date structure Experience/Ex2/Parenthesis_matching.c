#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TXET_LEN 100        // 定义文本最大长度

// 定义链栈结构体
typedef struct SNode {
    char data;
    struct SNode *next;         // 指向下一个节点的指针
} SNode, *LinkStack;            // SNode为节点类型，LinkStack为指向节点的指针类型

// 初始化链栈
void Init_Stack(LinkStack *s) { // 传入指向链栈的指针
    *s = NULL;                  // 将栈顶指针置空
}

// 判断链栈是否为空
bool Is_Empty(LinkStack s) {    // 传入链栈
    return s == NULL;           // 栈顶指针为空，栈空
}

// 入栈
void Push(LinkStack *s, char data) {
    LinkStack newNode = (SNode *)malloc(sizeof(SNode)); // 为新节点分配内存
    newNode -> data = data;                             // 新节点数据域赋值
    newNode -> next = *s;                               // 新节点指针域指向栈顶元素     
    *s = newNode;                                       // 栈顶指针指向新节点
}

// 出栈
char Pop(LinkStack *s) {
    if (Is_Empty(*s)) {
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    LinkStack temp = *s;                // 保存栈顶元素   
    char data = temp->data;             // 保存栈顶元素数据域 
    *s = temp->next;                    // 栈顶指针指向下一个元素
    free(temp);                         // 释放栈顶元素内存
    return data;                        // 返回栈顶元素数据域
}

// 获取栈顶元素
char Get_Top(LinkStack s) {
    if (Is_Empty(s)) {                      
        printf("Error: Stack is empty!\n");
        exit(1);
    }
    return s->data;                     // 返回栈顶元素数据域
}

// 判断括号是否匹配
bool Is_Match(char left, char right) {
    if (left == '(' && right == ')') {
        return true;
    } else if (left == '[' && right == ']') {
        return true;
    } else if (left == '{' && right == '}') {
        return true;                    // 若左右括号匹配，返回true
    }else {
        return false;
    }
}

// 检查括号匹配
bool Check_Parenthesis(char *text) {
    LinkStack s;
    Init_Stack(&s);
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') 
        {
            Push(&s, text[i]);                                          // 左括号入栈
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}')  // 右括号匹配
        {
            if (Is_Empty(s) || !Is_Match(Get_Top(s), text[i]))          // 栈空或者左右括号不匹配，返回false
            {
                return false;
            } else 
            {
                Pop(&s);                                                // 左右括号匹配，出栈
            }
        }
    }
    return Is_Empty(s);                                                 // 栈空，返回true
}

int main() {
    char text[MAX_TXET_LEN];
    printf("请输入待检查的文本: ");
    fgets(text, MAX_TXET_LEN, stdin); 	// 使用fgets替换scanf,修复输入文本中有空格时的bug
    text[strcspn(text, "\n")] = 0; 		// 去掉fgets可能会读入的换行符
    if (Check_Parenthesis(text)) {
        printf("此文本的括号匹配\n");
    } else {
        printf("此文本的括号不匹配\n");
    }
    return 0;
}
