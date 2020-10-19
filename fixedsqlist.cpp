#include "fixedsqlist.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//��Ӧ��ͷ�ļ��ĺ����Ķ��壨ʵ�֣�

void FixedSqlistInit(FixedSqList* sq)
{
	//1. ��sqָ���data����洢Ԫ�صĿռ�
	//2. ��sqָ���lenght����Ϊ0
	assert(sq != NULL);
	if (sq == NULL)
	{
		exit(0); //ֱ�ӽ�������
	}
	sq->data = (ElemType*)malloc(sizeof(ElemType) * INTSIZE);
	if (sq->data == NULL)
	{
		exit(0);
	}
	sq->length = 0;
}

void FixedSqListInsert(FixedSqList* sq, ElemType val, int pos)
{
	if (sq == NULL) exit(0);
	// ����
	if (sq->length == INTSIZE)
	{
		printf("Sqlist is Full\n");
		return;
	}
	//��posֵ�Ϸ��Ե��ж�
	if (pos < 0 || pos > sq->length)
	{
		printf("Insert Pos is error\n");
		return;
	}
	// ��posλ�ü���֮���Ԫ��ͳһ���Ų��һ��λ��
	int i = sq->length;
	while (i > pos)
	{
		sq->data[i] = sq->data[i - 1];
		i--;
	}
	sq->data[pos] = val;
	sq->length++;
	// ��valֵ�洢����pos��Ϊ�±��λ��
}
//ͷ��
void FixedSqListInsertHead(FixedSqList* sq, ElemType val)
{
	FixedSqListInsert(sq, val, 0);
}
//β��
void FixedSqListInsertTail(FixedSqList* sq, ElemType val)
{
	assert(sq != NULL);
	FixedSqListInsert(sq, val, sq->length);
}

//ɾ��
void FixSqListDeletePos(FixedSqList* sq, int pos)
{
	assert(sq != NULL);
	if (sq->length == 0)
	{
		printf("Sqlist is Empty\n");
		return;
	}
	if (pos < 0 || pos >= sq->length)
	{
		printf("Delete Pos is error\n");
		return;
	}
	for (int i = pos; i < sq->length - 1; i++)
	{
		sq->data[i] = sq->data[i + 1];
	}
	sq->length--;
}

void FixSqListDeleteHead(FixedSqList* sq)	//ͷɾ
{
	FixSqListDeletePos(sq, 0);
}
void FixSqListDeleteTail(FixedSqList* sq)	//βɾ
{
	if (sq == NULL) exit(0);
	//˳����Ѿ��ǿյ���
	if (sq->length == 0) return;
	sq->length--;
}

void FixSqListDeleteVal1(FixedSqList* sq, ElemType val)//���ظ�ֵɾ��O(n*2)
{
	if (sq == NULL)  exit(0);
	for (int i = 0; i < sq->length;)
	{
		if (val == sq->data[i])
			FixSqListDeletePos(sq, i);
		else
			i++;
	}
}

void FixSqListDeleteVal2(FixedSqList* sq, ElemType val)//���ظ�ֵɾ��O(n)
{
	if (sq == NULL)  exit(0);
	int count = 0;
	for (int i = 0; i + count < sq->length; )
	{
		if (val == sq->data[i])
			count++;
		else
			i++;
		sq->data[i] = sq->data[i + count];
	}
	sq->length -= count;
}

int FindValLast(FixedSqList* sq, ElemType val)
{
	if (sq == NULL)  exit(0);
	int index = -1;
	for (int i = 0; i < sq->length; i++)
	{
		if (sq->data[i] == val)
		{
			index = i;
		}
	}
	return index;
}
//��ʾ
void FixedSqlistShow(FixedSqList* sq)
{
	//assert(sq != NULL);
	if (sq == NULL) exit(0);
	for (int i = 0; i < sq->length; i++)
	{
		printf("%d ", sq->data[i]);
	}
	printf("\n");
}


















