#pragma once

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node* prior;
	struct Node* next;
}LoopList;

static LoopList* _ApplyNode(ElemType val, LoopList* prior, LoopList* next)
{
	LoopList* s = (LoopList*)malloc(sizeof(LoopList));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;
	s->prior = prior;

	return s;
}

void InitLoopDList(LoopList* head)
{
	if (head == NULL)	exit(0);

	head->next = head->prior = head;
}

void InsertLoopListPos(LoopList* head, ElemType val, int pos)
{
	if (head == NULL) exit(0);

	if (pos < 0) return;

	LoopList* p = head;
	while (pos)
	{
		p = p->next;
		pos--;
	}

	LoopList* s = _ApplyNode(val, p, p->next);
	p->next->prior = s;
	p->next = s;
}

void InsertLoopListHead(LoopList* head, ElemType val)
{
	InsertLoopListPos(head, val, 0);
}

void InsertLoopListTail(LoopList* head, ElemType val)
{
	if (head == NULL) exit(0);

	LoopList* s = _ApplyNode(val, head->prior, head);

	s->prior = head->prior;
	head->prior->next = s;
}

void DeleteLoopListPos(LoopList* head, int pos)
{
	if (head == NULL)	exit(0);

	if (pos < 0) return;

	LoopList* p = head;
	while (pos)
	{
		p = p->next;
		pos--;
	}

	LoopList* q = p->next;
	p->next = q->next;
	q->next->prior = p;

	free(q);
}

void DeleteLoopListHead(LoopList* head)
{
	DeleteLoopListPos(head, 0);
}

void DeleteLoopListTail(LoopList* head)
{
	if (head == NULL)	exit(0);

	LoopList* p = head->prior;
	LoopList* q = p->prior;
	head->prior = p->prior;
	q->next = head;

	free(p);
}

void ShowLoopList(LoopList* head)
{
	if (head == NULL)	exit(0);

	LoopList* p = head;
	while (p->next != head)
	{
		printf("%d-->", p->next->data);
		p = p->next;
	}
	printf("head\n");
	while (p != head)
	{
		printf("%d-->", p->data);
		p = p->prior;
	}
	printf("head\n");
}

void DestoryLoopList(LoopList* head)
{
	if (head == NULL)	exit(0);

	while (head->next != head)
	{
		DeleteLoopListHead(head);
	}
}
