#pragma once      //防止头文件重复包含

//宏变量   宏函数
#define INTSIZE 10
//声明结构
typedef int ElemType;
typedef struct
{
	ElemType* data; //用来存储申请的空间的首地址
	int length;        //当前已存储的数据元素的个数
}FixedSqList;

//声明函数

//初始化
void FixedSqlistInit(FixedSqList*);

//插入
void FixedSqListInsert(FixedSqList*, ElemType, int);//按位置插
void FixedSqListInsertHead(FixedSqList*, ElemType);//头插
void FixedSqListInsertTail(FixedSqList*, ElemType);//尾插

//删除
void FixSqListDeletePos(FixedSqList*, int);	//按位置删除
void FixSqListDeleteHead(FixedSqList*);	//头删
void FixSqListDeleteTail(FixedSqList*);	//尾删
void FixSqListDeleteVal1(FixedSqList*, ElemType);//按重复值删除O(n*2)
void FixSqListDeleteVal2(FixedSqList*, ElemType);//按重复值删除O(n)

//查找
int FindValLast(FixedSqList*, ElemType);
//显示
void FixedSqlistShow(FixedSqList*);











