#pragma once


typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* prior;
	struct Node* next;
}DList;


static DList* _ApplyNode(ElemType val, DList* prior, DList* next)
{
	DList* s = (DList*)malloc(sizeof(DList));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;
	s->prior = prior;

	return s;
}

void InitDList(DList* head)
{
	if (head == NULL) exit(0);

	head->next = head->prior = NULL;
}

void InsertPos(DList* head, ElemType val, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;

	DList* p = head;
	while (pos && p != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p == NULL) return;

	DList* s = _ApplyNode(val, p, p->next);
	if (s == NULL) return;

	if (p->next != NULL)	p->next->prior = s;
	
	p->next = s;
}

void InsertHead(DList* head, ElemType val)
{
	InsertPos(head, val, 0);
}

void InsertTail(DList* head, ElemType val)
{
	if (head == NULL) exit(0);

	DList* p = head;

	while (p->next != NULL)		p = p->next;

	p->next = _ApplyNode(val, p, NULL);

}

void DeletePos(DList* head, int pos)
{
	if (head == NULL)	exit(0);

	if (pos < 0) return;

	DList* p = head;
	while (pos && p->next != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p->next == NULL)	return;

	DList* q = p->next;
	p->next = q->next;
	if (q->next != NULL)	q->next->prior = p;

	free(q);
}

void DeleteHead(DList* head)
{
	DeletePos(head, 0);
}

void DeleteTail(DList* head)
{
	if (head == NULL) exit(0);

	DList* p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}

	if (p == head)	return;//空链

	p->prior->next = NULL;//p的前一个结点的next域置为空

	free(p);
}

void ShowDList(DList* head)
{
	if (head == NULL) exit(0);

	DList* p = head;
	while (p->next != NULL)//从前往后遍历
	{
		printf("%d-->", p->next->data);
		p = p->next;
	}
	printf("NULL\n");

	while (p != head)//从后往前遍历
	{
		printf("%d-->", p->data);
		p = p->prior;
	}
	printf("NULL\n");
}

void Destory(DList* head)
{
	if (head == NULL)	exit(0);

	while (head->next != NULL)
	{
		DeleteHead(head);
	}
}
