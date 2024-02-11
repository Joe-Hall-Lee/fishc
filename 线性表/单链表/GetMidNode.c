#include <stdio.h>
#define OK 1;

typedef int Status;
typedef int ElemType;
typedef struct Node
{
	ElemType data;	   // ������
	struct Node *next; // ָ����
} Node, *LinkList;

Status GetMidNode(LinkList L, ElemType *e)
{
	LinkList search, mid;
	mid = search = L;

	while (search->next != NULL)
	{
		// search �ƶ����ٶ��� mid ������
		if (search->next->next != NULL)
		{
			search = search->next->next;
			mid = mid->next;
		}
		else
		{
			search = search->next;
		}
	}

	*e = mid->data;

	return OK;
}