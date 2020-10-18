#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


// ��ʼ��
void Init_Stack(PStack ps)
{
	assert(ps != NULL);
	ps->data = (int*)malloc(INIT_SIZE * sizeof(int));
	ps->top = 0;
	ps->stacksize = INIT_SIZE;
}

// ����
static bool IsFull(PStack ps)
{
	return ps->top = ps->stacksize;
}
// ����
static void AppendSpace(PStack ps)
{
	assert(ps->data != NULL);
	ps->data = (int *)realloc(ps->data, (ps->stacksize) * 2 * sizeof(int));
	ps->stacksize *= 2;
}

// ��ջ
bool Push(PStack ps, int val)
{
	if (IsFull(ps))
	{
		AppendSpace(ps);
	}

	ps->data[ps->top++] = val;  // �ȴ�����++
	return true;
}

// ջ�Ƿ�Ϊ��
bool IsEmpty(PStack ps)
{
	return ps->top == 0;
}

// ��ȡջ��Ԫ�ص�ֵ������ɾ��
// rtval: �������
bool GetTop(PStack ps, int *rtval)
{
	if (IsEmpty(ps))
	{
		return false;
	}
	if (rtval != NULL)
	{
		*rtval = ps->data[ps->top - 1];	
		return true;
	}

}

// ��ջ���õ�ջ����ֵ����ɾ��
bool Pop(PStack ps, int* rtval)
{
	if (IsEmpty(ps))
	{
		return false;
	}
	if (rtval != NULL)
	{
		*rtval = ps->data[ps->top - 1];
	}
	--ps->top;
	return true;
}

// �ݻ�
void Destroy(PStack ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->stacksize = 0;
	ps->top = 0;
}

