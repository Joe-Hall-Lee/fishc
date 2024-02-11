#define ERROR 0
#define OK 1
/* ��ʼ��������ʽ���Ա� L �Ѵ��ڣ�1 <= i <= ListLength(L) */

typedef int ElemType;

typedef struct Node
{
	ElemType data;	   // ������
	struct Node *next; // ָ����
} Node;
typedef struct Node *LinkList;

/* �����������e����L�е�i������Ԫ�ص�ֵ */
typedef int Status;

Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;

	p = L->next;
	j = 1;

	while (p && j < i)
	{
		p = p->next;
		++j;
	}

	if (!p || j > i)
	{
		return ERROR;
	}

	*e = p->data;

	return OK;
}