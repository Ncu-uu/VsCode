#include <stdio.h>
#include <stdlib.h>

struct LNode {
    int data;
    struct LNode *next;
};

struct LNode *creat(int n) {
    int i;
    struct LNode *head = NULL, *p1, *p2;

    for (i = 1; i <= n; i++) {
        p1 = (struct LNode *)malloc(sizeof(struct LNode));

        printf("请输入链表中第%d个数：", i);
        scanf("%d", &p1->data);

        if (head == NULL) {
            head = p1;
            p2 = p1;
        } else {
            p2->next = p1;
            p2 = p1;
        }
    }

    if (head != NULL) {
        p2->next = NULL;
    }

    return head;
}

void deleteNode(struct LNode **headRef, int key) {
    struct LNode *temp = *headRef, *prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next; // Changed head
        free(temp);            // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("节点 %d 不存在\n", key);
        return;
    }

    // Unlink the node from linked list
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *headRef = temp->next;
    }

    free(temp); // Free memory
}

void printList(struct LNode *head) {
    printf("\n链表中的数据：\n");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    struct LNode *head;

    printf("请输入链表的长度：");
    scanf("%d", &n);
    head = creat(n);
    
    printList(head);

    printf("\n请输入要删除的结点的值：");
    scanf("%d", &key);

    deleteNode(&head, key);
    printList(head);

    printf("\n\n\n");
    return 0;
}


