#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

int is_full(HeapType* h) {
	return (h->heap_size == MAX_ELEMENT);
}
//비어있는지 확인 하는 함수
int is_empty(HeapType* h) {
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
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1]; //루트 노드
	temp = h->heap[(h->heap_size)--]; //새로 들어오는 노드
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	HeapType* heap;

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

	char order = ' ';
	int hh = 0;
	char a[5];
	element delete_e;

	while (1) {
		scanf_s("%[^\n]s", &a, 10); //입력 받음//%[^\n]s 띄어쓰기도 입력받기 위함

		rewind(stdin);//엔터가 그 다음 입력할 때 영향을 주기 때문에 입력버퍼를 지워줌

		char* context;

		//----------삽입 (I): max heap에 x를 삽입

		if (a[0] == 'I') {
			//h->heap_size == MAX_ELEMENT이라면

			if (is_full(heap)) {

				//Full 출력

				printf("Full\n");

			}

			//아니라면

			else {
				//python에 .split()처럼 쓰기 위해서 

				//특정 기준으로 문자열을 자를 수 있는 strtok_s를 사용했다

				//a: 자르고자하는 문자열, " ":자를 기준을 정하는 구분자, context:분할고 나머지 문지열 

				strtok_s(a, " ", &context);// " " 공백 문자를 기준으로 문자열을 자름



				element e = { atoi(context) }; //atoi()를 이용하여 문자열을 정수로 바꿔줌

				insert_max_heap(heap, e); //히프트리에 삽입

			}
		}
		//----------삭제 (D): 삭제후 값 출력

		else if (a[0] == 'D') {

			//h->heap_size == 0이라면

			if (is_empty(heap)) {

				//Empty 출력

				printf("Empty\n");
			}

			//아니라면
			else {
				delete_e = delete_max_heap(heap);//히프트리 삭제

				printf("%d\n", delete_e.key);//반환된 값 출력

			}
		}

		//----------종료 (Q): 종료

		else if (a[0] == 'Q') {
			exit(0);
		}
	}
	free(heap);
	return 0;
}