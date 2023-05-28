//원형 연결 리스트
//마지막 노드가 head!!!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}ListNodeType;

ListNodeType* insert_first(ListNodeType* head, int val) {
	ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
	p->data = val;
	if (head == NULL) {
		head=p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
	}
	return head;
}

ListNodeType* insert_last(ListNodeType* head, int val) {
	ListNodeType* p = (ListNodeType*)malloc(sizeof(ListNodeType));
	p->data = val;
	if (head == NULL) {
		head = p;
		p->link = head;
	}
	else {
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}

void print_list(ListNodeType* head) {
	ListNodeType* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); //마지막 노드 출력
}



int main(void) {
	ListNodeType* list = NULL;

	list = insert_first(list, 10);
	list = insert_first(list, 20);
	list = insert_first(list, 30);

	list = insert_last(list, 40);
	list = insert_last(list, 50);
	print_list(list);
	return 0;
}
