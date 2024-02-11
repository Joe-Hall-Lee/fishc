#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
	ElemType *base; // ���ڴ���ڴ�������ַ��Ҳ������������
	int front;
	int rear;
} cycleQuene;

InsertQuene(cycleQuene *q, ElemType e)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return; // ��������
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}