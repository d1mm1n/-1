#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// 수준별 순회
void level_order(TreeNode* root) {
    if (root == NULL)
        return;

    // 큐를 사용하여 노드들을 저장
    TreeNode* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* node = queue[front++];
        printf("%d ", node->data);

        if (node->left != NULL)
            queue[rear++] = node->left;
        if (node->right != NULL)
            queue[rear++] = node->right;
    }
}

TreeNode* cons_tree(int t[], int i) {
    if (t[i] != 0) {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        if (root != NULL) {
            root->data = t[i];
            root->left = cons_tree(t, i * 2);
            root->right = cons_tree(t, i * 2 + 1);
        }
        return root;
    }
    else return NULL;
}

TreeNode* make_node(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(void) {
    int t[32] = { 0, 1, 2, 3, 4, 5, 6, 0, 0, 7, 8, 0, 0, 9, 0, 0 };
    TreeNode* root = cons_tree(t, 1);

    level_order(root);

    return 0;
}
