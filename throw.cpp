#include <iostream>

using namespace std;

int main()
{
	try
	{
		int* ptr = new int[536870910]; //空间申请失败

		delete[] ptr;
	}
	//catch (bad_alloc& e)
	catch (exception& e)  // 所有异常类的基类
	{
		cout << e.what() << endl;
	}
	return 0;
}

/*
// 异常规范：
// 1. 异常规格说明的目的是为了让函数使用者知道该函数可能抛出的异常有哪些。 可以在函数的后面接throw(类型)，列出这个函数可能抛掷的所有异常类型。
// 2. 函数的后面接throw()，表示函数不抛异常。
// 3. 若无异常接口声明，则此函数可以抛掷任何类型的异常。

int Div(int a, int b)// throw(int, char, double)  //异常规范 列出这个函数可能抛出的所有异常类型
{
	if (b == 0)
	{
		throw b;
	}
	return a / b;
}

int main()
{
	int a = 10;
	//int b = 5;
	int b = 0;

	int res = 0;

	try
	{
		res = Div(a, b);
		cout << "res = " << res << endl;
	}
	catch(int &x) // x接收上面抛出的异常变量
	{
		cout << "Error" << endl;
	}

	return 0;
}
*/
