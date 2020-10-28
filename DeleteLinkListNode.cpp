
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

//O(1)删除非尾结点p
bool DeleteLinkListNode(LinkList* list, LinkList* p)
{
	if (list == NULL || p == NULL) exit(0);

	//如果p是尾结点，则直接调用尾删
	if (p->next == NULL)
	{
		DeleteLinkListTail(list);
		return true;
	}

	LinkList* q = p->next;//q是将来真正删除的结点
	p->data = q->data;
	p->next = q->next;

	free(q);
	return true;
}
