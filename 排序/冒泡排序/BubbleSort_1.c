#include <stdio.h>

void BubbleSort_1(int k[], int n)
{
	int i, j, temp, count1 = 0, count2 = 0;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			count1++;
			if (k[i] > k[j])
			{
				count2++;
				temp = k[j];
				k[j] = k[i];
				k[i] = temp;
			}
		}
	}

	printf("�ܹ������� %d �αȽϣ������� %d ���ƶ���", count1, count2);
}

int main1()
{
	int i, a[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};

	BubbleSort_1(a, 10);

	printf("�����Ľ���ǣ�");
	for (i = 0; i < 10; i++)
		printf("%d", a[i]);

	printf("\n\n");

	return 0;
}
