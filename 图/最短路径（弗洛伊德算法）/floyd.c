#include <stdbool.h>
#include <stdio.h>
#define MaxInt 65535 // ��ʾ����ֵ���� ��
#define MVNum 9		 // ��󶥵���
#define MAGEDGE 4950
#define OK 1

typedef int ArcType;	 // ����ߵ�Ȩֵ����Ϊ����
typedef char VerTexType; // �趥�����������Ϊ�ַ���
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum]; // �����
	int arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum;		// ͼ�ĵ�ǰ�����ͱ���
} MGraph;

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
		scanf("%c", &(G->vexs[i])); // ������������Ϣ

	for (int i = 0; i < G->vexnum; ++i) // ��ʼ���ڽӾ���
	{
		for (int j = 0; j < G->vexnum; ++j)
			G->arcs[i][j] = MaxInt; // �ߵ�Ȩֵ����Ϊ����ֵ
	}

	for (int k = 0; k < G->arcnum; ++k) // �����ڽӾ���
	{
		int v1, v2;
		ArcType w;
		scanf("%d%d%d", &v1, &v2, &w); // ����һ�����������Ķ��㼰�ߵ�Ȩֵ
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);	   // ȷ�� v1 �� v2 �� G �е�λ��
		G->arcs[i][j] = w;			   // �� <v1, v2> ��Ȩֵ��Ϊ w
		G->arcs[j][i] = G->arcs[i][j]; // �� <v1, v2> �ĶԳƱ� <v2, v1> ��ȨֵΪ w
	}								   // for
	return OK;
} // CreateUDN

typedef int Pathmatrix[MVNum][MVNum];
typedef int ShortPathTable[MVNum][MVNum];

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
	int v, w, k;

	// ��ʼ�� D �� P
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			(*D)[v][w] = G.arcs[v][w];
			(*P)[v][w] = w;
		}
	}

	// �����ĸ��������㷨
	for (k = 0; k < G.vexnum; k++)
	{
		for (v = 0; v < G.vexnum; v++)
		{
			for (w = 0; w < G.vexnum; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}
}
