#define _CRT_SECURE_NO_WARNINGS

#include "ds_insert.h"

// /* ������ */
// /* ����������ĵ�һ����㣬�����λ�� */
void ds_insert(node **pNode, int i)
{
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;

	printf("����Ҫ�������ֵ:");
	scanf("%d", &item);

	if (i == 1)
	{
		// �²���Ľ����Ϊ��һ�����
		temp = (node *)malloc(sizeof(struct CLinkList));
		if (!temp)
		{
			exit(0);
		}

		temp->data = item;

		/* Ѱ�����һ����� */
		for (target = (*pNode); target->next != (*pNode); target = target->next)
			;

		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;
	}
	else
	{
		target = *pNode;

		for (; j < (i - 1); ++j)
		{
			target = target->next;
		}

		// target ָ��ڶ���Ԫ��

		temp = (node *)malloc(sizeof(struct CLinkList));

		temp->data = item;

		p = target->next;
		target->next = temp;
		temp->next = p;
	}
}