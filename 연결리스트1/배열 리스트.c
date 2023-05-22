//배열 리스트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//리스트의 최대 크기
#define MAX 100

typedef struct {
	int array[MAX];
	int size;
}ArrayList;

void init(ArrayList* L) {
	L->size = 0;
}

int is_empty(ArrayList L) {
	return L.size == 0;
}

int is_full(ArrayList L) {
	return L.size == MAX - 1;
}

void insert(ArrayList* L, int pos, int item) {
	if (!is_full(*L)) {
		for (int i = L->size; i >=pos; i--) {
			L->array[i + 1] = L->array[i];
		}
	}
	L->array[pos] = item;
	L->size++;
}

void insert_last(ArrayList *L, int item) {
	if (!is_full(*L)) {
		L->array[L->size++] = item;
	}
}

void print_list(ArrayList *L) {
	for (int i = 0; i < L->size; i++) {
		printf("%d->", L->array[i]);
	}
	printf("\n");
}

void delete(ArrayList *L, int pos) {
	if (!is_empty(*L)) {
		for (int i = pos; i <= L->size; i++) {
			L->array[i] = L->array[i+1];
		}
		L->size--;
	}
}

int main(void) {
	ArrayList list;  //list를 포인터 타입으로 선언하지 말기
	init(&list);
	insert(&list, 0, 10);
	print_list(&list);
	insert(&list, 0, 20);
	print_list(&list);
	insert(&list, 0, 30);
	print_list(&list);
	insert_last(&list, 40);
	print_list(&list);
	delete(&list, 0);
	print_list(&list);
}
