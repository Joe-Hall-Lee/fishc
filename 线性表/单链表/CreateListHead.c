#include <stdio.h>

/* ͷ�巨����������ʾ�� */
typedef int ElemType;
typedef struct Node
{
	ElemType data;	   // ������
	struct Node *next; // ָ����
} Node, *LinkList;

void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;

	srand(time(0)); // ��ʼ�����������

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node)); // �����½��
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
