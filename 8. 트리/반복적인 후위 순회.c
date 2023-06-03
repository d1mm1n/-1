#include<stdio.h>
#include<stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
    if (top < SIZE - 1) {
        stack[++top] = p;
    }
}

//스택이 비어있는 경우에 NULL을 반환하기 위해 p를 초기화
TreeNode* pop() {
    TreeNode* p = NULL;
    if (top>=0) {
        p=stack[top--];
    }
    return p;
}

TreeNode* peek() {
    TreeNode* p = NULL;
    if (top >= 0) {
        p = stack[top];
    }
    return p;
}

void postorder_iter(TreeNode* root) {
    if (root == NULL)
        return;

    TreeNode* last_visited = NULL;

    do {
        while (root) {
            if (root->right)
                push(root->right);

            push(root);
            root = root->left;
        }
        root = pop();

        if (root->right && stack[top] == root->right) {
            top--;
            stack[++top] = root;
            root = root->right;
        }
        else {
            printf("[%d] ", root->data);
            last_visited = root;
            root = NULL;
        }
    } while (top >= 0);
}



//     15
//  4     20 
//1     16  25



TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 16,NULL,NULL };
TreeNode n3 = { 25,NULL,NULL };
TreeNode n4 = { 20,&n2,&n3 };
TreeNode n5 = { 4,&n1,NULL };
TreeNode n6 = { 15,&n5,&n4 };
TreeNode* root = &n6;


int main(void) {
    postorder_iter(root);

    return 0;
}
