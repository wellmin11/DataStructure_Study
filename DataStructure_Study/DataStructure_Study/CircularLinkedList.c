#include "CircularLinkedList.h"
#include <stdio.h>

// ȯ�� ����Ʈ �ʱ�ȭ, ������ 0 ��ȯ, ���н� -1 (�̹� �ʱ�ȭ�� �� ����� ���� �Ѱ��̻��� ��尡 �����ϴ� ��� -1 ��ȯ)
int InitList(CircularList* clist)
{
	if (clist->Head == NULL || clist->Head->Next != NULL)
		return -1;
	else
		clist->Head = NULL;
	return 0;
}

// ������ �����͸� ���� ��带 ����Ʈ�� element �� �������� �߰������ش� (������ 0, �����Ҵ� ���н� -1)
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

// element node �� ã�´�, ã���� 0, ������ -1
int FindNode(CircularList* clist, Node* element)
{
	while (clist->Head->Next != NULL) {
		if (clist->Head == element)
			return  0;
	}
	return -1;
}

// element node �� ã�Ƽ� ����� 
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

// ȯ�� ����Ʈ �ı��ϱ� ������ 0 ��ȯ, ���н� -1 (�ƹ� ��尡 ���°�� -1, �ʱ�ȭ�� �ѻ��¶�� ����)
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
