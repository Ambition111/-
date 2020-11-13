#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

typedef int ElemType;

//单链表的结构体
typedef struct Node
{
	ElemType data;
	struct Node* next;
}ListNode;

//链式队列的结构体
typedef struct que
{
	ListNode* front;
	ListNode* rear;
}ListQue;





static ListNode* ApplyNode(ElemType val, ListNode* next)
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	if (s == NULL)		return NULL;

	s->data = val;
	s->next = next;

	return s;
}

void InitListQue(ListQue* que)
{
	if (que == NULL)		exit(0);
	que->front = que->rear = NULL;
}

int Empty(ListQue* que)
{
	if (que == NULL)		exit(0);

	return que->rear == NULL ? 1 : 0;
}

void Push(ListQue* que, ElemType val)
{
	if (que == NULL)		exit(0);

	ListNode* newnode = ApplyNode(val, NULL);
	if (newnode == NULL)		return;

	if (Empty(que))	//入队列之前，队列为空
	{
		que->front = que->rear = newnode;
	}
	else//入队列之前，队列非空
	{
		que->rear->next = newnode;
		que->rear = newnode;//新节点为新的队尾
	}
}

void Pop(ListQue* que)
{
	if (que == NULL)		exit(0);
	if (Empty(que))			return;

	if (que->front == que->rear)//队列只有一个节点
	{
		free(que->front);//也可free(que->rear);
		que->front = que->rear = NULL;
	}
	else//队列有两个以上节点
	{
		ListNode* p = que->front;
		que->front = que->front->next;
		free(p);
	}
}

int GetHead(ListQue* que, ElemType* reval)
{
	if (que == NULL)		exit(0);
	if (Empty(que))			return 0;

	return *reval = que->front->data;
	//return 1;
}

void DestroyListQue(ListQue* que)
{
	while (!Empty(que))
	{
		Pop(que);
	}
}
