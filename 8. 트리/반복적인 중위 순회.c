#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	char data[100];
	struct TreeNode* left, * right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}

void inorder_iter(TreeNode *root) {
	while (1) {
		for (; root; root = root->left)
			push(root);

		root = pop();
		if (!root) break;
		printf("[%s] ", root->data);
		root = root->right;
	}
}
//          A
//     B          C
//   D   E      F   G
//        H       I


TreeNode n1 = { "H",NULL,NULL};
TreeNode n2 = { "I",NULL,NULL };
TreeNode n3 = { "G",&n2,NULL };
TreeNode n4 = { "F",NULL,NULL };
TreeNode n5 = { "D",NULL,NULL };
TreeNode n6 = { "E",NULL,&n1};
TreeNode n7 = { "B",&n5,&n6 };
TreeNode n8 = { "C",&n4,&n3 };
TreeNode n9 = { "A",&n7,&n8 };
TreeNode* root = &n9;


int main(void) {
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}