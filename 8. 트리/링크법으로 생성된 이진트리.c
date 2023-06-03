//링크법으로 생성된 이진트리

#include<stdio.h>
#include<stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

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


void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        preorder(root->left);
        printf("[%d] ", root->data);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != NULL) {
        preorder(root->left);
        preorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void) {

    printf("전위 순회: ");
    preorder(root);
    printf("\n");
    printf("중위 순회: ");
    inorder(root);
    printf("\n");
    printf("후위 순회: ");
    postorder(root);

    return 0;
}
