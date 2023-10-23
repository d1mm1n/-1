//LPT 프로그램 구현(최소 히프를 사용)
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	int key;
	int id;
}element;

typedef struct {
	element heap[MAX];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;
}

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void insert(HeapType *h, element item) {
	int i = ++(h->heap_size);
	while ((i!=1)&&item.key < h->heap[i/2].key) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i]= item;
}

element delete_heap(HeapType *h) {
	int parent,child;
	parent = 1;
	child = 2;
	element item, temp;
	item=h->heap[1];
	temp = h->heap[(h->heap_size)--];

	while (child <= h->heap_size) {
		if (h->heap[child].key > h->heap[child + 1].key) child++; //자식중 더 작은 key값을 가진 자식 찾기
		if (temp.key < h->heap[child].key) break;
		//한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

#define JOBS 7
#define MACHINES 3

int main() {
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0, 0 };
	HeapType* h;
	h = create();
	init(h);

	//여기서 key 값은 기계가 사용 가능하게 되는 시간이다.
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.key = 0;
		insert(h, m);
	}
	//최소 히프에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가 시킨 후에 다시 최소 히프에 추가한다.
	for (int i = 0; i < JOBS; i++) {
		m = delete_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다.\n", i, m.key, m.key + jobs[i] - 1, m.id);

		m.key += jobs[i];
		insert(h, m);
	}

}