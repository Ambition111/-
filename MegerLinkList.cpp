/*
	5.�ϲ��������������ϲ�����������
		����1��1 3 5 7
		����2��2 4 6 8
		�ϲ���1 2 3 4 5 6 7 8
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
	list2->next = NULL;  //���ֵ���ŵ�list1���ˣ�list2��û���ˣ���list2->next = NULL
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
		tail = tail->next;//tail��Զָ���������β
	}

	if (p != NULL)
		tail->next = p;
	if (q != NULL)
		tail->next = q;
}


