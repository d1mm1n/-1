//인접리스트로 표현된 그래프에 대한 깊이 우선 탐색 프로그램
//리스트로 작성하면 역순? 으로 저장되어서 역순으로,, 출력되는건가????>?>?
//교재 프로그램 10.2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u > g->n || v > g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }

    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int visited[MAX_VERTICES];

void dfs_list(GraphType* g, int v) {
    GraphNode* w;
    visited[v] = TRUE; // 정점 v의 방문 표시

    printf("정점 %d ->", v);

    for (w = g->adj_list[v]; w; w = w->link) {
        if (!visited[w->vertex]) {
            dfs_list(g, w->vertex);
        }
    }
    
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));

    init(g);
    for (int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");


    dfs_list(g, 0);
    printf("\n");

    free(g);
    return 0;
}
