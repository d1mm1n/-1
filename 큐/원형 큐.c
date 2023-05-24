// 원형 큐 기본
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 5

typedef struct {
	int front;
	int rear;
	int data[MAX];
}QueueType;


void init(QueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_full(QueueType q) {
	return q.front==(q.rear+1)%MAX;
}

int is_empty(QueueType q) {
	return q.front == q.rear;
}

void enqueue(QueueType* q, int item) {
	if (!is_full(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = item;
	}
}

int dequeue(QueueType* q) {
	if (!is_empty(*q)) {
		q->front = (q->front + 1) % MAX;
		return q->data[q->front];
	}
}

int peek(QueueType q) {
	if (!is_empty(q)) {
		return q.data[(q.front + 1) % MAX];
	}
}

void queue_print(QueueType q) {
	if (!is_empty(q)) {
		int i = q.front;
		do {
			i=(i+1)%MAX;
			printf("%d", q.data[i]);
		} while (i != q.rear);
	}
}

int main(void) {
	QueueType q;

	init(&q);
	
	enqueue(&q, 1);
	enqueue(&q, 2);
	printf("dequeue: %d\n", dequeue(&q));
	enqueue(&q, 3);
	enqueue(&q, 4);
	printf("dequeue: %d\n", dequeue(&q));
	enqueue(&q, 5);
	enqueue(&q, 6);
	
	printf("큐에 남아 있는 정수: ");
	queue_print(q);

}