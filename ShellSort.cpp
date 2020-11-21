void Shell(int* arr, int len, int group)
{
	for (int i = group; i < len; ++i)		// i ��������������ݶΣ����Ʊ���ֱ�Ӳ�����������һ�������
	{
		int tmp = arr[i];
		int j = 0; 

		for (j = i - group; j >= 0; j -= group)
		{
			if (arr[j] <= tmp)
				break;

			arr[j + group] = arr[j];
		}

		arr[j + group] = tmp;
	}
}
/*
	ʱ�临�Ӷȣ�O(n^1.3 ~ n^1.5) ��ѧ�Ƶ��ó�
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ����ȶ�
*/
void ShellSort(int* arr, int len)
{
	int group[] = { 5, 3, 1};		//����û�б�׼�ķַ���һ�����������Լ����ã������������ǿ����Լ���
	
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); ++i)
	{
		Shell(arr, len, group[i]);
	}
}
