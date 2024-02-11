#include <stdio.h>

typedef char *String;

void get_next(String T, int *next)
{
	int j = 0;
	int i = 1;
	next[1] = 0;

	while (i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] != T[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}
		}
		else
		{
			// j ����
			j = next[j];
		}
		// ��Ϊǰ׺�ǹ̶��ģ���׺����Ե�
	}
}

// �����Ӵ������� S �� pos ���ַ�֮���λ��
// �������ڣ��򷵻� 0
int Index_KMP(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];

	get_next(T, next);

	while (i <= S[0] || j <= T[0])
	{
		if (0 == j || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j > T[0])
	{
		return i - T[0];
	}
}