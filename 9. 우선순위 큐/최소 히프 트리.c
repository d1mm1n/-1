// 최소 히프
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

//비어있는지 확인 하는 함수
int Empty(HeapType* h) {
	return (h->heap_size ? 0 : 1);
}

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}

// 삭제 함수
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; //루트 노드
	temp = h->heap[(h->heap_size)--]; //새로 들어오는 노드
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
//히프 트리를 출력하는 함수
void printHeap(HeapType* h) {
	if (Empty(h)) {
		printf("히프가 비어있습니다.");
		return;
	}

	printf("히프 트리 출력:");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i].key);
	}
	printf("\n");
		
}
  

int main(void)
{
	element e1 = { 10 }, e2 = { 40 }, e3 = { 30 }, e4 = { 5 }, e5 = { 12 }, e6 = { 6 }, e7 = { 15 }, e8 = { 9 }, e9 = { 60 };
	HeapType* heap;

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

	// 삽입
	insert_min_heap(heap, e1);
	printHeap(heap);
	insert_min_heap(heap, e2);
	printHeap(heap);
	insert_min_heap(heap, e3);
	printHeap(heap);
	insert_min_heap(heap, e4);
	printHeap(heap);
	insert_min_heap(heap, e5);
	printHeap(heap);
	insert_min_heap(heap, e6);
	printHeap(heap);
	insert_min_heap(heap, e7);
	printHeap(heap);
	insert_min_heap(heap, e8);
	printHeap(heap);
	insert_min_heap(heap, e9);
	

	//삭제
	while (!Empty(heap)) {
		printHeap(heap);
		printf(" \n 삭제: < %d > \n", delete_min_heap(heap));
	}

	free(heap);
	return 0;
}