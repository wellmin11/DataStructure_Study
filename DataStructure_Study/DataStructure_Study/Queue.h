#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	typedef struct Node_
	{
		struct Node_* Next;
		int* Data;
	}Node;

	typedef struct Queue_
	{
		int Size;
		Node* Head;
		Node* Tail;
	}Queue;

	//queue �� �ʱ�ȭ�Ѵ�, queue�� Head, Tail ��带 �� �ʱ�ȭ�Ѵ�, 
	int InitQueue(Queue* queue);


	// ������ �����͸� ������ �ִ� ��带 queue �� "������ ���" �� �߰��Ѵ�
	int Enqueue(Queue* queue, int data);

	// Head��带 �����ϰ� Head ����� Data �� ��ȯ
	int Dequeue(Queue* queue);

#ifdef __cplusplus
}
#endif // __cplusplus