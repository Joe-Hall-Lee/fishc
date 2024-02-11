#include <stdbool.h>
#include <stdio.h>
#define MaxInt 32767 // ��ʾ����ֵ���� ��
#define MVNum 100	 // ��󶨵���
#define OK 1
#define ERROR 0
#define MAXQSIZE 100 // �����г���
#define OVERFLOW -2

typedef char VerTexType; // �趥�����������Ϊ�ַ���
typedef int Status;

typedef struct
{
	int *base; // ��̬����洢�ռ�
	int front; // ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;  // βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
} Queue;

Status InitQueue(Queue *Q)
{
	Q->base = (VerTexType *)malloc(MAXQSIZE * sizeof(VerTexType)); // ��������ռ�

	if (!Q->base)
		exit(OVERFLOW); // �洢����ʧ��

	Q->front = Q->rear = 0; // ͷָ�롢βָ����Ϊ 0������Ϊ��
	return OK;
}

int QueueLength(Queue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}
Status EnQueue(Queue *Q, int i)
{
	if ((Q->rear + 1) % MAXQSIZE == Q->front)
		return ERROR;
	Q->base[Q->rear] = i;				// ��Ԫ�ؼ����β
	Q->rear = (Q->rear + 1) % MAXQSIZE; // ��βָ�� + 1
	return OK;
}

Status DeQueue(Queue *Q, int *i)
{
	if (Q->front == Q->rear)
		return ERROR;					  // �ӿ�
	*i = Q->base[Q->front];				  // �����ͷԪ��
	Q->front = (Q->front + 1) % MAXQSIZE; // ��ͷָ�� + 1
	return OK;
}

typedef struct
{
	VerTexType vexs[MVNum]; // �����
	int arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum;		// ͼ�ĵ�ǰ�����ͱ���
} MGraph;

VerTexType GetHead(Queue Q)
{
	if (Q.front != Q.rear)		// ���в�Ϊ��
		return Q.base[Q.front]; // ���ض�ͷָ��Ԫ�ص�ֵ����ͷָ�벻��
}

int LocateVex(MGraph G, VerTexType u)
{
	// ͼ G �в��Ҷ��� u�������򷵻ض�����е��±ꣻ���򷵻� -1
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}

Status CreateUDN(MGraph *G) // �����ڽӾ����ʾ�������������� G
{
	scanf("%d%d", &(G->vexnum), &(G->arcnum)); // �����ܶ��������ܱ���
	for (int i = 0; i < G->vexnum; ++i)
		scanf("%c", &(G->vexs[i]));		// ������������Ϣ
	for (int i = 0; i < G->vexnum; ++i) // ��ʼ���ڽӾ���
	{
		for (int j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = MaxInt; // �ߵ�Ȩֵ����Ϊ����ֵ
	}

	for (int k = 0; k < G->arcnum; ++k) // �����ڽӾ���
	{
		VerTexType v1, v2;
		int w;
		scanf("%c%c%d", &v1, &v2, &w);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2); // ȷ�� v1 �� v2 �� G �е�λ��
		G->arcs[i][j] = w;
		G->arcs[j][i] = G->arcs[i][j];
	}
	return OK;
}

// �ڽӾ���Ĺ�������㷨

void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	bool *visited = (bool *)malloc(sizeof(bool) * G.vexnum);
	for (i = 0; i < G.vexnum; i++)
		visited[i] = false;

	InitQueue(&Q);

	for (i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			printf("%c", G.vexs[i]);
			visited[i] = true;
			EnQueue(&Q, i);

			while (!(Q.front == Q.rear))
			{
				DeQueue(&Q, &i);
				for (j = 0; j < G.vexnum; j++)
				{
					if (G.arcs[i][j] == 1 && !visited[j])
					{
						printf("%c", G.vexs[j]);
						visited[i] = true;
						EnQueue(&Q, i);
					}
				}
			}
		}
	}
}
