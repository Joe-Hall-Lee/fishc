#define ERROR 0
#define OK 1
/* ��ʼ��������ʽ���Ա�L�Ѵ��ڣ�1 <= i <= ListLength(L) */

typedef int ElemType;

typedef struct Node
{
	ElemType data;	   // ������
	struct Node *next; // ָ����
} Node;
typedef struct Node *LinkList;

/* ���������ɾ�� L �ĵ� i ������Ԫ�أ����� e ������ֵ��L �ĳ��� -1 */
typedef int Status;

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;

	p = *L;
	j = 1;

	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j > i)
		return ERROR;

	q = p->next;
	p->next = q->next;

	*e = q->data;
	free(q);

	return OK;
}
