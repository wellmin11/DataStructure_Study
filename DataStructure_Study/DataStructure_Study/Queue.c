#include "Queue.h"
#include <stdio.h>

//queue �� �ʱ�ȭ�Ѵ�, queue�� Head, Tail ��带 �� �ʱ�ȭ�Ѵ�, 
int InitQueue(Queue* queue)
{
	if (queue == NULL) return -1;
	queue->Head = NULL;
	queue->Tail = NULL;
	return 0;
}


// ������ �����͸� ������ �ִ� ��带 queue �� "������ ���" �� �߰��Ѵ�
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

// Head��带 �����ϰ� Head ����� Data �� ��ȯ
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
