//ʱ�临�Ӷ�ΪO(n),�ܹ�ɾ�����ظ���Ԫ��
void DeleteLinkListValue(LinkList* list, ElemType val)
{
	if (list == NULL) exit(0);

	LinkList* p = list;
	LinkList* q = p->next;

	while (q != NULL)
	{
		if (q->data == val)
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
}
