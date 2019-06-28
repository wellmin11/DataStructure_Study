#include "CircularLinkedList.h"
#include <stdio.h>

// 환형 리스트 초기화, 성공시 0 반환, 실패시 -1 (이미 초기화가 된 노드의 경우와 한개이상의 노드가 존재하는 경우 -1 반환)
int InitList(CircularList* clist)
{
	if (clist->Head == NULL || clist->Head->Next != NULL)
		return -1;
	else
		clist->Head = NULL;
	return 0;
}

// 정수형 데이터를 가진 노드를 리스트의 element 의 다음노드로 추가시켜준다 (성공시 0, 동적할당 실패시 -1)
int AddNode(CircularList* clist, Node* element, int data)
{
	Node* node = (Node *)malloc(sizeof(Node));
	
	if (node == NULL) return -1;

	node->Data = data;
	
	element = clist->Head;
	while (element->Next != NULL)
		element = element->Next;
	element->Next = node;

	return 0;
}

// element node 를 찾는다, 찾을시 0, 없을시 -1
int FindNode(CircularList* clist, Node* element)
{
	while (clist->Head->Next != NULL) {
		if (clist->Head == element)
			return  0;
	}
	return -1;
}

// element node 를 찾아서 지운다 
int RemoveNode(CircularList* clist, Node* element)
{
	Node* node = (Node *)malloc(sizeof(Node));
	node = clist->Head;

	if (clist->Head == element) {
		clist->Head = clist->Head->Next;
		clist->Head = NULL;
		free(clist->Head);
		return 0;
	}

	while (node->Next != NULL) {
		if (node->Next == element) {
			node = NULL;
			free(node);
			return 0;
		}
		node = node->Next;
	}
	return -1;
}

// 환형 리스트 파괴하기 성공시 0 반환, 실패시 -1 (아무 노드가 없는경우 -1, 초기화를 한상태라고 가정)
int DestroyList(CircularList* clist)
{
	if (clist->Head == NULL) return -1;

	Node* node = (Node*)malloc(sizeof(Node));
	node = clist->Head;
	
	while (node->Next != NULL) {
		node = node->Next;
		node = NULL;
		free(node);
	}

	return 0;
}
