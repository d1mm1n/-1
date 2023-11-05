//Floyd 최단 경로 알고리즘 프로그램

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L  //연결이 없는 경우 무한대

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int A[MAX_VERTICES][MAX_VERTICES];
int num = -1;

void printA(GraphType* g) {
	int i, j;
	printf("=======================================\n");
	printf("A%d", num);
	num++;
	printf("\n");
	for ( i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF) printf(" * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("=======================================");
}

//최단 거리 찾기 
void floyd(GraphType* g) {
	int i, j, k;
	for (i = 0; i < g->n; i++) { //초기화
		for (j = 0; j < g->n; j++) {
			A[i][j] = g->weight[i][j];
		}
	}

	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (A[i][k] + A[k][j] < A[i][j])  A[i][j] = A[i][k] + A[k][j];
			}
		}
		printA(g);
	}
	
	
}




int main(void) {
	GraphType g = { 6,{{0,10,INF,30,100,INF},{INF,0,50,INF,INF,INF},{INF,INF,0,INF,10,5},{INF,INF,20,0,INF,15},{INF,INF,INF,60,0,INF},{INF,INF,INF,INF,INF,0}} };
	floyd(&g);
	// 최단 경로 가중치의 합을 계산

	int total_weight = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (i != j && A[i][j] != INF) {
				total_weight += A[i][j];
			}
		}
	}

	printf("\n최단거리 가중치의 합: %d\n", total_weight);
	return 0;
}
