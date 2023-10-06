#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct QueueType {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}
//큐 초기화
void queue_init(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

int is_empty(QueueType* q) {
	return q->front == q->rear;
}
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (!is_full(q)) {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
element dequeue(QueueType* q) {
	if (!is_empty(q)) {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}

#define MAX_VERTEXS 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTEXS][MAX_VERTEXS];
}GraphType;

int visited[MAX_VERTEXS];

//그래프 초기화
void graph_init(GraphType* g) {
	g->n = 0;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEXS) {
		fprintf(stderr, "그래프: 정점 번호 오류invertex");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
	if (start > g->n || end > g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류!!!!!!!inedge");
		return;
	}
	g->adj_mat[start][end]=1;
	g->adj_mat[end][start]=1;
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d 방문->", v + 1);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++) {  //인접 정점 탐색
			if (g->adj_mat[v][w]==1 && !visited[w]) {
				visited[w] = TRUE;
				printf("%d 방문->", w + 1);
				enqueue(&q, w);
			}
		}
	}
}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 8; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 1, 7);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 5, 7);
	insert_edge(g, 5, 6);
	insert_edge(g, 6, 7);
	printf("너비우선탐색\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}