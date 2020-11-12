#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#pragma once
#define INITSIZE 10

typedef int ElemType;

typedef struct queue
{
	ElemType* data;
	int size;
	int front;
	int rear;
}Queue;

static int Full(Queue* que)
{
	if ((que->rear + 1) % que->size == que->front)
		return 1;

	return 0;
}

static void AppendSpace(Queue* que)
{
	ElemType* s = (ElemType*)malloc(sizeof(ElemType) * que->size * 2);
	if (s == NULL)		return;

	int index = 0;//访问新空间的位置
	int i = que->front;//访问原来空间从front到rear的内容

	for (; index < que->size - 1; ++index)
	{
		s[index] = que->data[i];
		i = (i + 1) % que->size;
	}

	que->front = 0;
	que->rear = que->size;
	que->size *= 2;

	que->data = s;
	free(que->data);
	
}

void InitQueue(Queue* que)
{
	if (que == NULL)		exit(0);

	que->data = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	if (que->data == NULL)		exit(0);

	que->size = INITSIZE;
	que->front = que->rear = 0;
}

void Push(Queue* que, ElemType val)
{
	if (que == NULL)		exit(0);

	if (Full(que))
		AppendSpace(que);

	que->data[que->rear] = val;
	que->rear = (que->rear + 1) % que->size;//类似rear+1, 因为要循环
}

int Empty(Queue* que)
{
	if (que == NULL)		exit(0);
	return que->front == que->rear ? 1 : 0;
}

void Pop(Queue* que)
{
	if (que == NULL)		exit(0);

	if (Empty(que))			return;

	que->front = (que->front + 1) % que->size;
}

int GetHead(Queue* que, ElemType* reval)
{
	if (que == NULL)		exit(0);

	if (Empty(que))			return 0;

	return *reval = que->data[que->front];
	//return 1;
}

void DestroyQueue(Queue* que)
{
	if (que == NULL)		exit(0);

	free(que->data);
	que->data = NULL;
	que->front = que->rear = que->size = 0;
}
