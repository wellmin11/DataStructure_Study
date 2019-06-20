#pragma once
#pragma once

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	typedef struct node
	{
		struct node* Next;
		struct node* Prev;
		int Data;
	}Node;


	typedef struct list
	{
		Node* Head;
		Node* Tail;
	}List;

	//����Ʈ�� �ʱ�ȭ�Ѵ� 
	int InitList(List* list);

	// int ���� data �� ����Ʈ�� Tail �ڿ� �߰��Ѵ� ������ 0 ��ȯ ���н� -1 ��ȯ�ϱ�
	int AddNode(List* list, int data);

	//Head ���κ��� i ��°�� ����� �����͸� �����´� ������ 0 , ���н� -1 ��ȯ�ϱ�
	int GetData(List* list, int i);

	// ����Ʈ�� ����� ��ȯ �ϱ�
	int GetListSize(List* list);

	// i ��°�� ��带 ����� (����� ���ٸ� -1, ����� �����ϸ� 0 ��ȯ)
	int RemoveNodeFromList(List* list, int i);

	//  ����Ʈ �����ϱ� �����Ұ� ������ -1 ��ȯ ������ 0
	int DestroyList(List* list);

	// i��° ����� �����͸� �����´� 

	Node* GetNode(List* list, int i);

	//list1�� i ��° �ε��� ��忡 list2�� �߰��Ѵ�. (����ִ°�� -1 ��ȯ, ������ 0 ��ȯ)
	int AddList(List* list1, List* list2, int i);

	// list �� Tail �ڿ� node �� �߰��Ѵ�
	int AddNodePtr(List* list, Node* node);

#ifdef __cplusplus
}
#endif // __cplusplus

