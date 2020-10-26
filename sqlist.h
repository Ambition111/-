#pragma once
//宏变量   宏函数
#define INTSIZE 10
//声明结构
typedef int ElemType;
typedef struct
{
	ElemType* data; //用来存储申请的空间的首地址
	int length;        //当前已存储的数据元素的个数
	int size;
}SqList;


void InitSqlist(SqList*);

void InsertSqlistPos(SqList*, ElemType, int);
void SqListInsertHead(SqList*, ElemType);
void SqListInsertTail(SqList*, ElemType);

void FixSqListDeletePos(SqList*, int);
void FixSqListDeleteHead(SqList*);	//头删
void FixSqListDeleteTail(SqList*);	//尾删
void FixSqListDeleteVal1(SqList*, ElemType);//按重复值删除O(n*2)
void FixSqListDeleteVal22(SqList*, ElemType);//按重复值删除O(n)

int FindValLast(SqList*, ElemType);

void SqListShow(SqList*);

void DestroyFixSqList(SqList*);


