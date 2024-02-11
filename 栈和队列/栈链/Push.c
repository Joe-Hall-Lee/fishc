#include <stdlib.h>
#define OK 1

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
Status Push(LinkStack *s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
}