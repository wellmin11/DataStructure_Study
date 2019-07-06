#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

//스택은 LIFO (Last In First Out)형 자료구조입니다 
//데이터는 양의 정수로 가정합니다.

// 스택을 초기화해준다.성공시 0
int InitStack(Stack* stack)
{
	if (stack == NULL)  return -1;
	stack->Head = NULL;
	return 0;
}

//정수형 데이터를 스텍에 넣는다 성공시 1 실패시 -1
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

//stack 의 Top 위치에 있는 정수형 데이타를 반환하고 리스트에서 제거한다. 성공시 1 , 아무것도 없을때 Pop 시에는 -1 반환
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

//Top 위치에 있는 정수형 데이타를 반환한다. 성공시 1 , 실패시 -1(아무것도 없을때)
int Top(Stack* stack)
{
	if (stack == NULL) return -1;
	return stack->Head->Data;
}

//동적할당된 메모리들을 전부 해제해준다. 성공시 0 실패시 -1
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