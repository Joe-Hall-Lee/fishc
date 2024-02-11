#include <stdio.h>
#include <stdlib.h>

// ����洢�ṹ
typedef struct LinkList
{
    int data;
    struct LinkList *next;
} node;
/** \brief ������ʼ��ѭ������
 *
 * \param ���� L
 * \param ����ĳ��� n
 * \return ��һ�����ĵ�ַ
 *
 */
node *CreateList(node *head, int n)
{
    node *rear;     // β���
    node *p, *temp; // ��ʱ���
    int i = 1;
    // ����һ�����
    if (head == NULL)
        head = (node *)malloc(sizeof(node));
    if (!head)
        exit(0);

    p = head;
    while (i <= n)
    {
        // ����һ�����
        temp = (node *)malloc(sizeof(node));
        if (!temp)
            exit(0);

        temp->data = i;
        p->next = temp;
        p = temp;
        i++;
    }
    // β���ָ���һ����㣬����ѭ������
    rear = p;
    rear->next = head->next;

    return rear->next;
}
/** \brief ��ӡ���ѭ������
 *
 * \param ��һ�����ĵ�ַ
 * \return ��
 *
 */
void print(node *pHead)
{
    node *temp;
    temp = pHead;

    while (1)
    {
        printf("%3d", temp->data);
        temp = temp->next;
        if (temp == pHead) // �ٴε����һ������λ��
            break;
    }
}

int main()
{
    int n; // ��Ž���
    node *L = NULL;
    node *pHead; // ��һ�����
    int count = 1;

    printf("��������������Ľ��� n = ");
    scanf_s("%d", &n);

    pHead = CreateList(L, n);
    while (count <= n)
    {
        print(pHead);
        printf("\n");
        pHead = pHead->next;
        count++;
    }

    return 0;
}