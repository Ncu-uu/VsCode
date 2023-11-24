#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 20
#define MAX_COL 20

typedef struct {
    int data[MAX_COL];          // 数组存储元素，每行元素个数不超过MAX_COL，用于存储杨辉三角形的一行
    int length;                 // 数组长度
} Array;

typedef struct {
    Array data[MAX_ROW];        // 数组存储元素，每行元素个数不超过MAX_COL，用于存储杨辉三角形的所有行
    int front, rear;            // 队头和队尾指针
} Queue;

// 初始化队列
void initQueue(Queue *q) {           
    q->front = q->rear = 0;     // 队头和队尾指针置为0
}

// 判断队列是否为空
int isQueueEmpty(Queue q) {    
    return q.front == q.rear;   // 队头和队尾指针相等，队列为空
}

// 判断队列是否已满
int isQueueFull(Queue q) {
    return q.rear == MAX_ROW;   // 队尾指针等于队列最大长度，队列已满
}

// 入队
void enqueue(Queue *q, Array a) {
    if (isQueueFull(*q)) {      // 队列已满，入队失败
        return;
    }
    q->data[q->rear++] = a;     // 将元素a入队
}

// 出队
Array dequeue(Queue *q) {
    if (isQueueEmpty(*q)) {     // 队列为空，出队失败
        exit(1);
    }
    return q->data[q->front++]; // 返回队头元素
}

// 打印杨辉三角形
void printYangHuiTriangle(int n) {
    Queue q;                            // 定义单行杨辉三角形队列
    initQueue(&q);                      // 初始化队列

    Array a = {{1}, 1};                 // 第一行元素为1
    enqueue(&q, a);                     // 将第一行元素入队

    for (int i = 0; i < n; i++) {
        Array prev = dequeue(&q);       // 将上一行元素出队并赋值给prev
        Array curr = {{1}, i + 1};      // 当前行元素第一个元素为1，长度为i+1
        for (int j = 1; j < i; j++) {
            curr.data[j] = prev.data[j - 1] + prev.data[j];
        }                               // 当前行元素第二个元素到倒数第二个元素为上一行元素相邻两个元素之和
        curr.data[i] = 1;               // 当前行元素最后一个元素为1
        enqueue(&q, curr);              // 将当前行元素入队

        int padding = (n - i) * 3;      // 计算每行前面的空格数
        for (int j = 0; j < padding; j++) {
            printf(" ");
        }
        // 打印当前行元素            
        for (int j = 0; j < curr.length; j++) {
            printf("%-6d", curr.data[j]);
        }
        printf("\n");
    }
}

int main() {
    printf("请输入要生成的杨辉三角形的行数：");
    int n;
    scanf("%d", &n);
    printYangHuiTriangle(n);
    return 0;
}
