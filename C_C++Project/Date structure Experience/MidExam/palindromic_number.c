#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c) {
    if (is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->data[s->top] = c;
}

char pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    char c = s->data[s->top];
    s->top--;
    return c;
}

int main() {
    Stack s;
    init(&s);

    char str[MAX_SIZE];
    printf("请输入一个字符串：");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    int is_palindrome = 1;
    for (int i = 0; i < len; i++) {
        char c = pop(&s);
        if (c != str[i]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("是回文\n");
    } else {
        printf("不是回文\n");
    }
    return 0;
}
