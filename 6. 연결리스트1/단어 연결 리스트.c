//단어를 저장하는 연결리스트를 만들어보쟉!
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//<stdlib.h> include 하는거 잊지 말기 
#include <stdlib.h>

typedef struct {
	char name[100];
}element;


typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

int is_empty(ListNode head) {
	return head.link== NULL;
}

ListNode* insert_first(ListNode* head, element val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->link = head;
	head=p;
	return head;
}

ListNode* insert(ListNode* head, ListNode *pre, element val) {
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
		printf("%s->", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	ListNode* head = NULL;
	element data;
	strcpy(data.name, "사과");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "키위");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "레몬");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}
