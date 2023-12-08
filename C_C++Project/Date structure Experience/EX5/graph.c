#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef struct {
    int vertex[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexNum;
    int arcNum;
} Graph;

void createGraph(Graph *G) {
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->vertexNum, &G->arcNum);

    printf("请输入每个顶点的值：");
    for (int i = 0; i < G->vertexNum; i++) {
        scanf("%d", &G->vertex[i]);
    }

    for (int i = 0; i < G->vertexNum; i++) {
        for (int j = 0; j < G->vertexNum; j++) {
            G->arcs[i][j] = 0;
        }
    }

    printf("请输入每条边的信息：\n");
    for (int k = 0; k < G->arcNum; k++) {
        int v1, v2;
        printf("请输入第%d条边的两个顶点：", k + 1);
        scanf("%d %d", &v1, &v2);
        G->arcs[v1][v2] = 1;
        G->arcs[v2][v1] = 1;
    }
}

void DFS(Graph G, int v, int visited[]) {
    printf("%d ", G.vertex[v]);
    visited[v] = 1;

    for (int i = 0; i < G.vertexNum; i++) {
        if (G.arcs[v][i] == 1 && visited[i] == 0) {
            DFS(G, i, visited);
        }
    }
}

void DFSTraverse(Graph G) {
    int visited[MAX_VERTEX_NUM] = {0};

    printf("深度优先遍历结果：");
    for (int i = 0; i < G.vertexNum; i++) {
        if (visited[i] == 0) {
            DFS(G, i, visited);
        }
    }
    printf("\n");
}

void BFS(Graph G, int v, int visited[]) {
    int queue[MAX_VERTEX_NUM];
    int front = 0, rear = 0;

    printf("%d ", G.vertex[v]);
    visited[v] = 1;
    queue[rear++] = v;

    while (front != rear) {
        int w = queue[front++];
        for (int i = 0; i < G.vertexNum; i++) {
            if (G.arcs[w][i] == 1 && visited[i] == 0) {
                printf("%d ", G.vertex[i]);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void BFSTraverse(Graph G) {
    int visited[MAX_VERTEX_NUM] = {0};

    printf("广度优先遍历结果：");
    for (int i = 0; i < G.vertexNum; i++) {
        if (visited[i] == 0) {
            BFS(G, i, visited);
        }
    }
    printf("\n");
}

int main() {
    Graph G;
    createGraph(&G);
    DFSTraverse(G);
    BFSTraverse(G);
    return 0;
}
