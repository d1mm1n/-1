//원형 연결 리스트로 원형 큐 구현하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct QNodeTyp { //큐의 노드 타입
	int data;
	struct Node* link;
}QNodeType;

typedef struct{  //큐 ADT 구현
	QNodeType *rear;
}linked_queue_type;

void init(linked_queue_type *q) {
	q->rear = NULL;
}

int is_empty(linked_queue_type *q) {
	return q->rear== NULL;
}

void enqueue(linked_queue_type *q, int val) {
	QNodeType* newNode = (QNodeType*)malloc(sizeof(QNodeType));
	newNode->data = val;
	if (is_empty(q)) {
		newNode->link = newNode; // 자기 자신을 가리키도록 설정
		q->rear = newNode;
	}
	else {
		newNode->link = q->rear->link;
		q->rear->link = newNode;
		q->rear = newNode;
	}
}

int dequeue(linked_queue_type *q) {
	if (is_empty(q)) return -1;
	
	QNodeType* front = q->rear->link;
	int val = front->data;
	q->rear->link=front->link;
	free(front);

	return val;
}

void print_queue(linked_queue_type *q) {
	QNodeType* p = q->rear->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != q->rear->link);
	printf("\n");
}

int main(void) {
	linked_queue_type q;
	init(&q);

	enqueue(&q, 1);
	print_queue(&q);
	enqueue(&q, 2);
	print_queue(&q);
	enqueue(&q, 3);
	print_queue(&q);

	dequeue(&q);
	print_queue(&q);

	enqueue(&q, 4);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);
	dequeue(&q);
	print_queue(&q);

	enqueue(&q, 5);
	print_queue(&q);
	return 0;
}
