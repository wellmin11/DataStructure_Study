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


	//������ LIFO (Last In First Out)�� �ڷᱸ���Դϴ� 

	// ������ �ʱ�ȭ���ش�.
	int InitStack(Stack* stack);

	//������ �����͸� ���ؿ� �ִ´� 
	int Push(Stack* stack, int Data);

	//Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�ϰ� ����Ʈ���� �����Ѵ�.
	int Pop(Stack* stack);

	//Top ��ġ�� �ִ� ������ ����Ÿ�� ��ȯ�Ѵ�.
	int Top(Stack* stack);

	//�����Ҵ�� �޸𸮵��� ���� �������ش�.
	int Destroy(Stack* stack);
#ifdef __cplusplus
}
#endif // __cplusplus
