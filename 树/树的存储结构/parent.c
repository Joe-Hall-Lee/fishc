// ����˫�ױ�ʾ�����ṹ����
#define MAX_TREE_SIZE 100

typedef int ElemType;

typedef struct PINode
{
	ElemType data; // �������
	int parent;	   // ˫��λ��
} FTNode;

typedef struct
{
	FTNode nodes[MAX_TREE_SIZE];
	int r; // ����λ��
	int n; // �����Ŀ
} PTree;