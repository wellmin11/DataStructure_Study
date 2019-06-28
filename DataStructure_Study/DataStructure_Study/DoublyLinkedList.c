#include "DoublyLinkedList.h"
#include <stdlib.h>

static int listSize = 0;

//����Ʈ�� �ʱ�ȭ�Ѵ� 
int InitList(List* list)
{

	list->Head = NULL;

	list->Tail = NULL;

	return 0;

}



// int ���� data �� ����Ʈ�� Tail �ڿ� �߰��Ѵ� ������ 0 ��ȯ ���н� -1 ��ȯ�ϱ�
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



//Head ���κ��� i ��°�� ����� �����͸� �����´� ������ 0 , ���н� -1 ��ȯ�ϱ�
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



// ����Ʈ�� ����� ��ȯ �ϱ�
int GetListSize(List* list)
{

	return listSize;

}



// i ��°�� ��带 ����� (����� ���ٸ� -1, ����� �����ϸ� 0 ��ȯ)

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



//  ����Ʈ �����ϱ� �����Ұ� ������ -1 ��ȯ ������ 0
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





// i��° ����� �����͸� �����´� 
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



//i ��°�� ����Ʈ�� �߰��Ѵ� 
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