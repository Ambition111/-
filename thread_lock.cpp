#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

//һ���̶߳Ա���number���м�һ100�Σ�����һ����һ100�Σ�ÿ�β�����һ���߼�һ֮��
//���number�Ľ����Ҫ��number����ֵΪ0

int number = 0;
mutex g_lock; 
//ʹ����ͨ�Ļ�����ʱ�������Ʋ���ʱ�����ܻ��������������ı��������м���뷵�أ����������ķ�Χ�����쳣��
//��ˣ�C++11����RAII�ķ�ʽ���������˷�װ����lock_guard������������unique_lock��Ψһ����
int ThreadProc1()
{
    for (int i = 0; i < 100; i++)
    {
        //g_lock.lock();
        //lock_guard<mutex> lock(g_lock); //����̺߳������м��˳��������lock����������������н����������˼����������м��˳���û�н��н�������������
        unique_lock<mutex> lock(g_lock);  //lock_guard����̫��һ���û�û�а취�Ը������п��ƣ����C++11���ṩ��unique_lock��

        ++number;
        cout << "thread 1 :" << number << endl;

        //g_lock.unlock();

    }
    return 0;
}

int ThreadProc2()
{
    for (int i = 0; i < 100; i++)
    {
        //g_lock.lock();
        //lock_guard<mutex> lock(g_lock);
        unique_lock<mutex> lock(g_lock);

        --number;
        cout << "thread 2 :" << number << endl;

        //g_lock.unlock();
    }
    return 0;
}
int main()
{
    thread t1(ThreadProc1);
    thread t2(ThreadProc2);

    t1.join();
    t2.join();

    cout << "number:" << number << endl;
    
    return 0;
}


/*
mutex m;  //���廥����

unsigned long sum = 0;  //��Ҫʹ�û�����
//atomic_long sum = 0;  //ԭ�����ͱ��������¾��л�����
 
// ʹ�ü������Խ����ȱ�ݾ���ֻҪһ���߳��ڶ�sum++ʱ�������߳̾ͻᱻ������
// ��Ӱ��������е�Ч�ʣ�������������Ʋ��ã����������������
// ���C++11��������ԭ�Ӳ�������νԭ�Ӳ����������ɱ��жϵ�һ����һϵ�в�����
// C++11�����ԭ�Ӳ������ͣ�ʹ���̼߳����ݵ�ͬ����÷ǳ���Ч��


void thread_fun(size_t num)
{
	for (int i = 0; i < num; ++i)
	{
		m.lock();   //����
		sum++;
		m.unlock(); //����
	}
}

int main()
{
	thread th1(thread_fun, 10000); //���̺߳��������̣߳��̺߳���Ϊ����ָ��
	thread th2(thread_fun, 10000);

    //th1.detach(); //�ú��������ú����߳������̷߳���
    //th2.detach();

	th1.join(); //���̵߳ȴ����߳̽�����Ҳ��ʹ��detach
	th2.join();

	cout << sum << endl;

	return 0;
}
*/
