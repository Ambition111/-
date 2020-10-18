#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"


// 初始化
void Init_Stack(PStack ps)
{
	assert(ps != NULL);
	ps->data = (int*)malloc(INIT_SIZE * sizeof(int));
	ps->top = 0;
	ps->stacksize = INIT_SIZE;
}

// 判满
static bool IsFull(PStack ps)
{
	return ps->top = ps->stacksize;
}
// 扩容
static void AppendSpace(PStack ps)
{
	assert(ps->data != NULL);
	ps->data = (int *)realloc(ps->data, (ps->stacksize) * 2 * sizeof(int));
	ps->stacksize *= 2;
}

// 入栈
bool Push(PStack ps, int val)
{
	if (IsFull(ps))
	{
		AppendSpace(ps);
	}

	ps->data[ps->top++] = val;  // 先处理，再++
	return true;
}

// 栈是否为空
bool IsEmpty(PStack ps)
{
	return ps->top == 0;
}

// 获取栈顶元素的值，但不删除
// rtval: 输出参数
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

// 出栈，得到栈顶的值，并删除
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

// 摧毁
void Destroy(PStack ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->stacksize = 0;
	ps->top = 0;
}

