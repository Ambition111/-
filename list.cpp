#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

static List* _ApplyNode(Elemtype val, List* next)
{
	List* s = (List*)malloc(sizeof(List));
	if (s == NULL) return NULL;

	s->data = val;
	s->next = next;
	return s;
}

void InitList(List** list) //此处的head是头指针变量的地址
{
	if (list == NULL) exit(0);

	*list = NULL;
}

void InsertListHead(List** list, Elemtype val)
{
	if (list == NULL) exit(0);

	List* newNode = _ApplyNode(val, *list);
	if (newNode == NULL) exit(0);
	*list = newNode;
}

void InsertList(List** list, Elemtype val, int pos)
{
	if (list == NULL) exit(0);

	if (pos < 0)
	{
		printf("Insert :: Pos is error\n");
		return;
	}

	if (pos == 0)
	{
		InsertListHead(list, val);
	}
	else
	{
		List* p = *list;//定义一个指针p指向头指针list，也就是指向第一个结点
		while (pos > 1 && p != NULL)
		{
			p = p->next;
			pos--;
		}

		if (p == NULL)
		{
			printf("Insert :: Pos is error\n");
		}
		else
		{
			List* newNode = _ApplyNode(val, p->next);
			if (newNode == NULL) exit(0);
			p->next = newNode;
		}
	}
}

void InsertListTail(List** list, Elemtype val)
{
	if (list == NULL) exit(0);

	if (*list == NULL)//当前链表为空链的情况下，尾插实际上就是头插
	{
		InsertListHead(list, val);
		return;
	}

	List* p = *list;
	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = _ApplyNode(val, NULL);
}

void DeleteList(List** list, int pos)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	if (pos < 0)
	{
		printf("Delete :: Pos is error\n");
		return;
	}

	if (pos == 0)
	{
		DeleteListHead(list);
	}
	else
	{
		List* p = *list;
		while (pos > 1 && p->next != NULL)
		{
			p = p->next;
			pos--;
		}

		if (p->next == NULL)
		{
			printf("Delete :: Pos is error\n");
		}
		else
		{
			List* q = p->next;
			p->next = q->next;
			free(q);
		}
	}
}

void DeleteListHead(List** list)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	List* p = *list;
	*list = p->next;

	free(p);
}

void DeleteListTail(List** list)
{
	if (list == NULL) exit(0);

	if (*list == NULL)
	{
		printf("List is Empty\n");
		return;
	}

	//仅剩下一个结点时，调用头删
	if ((*list)->next == NULL)
	{
		DeleteListHead(list);
		return;
	}

	List* p = *list;
	List* q = p->next;
	while (q->next != NULL)
	{
		p = q;
		q = q->next;
	}

	p->next = NULL;
	free(q);
}

void DeleteListValue(List** list, Elemtype val)
{
	if (list == NULL) exit(0);
	if (*list == NULL) return;//空链时

	if ((*list)->data == val) 
	{
		DeleteListHead(list);
		DeleteListValue(list, val);
	}
	else
	{
		List* p = *list;
		List* q = p->next;

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
}

void ShowList(List** list)
{
	if (list == NULL) exit(0);

	List* p = *list;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void DestroyList(List** list)
{
	if (list == NULL) exit(0);

	while (*list != NULL)
	{
		DeleteListHead(list);
	}
}


