#pragma once
#include <stdio.h>
#include <stdlib.h>
/* ����洢�ṹ�Ķ��� */
typedef struct CLinkList
{
	int data; // ������
	struct CLinkList *next;
} node;

/* ��ʼ��ѭ������ */
void ds_init(node **pNode);
