#include <iostream>

using namespace std;

int main()
{
	try
	{
		int* ptr = new int[536870910]; //�ռ�����ʧ��

		delete[] ptr;
	}
	//catch (bad_alloc& e)
	catch (exception& e)  // �����쳣��Ļ���
	{
		cout << e.what() << endl;
	}
	return 0;
}

/*
// �쳣�淶��
// 1. �쳣���˵����Ŀ����Ϊ���ú���ʹ����֪���ú��������׳����쳣����Щ�� �����ں����ĺ����throw(����)���г�����������������������쳣���͡�
// 2. �����ĺ����throw()����ʾ���������쳣��
// 3. �����쳣�ӿ���������˺������������κ����͵��쳣��

int Div(int a, int b)// throw(int, char, double)  //�쳣�淶 �г�������������׳��������쳣����
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
	catch(int &x) // x���������׳����쳣����
	{
		cout << "Error" << endl;
	}

	return 0;
}
*/
