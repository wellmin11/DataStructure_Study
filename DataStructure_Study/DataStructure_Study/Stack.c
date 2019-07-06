#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

//������ LIFO (Last In First Out)�� �ڷᱸ���Դϴ� 
//�����ʹ� ���� ������ �����մϴ�.

// ������ �ʱ�ȭ���ش�.������ 0
int InitStack(Stack* stack)
{
	if (stack == NULL)  return -1;
	stack->Head = NULL;
	return 0;
}

//������ �����͸� ���ؿ� �ִ´� ������ 1 ���н� -1
int Push(Stack* stack, int Data)
{
	if (stack == NULL) return -1;

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->Data = Data;
	printf("add node data %d \n", Data);

	if (stack->Head == NULL) {
		stack->Head = new_node;
	}
	else {
		new_node->Next = stack->Head;
		stack->Head = new_node;
	}

	return 0;
}

//stack �� Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�ϰ� ����Ʈ���� �����Ѵ�. ������ 1 , �ƹ��͵� ������ Pop �ÿ��� -1 ��ȯ
int Pop(Stack* stack)
{
	int data = 0;
	if (stack->Head == NULL) return -1;

	Node* node = (Node*)malloc(sizeof(Node));
	node = stack->Head;

	stack->Head = stack->Head->Next;
	data = node->Data;
	free(node);

	return data;
}

//Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�Ѵ�. ������ 1 , ���н� -1(�ƹ��͵� ������)
int Top(Stack* stack)
{
	if (stack == NULL) return -1;
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

int main(void)
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	InitStack(&stack);
	printf("Test Start! \n");

	for (int i = 1; i < 10; i++)
	{
		Push(&stack, i);
	}

	printf("Push Function Complete! \n");

	for (int i = 1; i < 10; i++)
	{
		int num = Pop(&stack);
		printf("%d \n", num);
	}

	printf("Pop Function Complete! \n");
	return 0;
}