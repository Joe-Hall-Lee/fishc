#define MAXSIZE 1000
#define OK 1
/* �ھ�̬����L�е�i��Ԫ��֮ǰ�����µ�����Ԫ�� */
typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data;  // ����
	int cur;  //�α�(Cursor)
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;

	return OK;
}