
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

LinkList* FindNodeOfK(LinkList* list, int k)
{
	//双指针，先让一个指针从头开始走k次，然后两个指针同步向后走，直到之前的指针走到空
	
	if (list == NULL || k <= 0) return NULL;//没有倒数第0个

	LinkList* p = list, * q = list;
	while (k && q != NULL)
	{
		q = q->next;
		k--;
	}

	if (q == NULL) return NULL; //避免k大于长度时

	while (q != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}

