#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

typedef struct {
	int data[MAX];
	int front, rear;
}QueueType;

void queue_init(QueueType *q) {
	q->front = -1;
	q->rear = -1;
}


int is_empty(QueueType q) {
	return q.front == -1&& q.rear==-1;
}
int is_full(QueueType q) {
	return q.rear==MAX-1;
}


void enqueue(QueueType *q, int item){
	if (!is_full(*q)) {
		q->rear++;
		q->data[q->rear] = item;
	}
	else {
		printf("큐는 포화상태");
	}
	
}

int dequeue(QueueType* q) {
	if (!is_empty(*q)) {
		q->front++;
		return q->data[q->front];
	}
	else {
		printf("큐가 비어있습니다.");
	}
}


void print_queue(QueueType q) {
	if (!is_empty(q)) {
		do {
			q.front++;
			printf("%d ", q.data[q.front]);
		} while (q.front != q.rear);
	}
	
}


int main() {
	QueueType q;
	queue_init(&q);

	enqueue(&q, 1);
	enqueue(&q, 2);
	printf("%d", dequeue(&q));
	enqueue(&q, 3);
	printf("\n");
	printf("큐에 남아있는 정수: ");
	print_queue(q);
	return 0;
}