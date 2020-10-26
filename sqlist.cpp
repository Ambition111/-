#include "sqlist.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


//��C������ ����һ��static�ĺ���ʱ�� �κ���ֻ�ܱ���ǰ�ļ��е�������������
static int AppendSpace(SqList* sq)
{
	ElemType* s = (ElemType*)malloc(sizeof(ElemType) * sq->size * 2);
	if (s == NULL)  return-1;
	//��ԭ���ռ������ȫ�����뵽�µĿռ���
	for (int i = 0; i < sq->size; i++)
	{
		s[i] = sq->data[i];
	}
	//��ԭ���ռ��ͷţ�Ȼ����sq->dataָ���µĿռ�s
	free(s);
	sq->data = s;
	sq->size *= 2;



}

void InitSqlist(SqList* sq)
{
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
	sq->size = INTSIZE;
}

void InsertSqlistPos(SqList* sq, ElemType val, int pos)
{
	if (sq == NULL) exit(0);
	if (pos < 0 || pos > sq->length)
	{
		printf("Insert :: Pos is error\n");
		return;
	}
	if (sq->length == sq->size)
	{
		if (-1 == AppendSpace(sq))
		{
			printf("Insert :: AppendSpace fail\n");
			return;
		}
	}
	int i = sq->length;
	while (i > pos)
	{
		sq->data[i] = sq->data[i - 1];
		i--;
	}
	sq->data[pos] = val;
	sq->length++;
}

//ͷ��
void SqListInsertHead(SqList* sq, ElemType val)
{
	InsertSqlistPos(sq, val, 0);
}
//β��
void SqListInsertTail(SqList* sq, ElemType val)
{
	assert(sq != NULL);
	InsertSqlistPos(sq, val, sq->length);
}

//ɾ��
void FixSqListDeletePos(SqList* sq, int pos)
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

void FixSqListDeleteHead(SqList* sq)	//ͷɾ
{
	FixSqListDeletePos(sq, 0);
}
void FixSqListDeleteTail(SqList* sq)	//βɾ
{
	if (sq == NULL) exit(0);
	//˳����Ѿ��ǿյ���
	if (sq->length == 0) return;
	sq->length--;
}

void FixSqListDeleteVal1(SqList* sq, ElemType val)//���ظ�ֵɾ��O(n*2)
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



void FixSqListDeleteVal22(SqList* sq, ElemType val)//���ظ�ֵɾ��O(n)
{
	if (sq == NULL)  exit(0);
	int count = 0;
	int i = 0;
	while (i + count <= sq->length)
	{
		if (sq->data[i] == val)
			count++;
		else
			i++;
		sq->data[i] = sq->data[i + count];
	}
	sq->length -= count;
}



int FindValLast(SqList* sq, ElemType val)
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
void SqListShow(SqList* sq)
{
	//assert(sq != NULL);
	if (sq == NULL) exit(0);
	for (int i = 0; i < sq->length; i++)
	{
		printf("%d ", sq->data[i]);
	}
	printf("\n");
}

void DestroyFixSqList(SqList* sq)
{
	if (sq == NULL)  exit(0);
	free(sq->data);
	sq->data = NULL;
	sq->length = 0;
}