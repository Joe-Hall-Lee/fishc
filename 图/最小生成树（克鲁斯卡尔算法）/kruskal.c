#include <stdbool.h>
#include <stdio.h>
#define MaxInt 32767 // ��ʾ����ֵ���� ��
#define MVNum 100	 // ��󶥵���
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

// Kruskal �㷨������С������
int Find(int *parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

typedef struct
{
	int begin;	// �ߵ���ʼ����
	int end;	// �ߵ���ֹ����
	int weight; // �ߵ�Ȩֵ
} Edge;

void MiniSpanTree_Kurskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAGEDGE]; // ����߼�����
	int parent[MVNum];	 // ���� parent ���������жϱ�����Ƿ��γɻ�·

	for (i = 0; i < G.vexnum; i++)
		parent[i] = 0;

	for (i = 0; i < G.arcnum; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);

		if (n != m) // ��� n == m�����γɻ�·�������㣡
		{
			parent[n] = m; // ���˱ߵĽ�β��������±�Ϊ���� parent �����У���ʾ�˶����Ѿ���������������
			printf("(%d, %d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
