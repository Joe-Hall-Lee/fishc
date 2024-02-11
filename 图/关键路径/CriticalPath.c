#include <stdlib.h>
#define MAXVEX 9
#define OK 1
#define ERROR 0

typedef int Status;

// �߱�������
typedef struct EdgeNode
{
	int weight;
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

int *etv, *ltv;
int *stack2; // ���ڴ洢�ز����е�ջ
int top2;

// �ز������㷨
// �� GL �޻�·��������ز��������в����� OK�����򷵻� ERROR
Status ToplogicalSort(GraphAdjList GL)
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

	// ��ʼ�� etv ��Ϊ 0
	top2 = 0;
	etv = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
		etv[i] = 0;

	stack2 = (int *)malloc(GL->numVertexes * sizeof(int));

	while (0 != top)
	{
		gettop = stack[--top]; // ��ջ
		// printf("%d -> ", GL->adjlist[gettop].data);
		stack2[top2++] = gettop; // �����ز�����˳��
		count++;

		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			// ע�⣺�±���� if �����Ƿ������������Ҫ�㣡
			// ��k�Ŷ����ڽӵ����� -1����Ϊ����ǰ���Ѿ�����
			// �����ж� -1 ������Ƿ�Ϊ 0�����Ϊ 0 ��Ҳ��ջ
			if (!(--GL->adjList[k].in))
				stack[top++] = k;

			if ((etv[gettop] + e->weight) > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}

	if (count < GL->numVertexes) // ��� count С�ڶ�������˵�����ڻ�
		return ERROR;
	else
		return OK;
}

// ��ؼ�·����GL Ϊ����ͼ����� GL �ĸ���ؼ��
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;

	// ���øĽ�����ز�������� etv �� stack2 ��ֵ
	ToplogicalSort(GL);

	// ��ʼ�� ltv ��Ϊ����ʱ��
	ltv = (int *)malloc(GL->numVertexes * sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
		ltv[i] = etv[GL->numVertexes - 1];

	// �ӻ�㵹����������� ltv
	while (0 != top2)
	{
		gettop = stack2[top2--]; // ע�⣬��һ����ջ�ǻ��
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if ((ltv[k] - e->weight) < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}

	// ͨ�� etv �� ltv �� ete �� lte
	for (j = 0; j < GL->numVertexes; j++)
	{
		for (e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;

			if (ete == lte)
				printf("<v%d, v%d> length: %d, ", GL->adjList[j].data, GL->adjList[k].data, e->weight);
		}
	}
}
