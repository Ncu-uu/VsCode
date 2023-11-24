#include <iostream>
#include <iomanip>

using namespace std;

// 定义队列结构体
struct Queue {
    int front, rear;
    int size;
    int* arr;
};

// 初始化队列
Queue* createQueue(int size) {
    Queue* queue = new Queue;
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = new int[size];
    return queue;
}

// 判断队列是否为空
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// 判断队列是否已满
bool isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// 入队
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = item;
}

// 出队
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// 获取队首元素
int front(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front];
}

// 获取队尾元素
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->rear];
}

// 获取队列大小
int size(Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

// 生成杨辉三角形数据并存储在队列中
void generateYangHuiTriangle(Queue* queue, int n) {
    int prev = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i - 1) {
                enqueue(queue, 1);
            } else {
                int curr = dequeue(queue);
                int sum = prev + curr;
                enqueue(queue, sum);
                prev = curr;
            }
        }
        enqueue(queue, 0);
    }
}

// 打印杨辉三角形数据
void printYangHuiTriangle(Queue* queue, int n) {
    int row = 1;
    int curr = dequeue(queue);
    while (curr != -1) {
        if (curr == 0) {
            cout << endl;
            row++;
            curr = dequeue(queue);
            continue;
        }
        cout << setw(2 * (n - row + 1)) << curr << " ";
        curr = dequeue(queue);
    }
}

int main() {
    int n;
    cout << "请输入要生成的杨辉三角形的行数：";
    cin >> n;
    Queue* queue = createQueue(n * (n + 1) / 2);
    generateYangHuiTriangle(queue, n);
    printYangHuiTriangle(queue, n);
    return 0;
}
