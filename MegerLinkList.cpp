/*
	5.合并两个有序链表，合并后依旧有序
		链表1：1 3 5 7
		链表2：2 4 6 8
		合并后：1 2 3 4 5 6 7 8
*/

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;



void MegerLinkList(LinkList* list1, LinkList* list2)
{
	if (list1 == NULL || list2 == NULL) return;

	LinkList* p = list1->next;
	LinkList* q = list2->next;
	LinkList* tail = list1;  
	list2->next = NULL;  //最后将值都放到list1里了，list2就没用了，则list2->next = NULL
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			tail->next = p;
			p = p->next;
		}
		else
		{
			tail->next = q;
			q = q->next;
		}
		tail = tail->next;//tail永远指向新链表的尾
	}

	if (p != NULL)
		tail->next = p;
	if (q != NULL)
		tail->next = q;
}


