#include <stdio.h>

typedef int ElemType;

typedef struct QNode
{
	ElemType data;
	struct QNode *next;
} QNode, *QuenePtr;

typedef struct
{
	QuenePtr front, rear; // ��ͷ��βָ��
} LinkQuene;

initQuene(LinkQuene *q)
{
	q->front = q->rear = (QuenePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}