#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void preorder(int t[], int root) {
	if (t[root] != 0) {
		printf("%d", t[root]);
		preorder(t, root * 2);
		preorder(t, root * 2 + 1);
	}
	
}
void inorder(int t[], int root) {
	if (t[root] != 0) {
		inorder(t, root * 2);
		printf("%d", t[root]);
		inorder(t, root * 2 + 1);
	}
	
}

void postorder(int t[], int root) {
	if (t[root] != 0) {
		postorder(t, root * 2);
		postorder(t, root * 2 + 1);
		printf("%d", t[root]);
	}
	
}


int main() {
	//트리 배열의 크기는 2^(n+1) ,여기서 n은 트리의 높이
	//배열 크기 설정 안해주니까 쓰레기값 나왔음
	int t[32] = { 0,1,2,3,4,5,6,0,0,7,8,0,0,9,0,0,0 };


	preorder(t, 1);
	printf("\n");
	inorder(t, 1);
	printf("\n");
	postorder(t, 1);

	return 0;
}