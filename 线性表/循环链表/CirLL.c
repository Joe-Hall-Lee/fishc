#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ds_init.h"
#include "ds_delete.h"
#include "ds_search.h"
#include "ds_insert.h"

/***********************************************************/
/*����                                                     */
/***********************************************************/

/*����*/
void ds_traverse(node *pNode) // ������ѭ������ı�������� do while ��� ����Ϊͷ�ڵ����ֵ
{
	node *temp;
	temp = pNode;
	do
	{
		printf("%5d", temp->data);
		temp = temp->next;
	} while (temp != pNode);

	printf("\n");
}

int main()
{
	node *pHead = NULL;
	char opp = 1;
	int find;

	printf("1. ��ʼ���б�\n\n2. ������\n\n3. ɾ�����\n\n4.���ؽ��λ��\n\n5. �����б�\n\n0. �˳�\n\n��ѡ����Ĳ�����");

	while (opp != '0')
	{
		scanf("%c", &opp);
		switch (opp)
		{
		case '1':
			ds_init(&pHead);
			printf("\n");
			ds_traverse(pHead);

			break;

		case '2':
			printf("������Ҫ�������λ�á�");
			scanf_s("%d", &find);
			ds_insert(&pHead, find);
			printf("��λ�� %d ����ֵ��:\n", find);
			ds_traverse(pHead);
			printf("\n");
			break;
		case '3':
			printf("������Ҫɾ���Ľ��λ�á�");
			scanf_s("%d", &find);
			printf("ɾ����%d������:\n", find);
			ds_delete(&pHead, find);
			ds_traverse(pHead);
			printf("\n");
			break;

		case '4':
			printf("��Ҫ�����ĸ�Ԫ�ص�λ�ã�");
			scanf_s("%d", &find);
			printf("Ԫ�� %d ����λ��:%d\n", find, ds_search(pHead, find));
			printf("\n");
			break;

		case '5':
			ds_traverse(pHead);
			printf("\n");
			break;
		case '0':
			exit(0);
		}
	}

	return 0;
}