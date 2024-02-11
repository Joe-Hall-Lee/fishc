#define MAX_SIZE 1000
#define ERROR 0
/* �ھ�̬���� L �е� i ��Ԫ��֮ǰ�����µ�����Ԫ�� */
typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data; // ����
	int cur;	   // �α꣨Cursor��
} Component, StaticLinkList[MAX_SIZE];

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
		// ������һ������������Ϊ���á�
	}
	return i;
}
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;

	k = MAX_SIZE - 1; // ��������һ��Ԫ��

	if (i < 1 || i > ListLength(L) + 1)
	{
		return ERROR;
	}

	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i - 1; l++)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
	}
}