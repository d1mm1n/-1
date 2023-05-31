#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
}TreeNode;

//중위
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//전위
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//후위
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

TreeNode* make_node(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* cons_tree(int t[], int i) {
    if (t[i] != 0) {
        TreeNode* root = make_node(t[i]);
        if (root != NULL) {
            root->left = cons_tree(t, i * 2);
            root->right = cons_tree(t, i * 2 + 1);
        }
        return root;
    }
    else return NULL;
}


int main(void) {
    int t[32] = {0,1,2,3,4,5,6,0,0,7,8,0,0,9,0,0,};
    TreeNode* root=cons_tree(t, 1);


    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
