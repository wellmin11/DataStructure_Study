#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

//������ LIFO (Last In First Out)�� �ڷᱸ���Դϴ� 
//�����ʹ� ���� ������ �����մϴ�.

// ������ �ʱ�ȭ���ش�.������ 0
int InitStack(Stack* stack)
{
	if (stack != NULL && stack->Head->Next != NULL)  return -1;
	stack->Head = NULL;
	return 0;
}

//������ �����͸� ���ؿ� �ִ´� ������ 1 ���н� -1
int Push(Stack* stack, int Data)
{
	if (stack->Head == NULL)
		return -1;
	Node* node = (Node*)malloc(sizeof(Node));
	node->Data = Data;

	while (stack->Head->Next != NULL) {
		stack->Head = stack->Head->Next;
	}
	stack->Head->Next = node;

	return 0;
}

//stack �� Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�ϰ� ����Ʈ���� �����Ѵ�. ������ 1 , �ƹ��͵� ������ Pop �ÿ��� -1 ��ȯ
int Pop(Stack* stack)
{
	int data = 0;
	if (stack->Head == NULL) return -1;

	Node* node = (Node*)malloc(sizeof(Node));
	node = stack->Head;

	while (node->Next != NULL) {
		node = node->Next;
	}
	data = node->Data;
	free(node);

	return data;
}

//Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�Ѵ�. ������ 1 , ���н� -1(�ƹ��͵� ������)
int Top(Stack* stack)
{
	if (stack->Head == NULL) return -1;
	
	while (stack->Head->Next != NULL) {
		stack->Head = stack->Head->Next;
	}
	return stack->Head->Data;
}

//�����Ҵ�� �޸𸮵��� ���� �������ش�. ������ 0 ���н� -1
int Destroy(Stack* stack)
{
	if (stack->Head == NULL) return -1;

	while (stack->Head->Next != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node = stack->Head;
		stack->Head = stack->Head->Next;
		free(node);
	}

	return 0;
}
