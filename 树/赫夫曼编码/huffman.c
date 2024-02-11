#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"
#include "queue.h"

void traverseTree(htNode *treeNode, hlTable **table, int k, char code[256])
{
	if (treeNode->left == NULL && treeNode->right == NULL)
	{
		code[k] = '\0';
		hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
		aux->code = (char *)malloc(sizeof(char) * (strlen(code) + 1));
		strcpy(aux->code, code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;

		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		else
		{
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}

	if (treeNode->left != NULL)
	{
		code[k] = '0';
		traverseTree(treeNode->left, table, k + 1, code);
	}
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		traverseTree(treeNode->right, table, k + 1, code);
	}
}

hlTable *buildTable(htTree *huffmanTree)
{
	hlTable *table = (hlTable *)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;

	char code[256];
	int k = 0;

	traverseTree(huffmanTree->root, &table, k, code);
	return table;
}

htTree *buildTree(char *inputString) // ���� Huffman ��
{
	// ��ʼ��
	int *probability = (int *)malloc(sizeof(int) * 256); // ��������
	for (int i = 0; i < 256; i++)
		probability[i] = 0; // ���������ʼ��
	// ͳ�ƴ�������ַ��������ַ����ֵĴ���
	for (int j = 0; inputString[j] != '\0'; j++)
		probability[(unsigned char)inputString[j]]++; // ��������ַ���������ʱ��һֱѭ������ӦASCII����������±������Ԫ��+1

	pQueue *huffmanqueue;
	initPQueue(&huffmanqueue); // ���ɲ���ʼ�� Huffman ������

	// ������
	for (int k = 0; k < 256; k++)
	{
		if (probability[k] != 0) // probablity[k] != 0 ˵�� k ������Ӧ�� ASCII ��������ַ�����
		{
			htNode *aux = (htNode *)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k; // ������ת��Ϊ�ַ�

			addPQueue(&huffmanqueue, aux, probability[k]); // Huffman �������ӣ�����Ԫ�ص�ֵ��ΪȨֵ������ʱ��������
		}
	}

	free(probability); // �ͷ�����

	// ����Huffman��
	while (huffmanqueue->size != 1) // ������ֻ��һ�����ʱ���Ǿ��Ǹ����
	{
		// �������ϲ�
		int priority = huffmanqueue->first->priority;
		priority += huffmanqueue->first->next->priority;
		htNode *left = getPQueue(&huffmanqueue); // ǰ�������������
		htNode *right = getPQueue(&huffmanqueue);
		htNode *newNode = (htNode *)malloc(sizeof(htNode)); // ���������Ȩֵ��ӣ��γ��µ� Huffman �����
		newNode->left = left;								// ���Һ��Ӹ�ֵ������ȨֵС���Һ���
		newNode->right = right;
		addPQueue(&huffmanqueue, newNode, priority); // �½���������������
	}
	htTree *tree = (htTree *)malloc(sizeof(htTree)); // ���� Huffman �����ڵ�
	tree->root = getPQueue(&huffmanqueue);			 // ����Ϊ Huffman ���ĸ��ڵ�

	return tree; // ���ظ����
}

void encode(hlTable *table, char *stringToEncode)
{
	hlNode *traversal;

	printf("Encoding......\n\nInput string : \n%s\n\nEncoded string : ", stringToEncode);

	for (int i = 0; stringToEncode[i] != '\0'; i++)
	{
		traversal = table->first;
		while (traversal->symbol != stringToEncode[i])
			traversal = traversal->next;
		printf("%s", traversal->code);
	}

	printf("\n");
}

void decode(htTree *tree, char *stringToDecode)
{
	int index = 0;
	htNode *traversal = tree->root;

	printf("\n\nDecoding...\n\nInput string : \n%s\nDecoded string : \n", stringToDecode);

	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		if (traversal->left == NULL && traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}

		if (stringToDecode[i] == '0')
			traversal = traversal->left;

		if (stringToDecode[i] == '1')
			traversal = traversal->right;

		if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
		{
			printf("The input string is not coded correctly!\n");
			return;
		}
		if (traversal->left == NULL && traversal->right == NULL) // ����Ѿ�����Ҷ��㣬�����Ҷ�����ַ�
		{
			printf("%c", traversal->symbol);
			traversal = tree->root; // ���´Ӹ���㿪ʼ��
			index = i;
		}
	}
}
