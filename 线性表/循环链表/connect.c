// ���� A��B Ϊ�ǿ�ѭ�������βָ��

typedef struct LinkList
{
	int data; // ������
	struct LinkList *next;
} *LinkList;

LinkList Connect(LinkList A, LinkList B)
{
	LinkList p = A->next; // ���� A ���ͷ�ڵ�λ�á�

	A->next = B->next->next; // B ��Ŀ�ʼ������ӵ� A ��β

	free(B->next); // �ͷ� B ���ͷ��㣬��ѧ����������

	B->next = p;

	return B; // ������ѭ�������βָ��
}