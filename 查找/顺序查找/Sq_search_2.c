// ˳������Ż�������a ΪҪ���ҵ����飬n ΪҪ���ҵ�����ĳ��ȣ�key ΪҪ���ҵĹؼ���
int Sq_search(int *a, int n, int key)
{
	int i = n;
	a[0] = key;
	while (a[i] != key)
		i--;

	return i;
}
