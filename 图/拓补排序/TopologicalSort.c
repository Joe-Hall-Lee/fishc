#include <stdlib.h>
#include <stdio.h>
#define MAXVEX 9
#define OK 1
#define ERROR 0

typedef int Status;

// �߱�������
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
} EdgeNode;

// �����������
typedef struct VertexNode
{
	int in; // �������
	int data;
	EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

// �ز��㷨����
// �� GL �޻�·��������ز��������в����� OK�����򷵻� ERROR
Status TopoloicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;   // ����ջָ���±�����
	int count = 0; // ����ͳ���������ĸ���
	int *stack;	   // ���ڴ洢���Ϊ 0 �Ķ���

	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
			stack[top++] = i; // ����Ϊ 0 �Ķ����±���ջ
	}

	while (0 != top)
	{
		gettop = stack[--top]; // ��ջ
		printf("%d -> ", GL->adjList[gettop].data);
		count++;

		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			// ע�⣺�±���� if �����Ƿ������������Ҫ�㣡
			// �� k �Ŷ����ڽӵ����� -1����Ϊ����ǰ���Ѿ�����
			// �����ж� -1 ������Ƿ�Ϊ 0�����Ϊ 0 ��Ҳ��ջ
			if (!(--GL->adjList[k].in))
				stack[top++] = k;
		}
	}

	if (count < GL->numVertexes) // ��� count С�ڶ�������˵�����ڻ�
		return ERROR;
	else
		return OK;
}
