#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
	ElemType *base; // ���ڴ���ڴ�������ַ��Ҳ������������
	int front;
	int rear;
} cycleQuene;

DeleteQuene(cycleQuene *q, ElemType *e)
{
	if (q->front == q->rear)
		return; // ����Ϊ��
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}