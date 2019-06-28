#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	typedef struct Node_
	{
		struct Node_* Next;
		int Data;
	}Node;

	typedef struct CircularList_
	{
		Node* Head;
	}CircularList;


	//환형 리스트 초기화, 성공시 0 반환, 실패시 -1 (이미 초기화가 된 노드의 경우와 한개이상의 노드가 존재하는 경우 -1 반환)
	int InitList(CircularList* clist);

	// 정수형 데이터를 가진 노드를 리스트의 element 의 다음노드로 추가시켜준다 (성공시 0, 동적할당 실패시 -1)
	int AddNode(CircularList* clist, Node* element, int data);

	// element node 를 찾는다, 찾을시 0, 없을시 -1
	int FindNode(CircularList* clist, Node* element);

	// element node 를 찾아서 지운다 
	int RemoveNode(CircularList* clist, Node* element);

	//환형 리스트 파괴하기 성공시 0 반환, 실패시 -1 (아무 노드가 없는경우 -1, 초기화를 한상태라고 가정)
	int DestroyList(CircularList* clist);



#ifdef __cplusplus
}
#endif // __cplusplus