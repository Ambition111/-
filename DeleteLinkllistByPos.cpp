//时间复杂度为O(n),能够删除的重复的元素
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
