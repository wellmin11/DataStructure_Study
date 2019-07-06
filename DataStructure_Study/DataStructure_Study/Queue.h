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

	//queue 를 초기화한다, queue의 Head, Tail 노드를 다 초기화한다, 
	int InitQueue(Queue* queue);


	// 정수형 데이터를 가지고 있는 노드를 queue 의 "마지막 노드" 에 추가한다
	int Enqueue(Queue* queue, int data);

	// Head노드를 제거하고 Head 노드의 Data 를 반환
	int Dequeue(Queue* queue);

#ifdef __cplusplus
}
#endif // __cplusplus