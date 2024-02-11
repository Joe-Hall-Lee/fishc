#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bin_search(int str[], int n, int key)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = low + (key - str[low]) * (high - low) / (str[high] - str[low]); // ��ֵ���ҵ�Ψһ��ͬ��

		if (str[mid] == key)
			return mid; // ���ҳɹ�
		if (str[mid] < key)
			low = mid + 1; // �ں�������в���
		if (str[mid] > key)
			high = mid - 1; // ��ǰ�������в���
	}

	return -1;
}

int main()
{
	int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	int m, addr;

	printf("����������ҵĹؼ���: ");
	scanf("%d", &m);

	addr = bin_search(str, 11, m);
	if (-1 != addr)
	{
		printf("���ҳɹ�����ϲ�ɺأ��ɿڿ��֣��ؼ��� %d ���ڵ�λ����: %d\n", m, addr);
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}

	return 0;
}
