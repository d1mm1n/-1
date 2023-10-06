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
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
};

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTEXS][MAX_VERTEXS];
	GraphNode* adj_list[MAX_VERTEXS];
}GraphType;

int mat_visited[MAX_VERTEXS];
int list_visited[MAX_VERTEXS];

//리스트 그래프 초기화
void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEXS; i++) {
		g->adj_list[i] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEXS) {
		fprintf(stderr, "그래프: 정점 번호 오류invertex");
		return;
	}
	g->n++;
}

//인접 행렬의 bfs
void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;
	queue_init(&q);
	mat_visited[v] = TRUE;
	printf("%d 방문->", v + 1);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++) {  //인접 정점 탐색
			if (g->adj_mat[v][w]==1 && !mat_visited[w]) {
				mat_visited[w] = TRUE;
				printf("%d 방문->", w + 1);
				enqueue(&q, w);
			}
		}
	}
}
//인접 리스트의 bfs
void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;
	list_visited[v] = TRUE;
	queue_init(&q);
	printf("%d 방문->", v+1);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link) {
			if (!list_visited[w->vertex]) {
				list_visited[w->vertex] = true;
				printf("%d 방문->", (w->vertex)+1);
				enqueue(&q, w->vertex);
			}
		}
	}
}

//인접 행렬 그래프 출력 함수
void print_adjmat(GraphType *g) {
	for (int i = 0; i < g->n; i++) {
		for (int k = 0; k < g->n; k++) {
			printf("%d ", g->adj_mat[i][k]);
		}
		printf("\n");
	}
	
}

//인접 리스트 출력 함수
void print_adjlist(GraphType* g) {
	for (int w = 0; w < g->n; w++) {
		GraphNode* p = g->adj_list[w];
		printf("정점 %d의 인접 리스트", w+1);
		while (p != NULL) {
			printf("->%d ", (p->vertex)+1);
			p = p->link;
		}
		printf("\n");
	}
}



int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 8; i++) {
		insert_vertex(g, i);
	}

	int adj_matrix[8][8] = {
		{0,1,1,0,0,0,0,0},
		{1,0,0,0,0,0,0,1},
		{1,0,0,1,1,0,0,0},
		{0,0,1,0,1,0,0,0},
		{0,0,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,1},
		{0,0,0,0,0,1,0,1},
		{0,1,0,0,0,1,1,0} 
	};


	//간선삽입
	for (int i = 0; i < 8; i++) {
		GraphNode* node;
		for (int j = 0; j < 8; j++) {
			g->adj_mat[i][j] = adj_matrix[i][j];
			if (adj_matrix[i][j] == 1) {
				node = (GraphNode*)malloc(sizeof(GraphNode));
				node->vertex = j;
				node->link = g->adj_list[i];
				g->adj_list[i] = node;
			}
		}
	}
	//인접 행렬 출력
	print_adjmat(g);
	
	printf("인접 행렬 bfs\n");
	bfs_mat(g, 0);
	printf("\n\n");
	//인접 리스트 출력
	printf("<인접 리스트의 구조 출력>\n");
	print_adjlist(g);
	printf("\n");
	printf("인접 리스트 bfs");
	printf("\n");
	bfs_list(g,0);
	printf("\n");
	free(g);

	return 0;
}