#pragma once

#ifdef __cplusplus
extern "C" {

#endif // __cplusplus


	typedef struct Node_
	{
		struct Node_* Next;
		int Data;
	}Node;

	typedef struct Stack_
	{
		Node* Head;
	}Stack;


	//스택은 LIFO (Last In First Out)형 자료구조입니다 

	// 스택을 초기화해준다.
	int InitStack(Stack* stack);

	//정수형 데이터를 스텍에 넣는다 
	int Push(Stack* stack, int Data);

	//Top 위치에 있는 정수형 데이타를 반환하고 리스트에서 제거한다.
	int Pop(Stack* stack);

	//Top 위치에 있는 정수형 데이타를 반환한다.
	int Top(Stack* stack);

	//동적할당된 메모리들을 전부 해제해준다.
	int Destroy(Stack* stack);
#ifdef __cplusplus
}
#endif // __cplusplus
