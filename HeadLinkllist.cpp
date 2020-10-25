#pragma once

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

//静态函数，申请结点 
static LinkList* ApplyNode(ElemType val, LinkList* next)
{
	LinkList* s = (LinkList*)malloc(sizeof(LinkList));
	if (s == NULL)   return NULL;
	s->data = val;
	s->next = next;
	return s;
}

//初始化
void InitLinkList(LinkList* list) //list头结点的地址
{
	if (list == NULL) exit(0);
	list->next = NULL;
}

//插入 
void InsertLinkList(LinkList* list, ElemType val, int pos)
{
	if (list == NULL) exit(0);

	if (pos < 0 )
	{
		printf("Pos is error\n");
		return;
	}
	LinkList* p = list;//将p指向头结点
	//1.找到pos位置的前一个结点
	//2.如果pos超过lenght，则p肯定为NULL
	while (pos && p != NULL) //p != NULL防止p指向最后一个结点的后一个空地址
	{
		p = p->next;
		pos--;
	}
	if (p == NULL)
	{
		printf("Pos id Error\n");
		return;
	}
	LinkList* newNode = ApplyNode(val, p->next);
	if (newNode == NULL) return;
	p->next = newNode;
}

//删除
void DeleteLinkList(LinkList* list, int pos)
{
	if (list == NULL) exit(0);

	LinkList* p = list;

	while (pos && p->next != NULL)
	{
		p = p->next;
		pos--;
	}

	if (p->next == NULL) return;

	LinkList* q = p->next;//使用q将要删除的结点记录下来
	p->next = q->next;
	free(q);
}


 
