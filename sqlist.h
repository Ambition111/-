#pragma once
//�����   �꺯��
#define INTSIZE 10
//�����ṹ
typedef int ElemType;
typedef struct
{
	ElemType* data; //�����洢����Ŀռ���׵�ַ
	int length;        //��ǰ�Ѵ洢������Ԫ�صĸ���
	int size;
}SqList;


void InitSqlist(SqList*);

void InsertSqlistPos(SqList*, ElemType, int);
void SqListInsertHead(SqList*, ElemType);
void SqListInsertTail(SqList*, ElemType);

void FixSqListDeletePos(SqList*, int);
void FixSqListDeleteHead(SqList*);	//ͷɾ
void FixSqListDeleteTail(SqList*);	//βɾ
void FixSqListDeleteVal1(SqList*, ElemType);//���ظ�ֵɾ��O(n*2)
void FixSqListDeleteVal22(SqList*, ElemType);//���ظ�ֵɾ��O(n)

int FindValLast(SqList*, ElemType);

void SqListShow(SqList*);

void DestroyFixSqList(SqList*);


