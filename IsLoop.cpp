LinkList* IsLoop(LinkList* list)
{
	if (list == NULL || list->next == NULL) return NULL;

	LinkList* p = list, * q = list;//p��q��

	while (p != NULL && p->next != NULL)//��Ϊpһ��������
	{
		p = p->next->next;
		q = q->next;

		if (p == q)//��ָ�����������������л�
		{
			break;
		}
	}

	if (p != q)//û�л�
	{
		return NULL;
	}

	q = list;//��һ�������󣬽���ָ��qָ��ͷ ��������
	while (p != q) //ѭ���˳�����ָ������(���)����ʱָ��ָ��Ľ������뻷�ĵ�һ�����
	{
		p = p->next;
		q = q->next;
	}
	return p;
}
