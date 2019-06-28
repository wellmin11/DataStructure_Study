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


	//ȯ�� ����Ʈ �ʱ�ȭ, ������ 0 ��ȯ, ���н� -1 (�̹� �ʱ�ȭ�� �� ����� ���� �Ѱ��̻��� ��尡 �����ϴ� ��� -1 ��ȯ)
	int InitList(CircularList* clist);

	// ������ �����͸� ���� ��带 ����Ʈ�� element �� �������� �߰������ش� (������ 0, �����Ҵ� ���н� -1)
	int AddNode(CircularList* clist, Node* element, int data);

	// element node �� ã�´�, ã���� 0, ������ -1
	int FindNode(CircularList* clist, Node* element);

	// element node �� ã�Ƽ� ����� 
	int RemoveNode(CircularList* clist, Node* element);

	//ȯ�� ����Ʈ �ı��ϱ� ������ 0 ��ȯ, ���н� -1 (�ƹ� ��尡 ���°�� -1, �ʱ�ȭ�� �ѻ��¶�� ����)
	int DestroyList(CircularList* clist);



#ifdef __cplusplus
}
#endif // __cplusplus