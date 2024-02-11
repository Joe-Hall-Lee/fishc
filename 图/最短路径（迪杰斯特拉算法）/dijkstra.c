#define MAXVEX 9
#define INFINITY 65535
#include <stdbool.h>
#include <stdio.h>
#define MAGEDGE 4950
#define OK 1

typedef int ArcType;	 // ����ߵ�Ȩֵ����Ϊ����
typedef char VerTexType; // �趥�����������Ϊ�ַ���
typedef int Status;

typedef struct
{
	VerTexType vexs[MAXVEX];  // �����
	int arcs[MAXVEX][MAXVEX]; // �ڽӾ���
	int vexnum, arcnum;		  // ͼ�ĵ�ǰ�����ͱ���
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
			G->arcs[i][j] = INFINITY; // �ߵ�Ȩֵ����Ϊ����ֵ
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

typedef int Patharc[MAXVEX];		// ���ڴ洢���·���±������
typedef int ShortPathTable[MAXVEX]; // ���ڴ洢������·����Ȩֵ��

void ShortestPath_Dijkstar(MGraph G, int V0, Patharc *P, ShortPathTable *D)
{
	int V, w, k, min;
	int final[MAXVEX]; // final[w] = 1 ��ʾ�Ѿ���ö��� V0 �� Vw �����·��

	// ��ʼ������
	for (V = 0; V < G.vexnum; V++)
	{
		final[V] = 0;			 // ȫ�������ʼ��Ϊδ�ҵ����·��
		(*D)[V] = G.arcs[V0][V]; // ���� V0 �����ߵĶ������Ȩֵ
		(*P)[V] = 0;			 // ��ʼ��·������ P Ϊ 0
	}

	(*D)[V0] = 0;  // V0 �� V0 ��·��Ϊ 0
	final[V0] = 1; // V0 �� V0 ����Ҫ��·��

	// ��ʼ��ѭ����ÿ����� V0 ��ĳ�� V ��������·��
	for (V = 1; V < G.vexnum; V++)
	{
		min = INFINITY;
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
			final[k] = 1; // ��Ŀǰ�ҵ�������Ķ����� 1
		}

		// ������ǰ���·��������
		for (w = 0; w < G.vexnum; w++)
		{
			// �������V�����·������������·�����ȶ̵Ļ������£�
			if (!final[w] && (min + G.arcs[k][w] < (*D)[w])) // �޸ĵ�ǰ·������
			{
				(*D)[w] = min + G.arcs[k][w]; // �޸ĵ�ǰ·������
				(*P)[w] = k;				  // ���ǰ������
			}
		}
	}
}
