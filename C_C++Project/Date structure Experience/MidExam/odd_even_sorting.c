#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *LinkList;

// 初始化一个空链表
void initList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

// 初始化并直接建立一个数据元素为1-10的链表
void createList(LinkList* L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    Node* tail = *L;
    for (int i = 1; i <= 10; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
}

// 奇偶排序
void splitList(LinkList A, LinkList B) {
    Node* tail = B;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* p = A->next;
    Node* prev = A;
    int index = 1;
    while (p != NULL) {
        Node* next = p->next;
        if (index % 2 == 0) {
            tail->next = p;
            tail = p;
            tail->next = NULL;
            prev->next = next;
        } else {
            prev = p;
        }
        p = next;
        index++;
    }
}

// 打印链表
void printList(LinkList L) {
    LinkList p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 测试
int main() {
    LinkList A;
    // 建立一个带头结点的单链表A并赋值为1-10
    createList(&A);
    LinkList B;
    // 初始化一个空链表B
    initList(&B);
    printf("原链表A: ");
    printList(A);
    splitList(A, B);
    printf("奇偶排序后的A链表:");
    printList(A);
    printf("B链表: ");
    printList(B);
    return 0;
}