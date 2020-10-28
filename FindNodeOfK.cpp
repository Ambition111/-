
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

LinkList* FindNodeOfK(LinkList* list, int k)
{
	//˫ָ�룬����һ��ָ���ͷ��ʼ��k�Σ�Ȼ������ָ��ͬ������ߣ�ֱ��֮ǰ��ָ���ߵ���
	
	if (list == NULL || k <= 0) return NULL;//û�е�����0��

	LinkList* p = list, * q = list;
	while (k && q != NULL)
	{
		q = q->next;
		k--;
	}

	if (q == NULL) return NULL; //����k���ڳ���ʱ

	while (q != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}

