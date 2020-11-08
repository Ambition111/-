#pragma once

constexpr auto INITSIZE = 5;

typedef char ElemType;

typedef struct stack
{
	ElemType* data;//ջ��ָ��
	int top;//ջ��ָ�� -- �������±�����ʾ
	int size;//ջ�ռ�Ĵ�С
}Stack;


static void AppendSpace(Stack* st)
{
	if (st == NULL)		exit(0);
	ElemType* s = (ElemType*)malloc(sizeof(ElemType) * st->size * 2);
	if (s == NULL)		return;

	//��ԭ��st->data�ռ��е�����ȫ��Ų��s�ռ���
	for (int i = 0; i < st->size; i++)
	{
		s[i] = st->data[i];
	}

	free(st->data);
	st->data = s;
	st->size *= 2;
}



void InitStack(Stack* st)
{
	st->data = (ElemType*)malloc(sizeof(ElemType) * INITSIZE);
	if (st->data == NULL)	exit(0);

	st->top = 0;
	st->size = INITSIZE;
}

void Push(Stack* st, ElemType val)
{
	if (st == NULL)		exit(0);
	//ջ��
	if (st->top == st->size)
	{
		AppendSpace(st);
	}
	st->data[st->top++] = val;
}

int Empty(Stack* st)
{
	if (st == NULL)		exit(0);
	return st->top == 0 ? 1 : 0;
}

int Top(Stack* st, ElemType* result)
{
	if (st == NULL)		exit(0);

	if (Empty(st))
		return 0;
	

	*result = st->data[st->top - 1];
	return 1;
}

void Pop(Stack* st)
{
	if (st == NULL)		exit(0);

	if (Empty(st))
		return;

	st->top--;
}

void DestroyStack(Stack* st)
{
	if (st == NULL)		exit(0);

	free(st->data);
	st->data = NULL;
	st->top = st->size = 0;
}
