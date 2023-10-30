//Prim의 최소 비용 신장 트리 프로그램

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; //정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];
//가중합을 계산 하기 위한 변수
int weight_sum = 0;

//최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
	int v, i;
	for (int i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	for (i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	}
	return v;
}

void prim(GraphType* g, int s) {
	int i, u, v, d,t;
	for (u = 0; u < g->n; u++) {
		distance[u] = INF;
	}
	distance[s] = 0;

	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;

		printf("selected 값의 변화\n");
		for (t = 0; t < g->n; t ++) {
			printf("%d ", selected[t]);
		}
		printf("\n");
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					distance[v] = g->weight[u][v];
					//distance 값의 변화를 출력
					
				}
			}
		}
		printf("distance 값의 변화\n");
		for (d = 0; d < g->n; d++) {
			printf("%d ", distance[d]);
		}
		printf("\n");
	}
}


//인천 0, 서울 1, 원주 2, 강릉 3, 전주 4, 대전 5, 광주 6, 대구 7, 부산 8
//시작 위치는 서울!
int main(void) {

	

	GraphType g = {
		9,{{0,35,INF,INF,245,INF,INF,INF,INF}, //인천
		{35,0,123,INF,INF,154,INF,INF,INF},  //서울
		{INF,123,0,117,INF,165,INF,222,INF},  //원주
		{INF,INF,117,0,INF,INF,INF,INF,INF},  //강릉
		{245,INF,INF,INF,0,87,98,INF,INF},  //전주
		{INF,154,165,INF,87,0,122,155,INF},  //대전
		{INF,INF,INF,INF,98,122,0,INF,INF},  //광주
		{INF,INF,222,INF,INF,155,INF,0,164},  //대구
		{INF,INF,INF,INF,INF,INF,INF,164,0},} //부산
	};
	for (int i = 0; i < g.n; i++) {
		selected[i] = 0;
	}

	//시작 위치가 서울이기 때문에 1을 매개변수로 전달
	prim(&g, 1);
	for (int i = 0; i < g.n; i++) {
		weight_sum += distance[i];
	}
	printf("가중치의 합은= %d",weight_sum);

	return 0;
	
}