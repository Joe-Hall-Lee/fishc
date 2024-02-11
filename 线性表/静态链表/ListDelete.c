#define ERROR 0
#define OK 1
#define MAX_SIZE 1000

/* ɾ���� L �еĵ� i ������Ԫ�� */
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType data; // ����
	int cur;	   // �α꣨Cursor��
} Component, StaticLinkList[MAX_SIZE];

Status ListDelete(StaticLinkList L, int i)
{
	int j, k;

	if (i < 1 || i > ListLength(L))
	{
		return ERROR;
	}

	k = MAX_SIZE - 1;

	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur; // k1 = 1; k2 = 5
	}

	j = L[k].cur; // j = 2
	L[k].cur = L[j].cur;

	Free_SLL(L, j);

	return OK;
}

/* ���±�Ϊ k �Ŀ��н����յ��������� */
void Free_SLL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/* ���� L ������Ԫ�ظ��� */
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAX_SIZE - 1].cur;

	while (i)
	{
		i = L[i].cur;
		j++;
	}

	return j;
}