#include "DoublyLinkedList.h"
#include <stdlib.h>

static int listSize = 0;

//리스트를 초기화한다 
int InitList(List* list)
{

	list->Head = NULL;

	list->Tail = NULL;

	return 0;

}



// int 형의 data 를 리스트에 Tail 뒤에 추가한다 성공시 0 반환 실패시 -1 반환하기
int AddNode(List* list, int data)
{

	Node* node = (Node*)malloc(sizeof(Node));

	node->Data = data;



	if (listSize == 0) {

		list->Head = node;

		list->Tail = node;

		list->Head->Next = list->Tail;

		list->Tail->Prev = list->Head;

	}

	else if (listSize == 1) {

		list->Tail = node;

		list->Head->Next = list->Tail;

		list->Tail->Prev = list->Head;

	}

	else {

		list->Tail->Next = node;

		node->Prev = list->Tail;

		list->Tail = list->Tail->Next;

	}

	listSize++;

	return 0;

}



//Head 노드로부터 i 번째의 노드의 데이터를 가져온다 성공시 0 , 실패시 -1 반환하기
int GetData(List* list, int i)
{

	if (listSize == 0 || listSize <= i) return -1;

	if (i == 1)

		return list->Head->Data;

	else {

		list->Head = list->Head->Next;

		for (int j = 0; j < i - 1; j++)

		{

			list->Tail = list->Tail->Next;

		}

		return list->Tail->Data;

	}

}



// 리스트의 사이즈를 반환 하기
int GetListSize(List* list)
{

	return listSize;

}



// i 번째의 노드를 지운다 (지울게 없다면 -1, 지운게 성공하면 0 반환)

int RemoveNodeFromList(List* list, int i)
{

	if (list->Head == NULL || i < 0) return -1;

	if (i == 1) {

		if (list->Head == list->Tail) {

			list->Head = NULL;

			list->Tail = NULL;

			free(list->Head);

			free(list->Tail);

		}

		else {

			list->Head = list->Head->Next;

			list->Head->Prev = NULL;

			free(list->Head->Prev);

		}

		listSize = 0;

		return 0;

	}



	Node* current = (Node*)malloc(sizeof(Node));

	current = list->Head;

	while (current != NULL && --i >= 0)

	{

		current = current->Next;

	}

	current->Next->Prev = current->Prev;

	current->Prev->Next = current->Next;

	listSize--;

	free(current);

	return 0;

}



//  리스트 제거하기 제거할게 없으면 -1 반환 성공시 0
int DestroyList(List* list)
{

	int i = listSize;

	if (i == 0) return -1;

	else {

		for (int j = 0; j < i; j++)

		{

			list->Head->Data = 0;

			list->Head = list->Head->Next;

			free(list->Head->Prev);

			listSize--;

		}

		free(list->Head);

	}

	return 0;

}



int AddNodePtr(List* list, Node* node)
{

	if (listSize == 0)

	{

		list->Head = node;

	}

	else if (listSize == 1) {

		list->Head->Next = node->Prev;

		node->Prev = list->Head->Next;

	}

	else

	{

		for (int i = 0; i < listSize - 1; i++)

			list->Tail = list->Tail->Next;

		list->Tail->Next = node->Prev;

		node->Prev = list->Tail->Next;

	}

	listSize++;

	return 0;

}





// i번째 노드의 포인터를 가져온다 
Node* GetNode(List* list, int i)
{

	if (listSize == 0 || listSize <= i) return NULL;

	if (listSize == 1)

		return list->Head;

	else {

		for (int k = 0; k < i; k++)

		{

			list->Head = list->Head->Next;

		}

	}

	return list->Head;

}



//i 번째에 리스트를 추가한다 
int AddList(List* list1, List* list2, int i)
{

	for (int j = 0; j < i; j++)

	{

		list1->Head = list1->Head->Next;

	}

	list1->Head = list2->Head->Prev;

	list2->Head->Prev = list1->Head;

	while (list2->Tail->Next != NULL) {

		list2->Head = list2->Head->Next;

	}

	list2->Head->Next = list1->Tail->Prev;

	list1->Tail->Prev = list2->Head->Next;

	return 0;

}