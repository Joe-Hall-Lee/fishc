#include <stdlib.h>
#define STACKINCREMENT 10

typedef int ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
} sqStack;

Push(sqStack *s, ElemType e)
{
	// ���ջ����׷�ӿռ�
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stackSize;			  // ����ջ��
		s->stackSize = s->stackSize + STACKINCREMENT; // ����ջ���������
	}

	*(s->top) = e;
	s->top++;
}
