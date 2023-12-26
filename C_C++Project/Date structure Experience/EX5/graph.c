#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 100

typedef struct {
    int vertex[MAX_VERTEX_NUM];
    int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertexNum;
    int arcNum;
} Graph;

void createGraph(Graph *G) {
    printf("请输入无向图顶点数:");
    scanf("%d", &G->vertexNum);
    printf("请输入边数:");
    scanf("%d", &G->arcNum);

    printf("请输入所有顶点的值:");
    for (int i = 0; i < G->vertexNum; i++) {
        scanf("%d", &G->vertex[i]);
    }

    for (int i = 0; i < G->vertexNum; i++) {
        for (int j = 0; j < G->vertexNum; j++) {
            G->arc[i][j] = 0;
        }
    }

    for (int k = 0; k < G->arcNum; k++) {
        int start, end;
        printf("请输入第 %d 边的两个顶点:", k+1);
        scanf("%d %d", &start, &end);
        G->arc[start-1][end-1] = 1;
        G->arc[end-1][start-1] = 1;
    }
}

void printMatrix(Graph G) {
    printf("邻接矩阵如下:\n");
    for (int i = 0; i < G.vertexNum; i++) {
        for (int j = 0; j < G.vertexNum; j++) {
            printf("%d ", G.arc[i][j]);
        }
        printf("\n");
    }
}

void DFS(Graph G, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", G.vertex[v]);

    for (int i = 0; i < G.vertexNum; i++) {
        if (G.arc[v][i] == 1 && visited[i] == 0) {
            DFS(G, i, visited);
        }
    }
}

void DFSTraversal(Graph G) {
    int visited[MAX_VERTEX_NUM] = {0};

    printf("DFS：");
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

    visited[v] = 1;
    printf("%d ", G.vertex[v]);
    queue[rear++] = v;

    while (front != rear) {
        int w = queue[front++];
        for (int i = 0; i < G.vertexNum; i++) {
            if (G.arc[w][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                printf("%d ", G.vertex[i]);
                queue[rear++] = i;
            }
        }
    }
}

void BFSTraversal(Graph G) {
    int visited[MAX_VERTEX_NUM] = {0};

    printf("BFS: ");
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
    printMatrix(G);
    DFSTraversal(G);
    BFSTraversal(G);
    return 0;
}
