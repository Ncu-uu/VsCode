#include <stdio.h>
#include <stdlib.h>

// 定义二叉树的二叉链表存储结构
typedef struct bitTreeNode {
    int data;               //数据域
    struct bitTreeNode* left;  //左孩子指针
    struct bitTreeNode* right; //右孩子指针
} bitTreeNode;

// 先序遍历递归创建二叉链表
bitTreeNode* createBinaryTree() {
    int data;
    printf("请输入结点的值（输入-1表示空结点）：");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    bitTreeNode* root = (bitTreeNode*)malloc(sizeof(bitTreeNode));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    printf("请输入结点 %d 的 左 子结点：", data);
    root->left = createBinaryTree();
    printf("请输入结点 %d 的 右 子结点：", data);
    root->right = createBinaryTree();
    return root;
}

// 先序遍历二叉树（递归）
void preOrderTraversal(bitTreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


// 中序遍历二叉树（递归）
void inOrderTraversal(bitTreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// 后序遍历二叉树（递归）
void postOrderTraversal(bitTreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// 非递归实现先序遍历：利用栈先进后出的思想
void preOrderTraversalNonRecursive(bitTreeNode* root) {
    if (root == NULL) {
        return;
    }
    bitTreeNode* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        bitTreeNode* node = stack[top--];
        printf("%d ", node->data);
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

// 递归求结点个数：如果是空树，则结点个数为0；否则，结点个数为左子树的结点个数加上右子树的结点个数；
int getNodeCount(bitTreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getNodeCount(root->left) + getNodeCount(root->right) + 1;
}

int main() {
    bitTreeNode* root = createBinaryTree();
    printf("先序遍历结果：");
    preOrderTraversal(root);
    printf("\n");
    printf("中序遍历结果：");
    inOrderTraversal(root);
    printf("\n");
    printf("后序遍历结果：");
    postOrderTraversal(root);
    printf("\n");
    printf("非递归先序遍历结果：");
    preOrderTraversalNonRecursive(root);
    printf("\n");
    printf("结点个数：%d\n", getNodeCount(root));
    return 0;
}
