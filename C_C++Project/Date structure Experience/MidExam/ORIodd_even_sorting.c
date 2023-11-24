//奇偶排序
//将一个带头结点的单链表A 分解为两个带头结点的单链表A和B，
//使得A表中中含有原标中序号为奇数的元素，而B 表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
//请编写相应程序，并举出实例运行。

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

// 将一个带头结点的单链表A 分解为两个带头结点的单链表A和B，
//使得A表中中含有原标中序号为奇数的元素，而B 表中含有原表中序号为偶数的元素，且保持其相对顺序不变
// void splitList(LinkList A, LinkList* B) {
//     *B = (LinkList)malloc(sizeof(Node));
//     (*B)->next = NULL;
//     Node* tail = *B;
//     Node* p = A->next;
//     int index = 1;
//     while (p != NULL) {
//         if (index % 2 == 0) {
//             tail->next = p;
//             tail = p;
//         }
//         p = p->next;
//         index++;
//     }
//     tail->next = NULL;
// }

// void splitList(LinkList A, LinkList* B) {
//     *B = (LinkList)malloc(sizeof(Node));
//     (*B)->next = NULL;
//     Node* tail = *B;
//     Node* p = A->next;
//     Node* prev = A;
//     int index = 1;
//     while (p != NULL) {
//         Node* next = p->next;
//         if (index % 2 == 0) {
//             tail->next = p;
//             tail = p;
//             tail->next = NULL;
//             prev->next = next;
//         } else {
//             prev = p;
//         }
//         p = next;
//         index++;
//     }
// }

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



