#define MAXSIZE 100

typedef int ElemType;
typedef struct
{
	ElemType *base; // ���ڴ���ڴ�������ַ��Ҳ������������
	int front;
	int rear;
} cycleQuene;

initQuene(cycleQuene *q)
{
	q->base = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base)
		exit(0);
	q->front = q->rear = 0;
}