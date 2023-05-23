//단순 연결 리스트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//<stdlib.h> include 하는거 잊지 말기 
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

int is_empty(ListNode head) {
	return head.link== NULL;
}

ListNode* insert_first(ListNode* head, int val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->link = head;
	head=p;
	return head;
}

ListNode* insert(ListNode* head, ListNode *pre, int val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* delete_first(ListNode *head) {
	ListNode* remove;
	if (is_empty(*head)) return NULL;
	remove = head;
	head = remove->link;
	free(remove);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* remove;
	if (is_empty(*head)) return NULL;
	remove = pre->link;
	pre->link = remove->link;
	free(remove);
	return head;
}


void print_list(ListNode *head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	ListNode* head=NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	//delete(head, prev) 리스트의 prev 다음 위치 항목 삭제 
	head = delete(head, head->link);
	print_list(head);
	head = delete_first(head);
	print_list(head);
}
