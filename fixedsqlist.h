#pragma once      //��ֹͷ�ļ��ظ�����

//�����   �꺯��
#define INTSIZE 10
//�����ṹ
typedef int ElemType;
typedef struct
{
	ElemType* data; //�����洢����Ŀռ���׵�ַ
	int length;        //��ǰ�Ѵ洢������Ԫ�صĸ���
}FixedSqList;

//��������

//��ʼ��
void FixedSqlistInit(FixedSqList*);

//����
void FixedSqListInsert(FixedSqList*, ElemType, int);//��λ�ò�
void FixedSqListInsertHead(FixedSqList*, ElemType);//ͷ��
void FixedSqListInsertTail(FixedSqList*, ElemType);//β��

//ɾ��
void FixSqListDeletePos(FixedSqList*, int);	//��λ��ɾ��
void FixSqListDeleteHead(FixedSqList*);	//ͷɾ
void FixSqListDeleteTail(FixedSqList*);	//βɾ
void FixSqListDeleteVal1(FixedSqList*, ElemType);//���ظ�ֵɾ��O(n*2)
void FixSqListDeleteVal2(FixedSqList*, ElemType);//���ظ�ֵɾ��O(n)

//����
int FindValLast(FixedSqList*, ElemType);
//��ʾ
void FixedSqlistShow(FixedSqList*);











