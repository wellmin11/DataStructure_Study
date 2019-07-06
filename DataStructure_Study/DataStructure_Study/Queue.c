#include "Queue.h"
#include <stdio.h>

//queue 를 초기화한다, queue의 Head, Tail 노드를 다 초기화한다, 
int InitQueue(Queue* queue)
{
	if (queue == NULL) return -1;
	queue->Head = NULL;
	queue->Tail = NULL;
	return 0;
}


// 정수형 데이터를 가지고 있는 노드를 queue 의 "마지막 노드" 에 추가한다
int Enqueue(Queue* queue, int data)
{
	if (queue == NULL) return -1;

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->Data = data;

	if (queue->Head == NULL && queue->Size == 0) {
		queue->Head = new_node;
	}
	else if (queue->Size == 1) {
		queue->Tail = new_node;
		queue->Head->Next = queue->Tail;
	}
	else {
		queue->Tail->Next = new_node;
		new_node = queue->Tail;
	}
	queue->Size++;
	return 0;
}

// Head노드를 제거하고 Head 노드의 Data 를 반환
int Dequeue(Queue* queue)
{
	if (queue == NULL || queue->Head == NULL) return -1;

	Node* de_node = (Node*)malloc(sizeof(Node));
	de_node = queue->Head;
	int data = de_node->Data;
	if(queue->Head->Next != NULL)
		queue->Head = queue->Head->Next;

	free(de_node);
	return data;
}
