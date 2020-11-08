#pragma once

constexpr auto INITSIZE = 5;

typedef char ElemType;

typedef struct stack
{
	ElemType* data;//栈底指针
	int top;//栈顶指针 -- 以数组下标来表示
	int size;//栈空间的大小
}Stack;


static void AppendSpace(Stack* st)
{
	if (st == NULL)		exit(0);
	ElemType* s = (ElemType*)malloc(sizeof(ElemType) * st->size * 2);
	if (s == NULL)		return;

	//把原来st->data空间中的数据全部挪到s空间上
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
	//栈满
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
