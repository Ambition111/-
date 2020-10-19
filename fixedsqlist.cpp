#include "fixedsqlist.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//对应的头文件的函数的定义（实现）

void FixedSqlistInit(FixedSqList* sq)
{
	//1. 给sq指向的data申请存储元素的空间
	//2. 将sq指向的lenght设置为0
	assert(sq != NULL);
	if (sq == NULL)
	{
		exit(0); //直接结束程序
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
	// 判满
	if (sq->length == INTSIZE)
	{
		printf("Sqlist is Full\n");
		return;
	}
	//对pos值合法性的判断
	if (pos < 0 || pos > sq->length)
	{
		printf("Insert Pos is error\n");
		return;
	}
	// 将pos位置及其之后的元素统一向后挪动一个位置
	int i = sq->length;
	while (i > pos)
	{
		sq->data[i] = sq->data[i - 1];
		i--;
	}
	sq->data[pos] = val;
	sq->length++;
	// 将val值存储到以pos作为下标的位置
}
//头插
void FixedSqListInsertHead(FixedSqList* sq, ElemType val)
{
	FixedSqListInsert(sq, val, 0);
}
//尾插
void FixedSqListInsertTail(FixedSqList* sq, ElemType val)
{
	assert(sq != NULL);
	FixedSqListInsert(sq, val, sq->length);
}

//删除
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

void FixSqListDeleteHead(FixedSqList* sq)	//头删
{
	FixSqListDeletePos(sq, 0);
}
void FixSqListDeleteTail(FixedSqList* sq)	//尾删
{
	if (sq == NULL) exit(0);
	//顺序表已经是空的了
	if (sq->length == 0) return;
	sq->length--;
}

void FixSqListDeleteVal1(FixedSqList* sq, ElemType val)//按重复值删除O(n*2)
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

void FixSqListDeleteVal2(FixedSqList* sq, ElemType val)//按重复值删除O(n)
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
//显示
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


















