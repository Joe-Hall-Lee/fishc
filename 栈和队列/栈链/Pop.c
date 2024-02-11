#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int ElemType;

typedef struct StackNode
{
	ElemType data; // ���ջ������
	struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; // top ָ��
	int count;		  // ջԪ�ؼ�����

} LinkStack;

typedef int Status;
Status Pop(LinkStack *s, ElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*s)) // �ж��Ƿ�Ϊ��ջ
	{
		return ERROR;
	}

	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return OK;
}