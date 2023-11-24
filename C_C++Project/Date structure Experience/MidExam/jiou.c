#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void splitList(Node* head, Node** oddList, Node** evenList) {
    Node* odd = *oddList;
    Node* even = *evenList;
    Node* curr = head->next;
    int index = 1;
    while (curr != NULL) {
        if (index % 2 == 1) {
            odd->next = curr;
            odd = odd->next;
        } else {
            even->next = curr;
            even = even->next;
        }
        curr = curr->next;
        index++;
    }
    odd->next = NULL;
    even->next = NULL;
}

int main() {

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* tail = head;

    for (int i = 1; i <= 10; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = i;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }

     printf("origin List: ");
    Node* origin = head->next;
    while (origin != NULL) {
        printf("%d ", origin->data);
        origin = origin->next;
    }
    printf("\n");

    Node* oddList = (Node*)malloc(sizeof(Node));
    oddList->next = NULL;
    Node* evenList = (Node*)malloc(sizeof(Node));
    evenList->next = NULL;

    splitList(head, &oddList, &evenList);

    printf("Odd List: ");
    Node* odd = oddList->next;
    while (odd != NULL) {
        printf("%d ", odd->data);
        odd = odd->next;
    }
    printf("\n");

    printf("Even List: ");
    Node* even = evenList->next;
    while (even != NULL) {
        printf("%d ", even->data);
        even = even->next;
    }
    printf("\n");

    return 0;
}
