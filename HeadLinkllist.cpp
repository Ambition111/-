#pragma once

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LinkList;

//��̬������������ 
static LinkList* ApplyNode(ElemType val, LinkList* next)
{
	LinkList* s = (LinkList*)malloc(sizeof(LinkList));
	if (s == NULL)   return NULL;
	s->data = val;
	s->next = next;
	return s;
}

//��ʼ��
void InitLinkList(LinkList* list) //listͷ���ĵ�ַ
{
	if (list == NULL) exit(0);
	list->next = NULL;
}

//���� 
void InsertLinkList(LinkList* list, ElemType val, int pos)
{
	if (list == NULL) exit(0);

	if (pos < 0 )
	{
		printf("Pos is error\n");
		return;
	}
	LinkList* p = list;//��pָ��ͷ���
	//1.�ҵ�posλ�õ�ǰһ�����
	//2.���pos����lenght����p�϶�ΪNULL
	while (pos && p != NULL) //p != NULL��ֹpָ�����һ�����ĺ�һ���յ�ַ
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

//ɾ��
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

	LinkList* q = p->next;//ʹ��q��Ҫɾ���Ľ���¼����
	p->next = q->next;
	free(q);
}


 
