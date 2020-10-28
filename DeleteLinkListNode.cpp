
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

//O(1)ɾ����β���p
bool DeleteLinkListNode(LinkList* list, LinkList* p)
{
	if (list == NULL || p == NULL) exit(0);

	//���p��β��㣬��ֱ�ӵ���βɾ
	if (p->next == NULL)
	{
		DeleteLinkListTail(list);
		return true;
	}

	LinkList* q = p->next;//q�ǽ�������ɾ���Ľ��
	p->data = q->data;
	p->next = q->next;

	free(q);
	return true;
}
