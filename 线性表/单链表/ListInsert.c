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

/* ����������� L �е� i ��λ��֮ǰ�����µ�����Ԫ�� e��L �ĳ��ȼ� 1 */
typedef int Status;
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;

	while (p && j < 1) // ����Ѱ�ҵ� i �����
	{
		p = p->next;
		j++;
	}

	if (!p || j > 1)
	{
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}
