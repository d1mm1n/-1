//Dijkstra 최단 경로 알고리즘 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L  //연결이 없는 경우 무한대

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

//가장 작은 거리 찾기
int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");

	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) printf(" * ");
		else printf("%2d ", distance[i]);
	}

	printf("\n");
	printf(" found: ");

	for (int i = 0; i < g->n; i++) {
		printf("%2d ", found[i]);
	}
	printf("\n");
}

//최단 거리 찾기 
void shortest_path(GraphType* g, int start) {
	int i, u, w;
	for (i = 0; i < g->n; i++) { //초기화
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}

	found[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < g->n; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++) {
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) distance[w] = distance[u] + g->weight[u][w];
		}
	}
}

int main(void) {
	GraphType g = { 6,{{0,10,INF,30,100,INF},{INF,0,50,INF,INF,INF},{INF,INF,0,INF,10,5},{INF,INF,20,0,INF,15},{INF,INF,INF,60,0,INF},{INF,INF,INF,INF,INF,0}} };
	shortest_path(&g, 0);
	//가중치의 합 구하기
	int sum = 0;

	for (int i = 0; i < g.n; i++) {
		sum += distance[i];
	}
	printf("가중치의 합: %d", sum);
	return 0;
}
