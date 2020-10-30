LinkList* IsLoop(LinkList* list)
{
	if (list == NULL || list->next == NULL) return NULL;

	LinkList* p = list, * q = list;//p快q慢

	while (p != NULL && p->next != NULL)//因为p一次走两步
	{
		p = p->next->next;
		q = q->next;

		if (p == q)//两指针相遇，即单链表有环
		{
			break;
		}
	}

	if (p != q)//没有环
	{
		return NULL;
	}

	q = list;//第一次相遇后，将慢指针q指向头 再重新走
	while (p != q) //循环退出后，两指针相遇(相等)，此时指针指向的结点就是入环的第一个结点
	{
		p = p->next;
		q = q->next;
	}
	return p;
}
