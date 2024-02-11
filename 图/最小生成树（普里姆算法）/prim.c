#include <stdbool.h>
#include <stdio.h>
#define MaxInt 32767 // ��ʾ����ֵ���� ��
#define MVNum 100	 // ��󶥵���
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
		scanf("%c", &(G->vexs[i]));		// ������������Ϣ
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
		int j = LocateVex(*G, v2);	   // ȷ�� v1 �� v2 ��G�е�λ��
		G->arcs[i][j] = w;			   // �� <v1, v2> ��Ȩֵ��Ϊ w
		G->arcs[j][i] = G->arcs[i][j]; // �� <v1, v2> �ĶԳƱ� <v2, v1> ��ȨֵΪ w
	}								   // for
	return OK;
} // CreateUDN

// Prim �㷨������С������
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MVNum];	// ������ض����±�
	int lowcost[MVNum]; // ������ض����ߵ�Ȩֵ

	lowcost[0] = 0; // v0 ��Ϊ��С�������ĸ���ʼ������ȨֵΪ 0
	adjvex[0] = 0;	// v0 ��һ������

	// ��ʼ������
	for (i = 1; i < G.vexnum; i++)
	{
		lowcost[i] = G.arcs[0][i]; // ���ڽӾ���� 0 ������Ȩֵ�ȼ�������
		adjvex[i] = 0;			   // ��ʼ��ȫ����Ϊ v0 ���±�
	}

	// ����������С�������Ĺ���
	for (i = 1; i < G.vexnum; i++)
	{
		min = MaxInt; // ��ʼ����СȨֵΪ��������ֵ
		j = 1;
		k = 0;

		// ����ȫ������
		while (j < G.vexnum)
		{
			// �ҳ� lowcost �����Ѵ洢����СȨֵ
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j; // �����ֵ���СȨֵ���±���� k���Դ�ʹ�á�
			}
			j++;
		}

		// ��ӡ��ǰ�������Ȩֵ��С�ı�
		printf("(%d, %d)", adjvex[k], k);
		lowcost[k] = 0; // ����ǰ�����Ȩֵ����Ϊ 0����ʾ�˶����Ѿ�������񣬽�����һ������ı���

		// �ڽӾ���k���������ȫ������
		for (j = 1; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;
			}
		}
	}
}
