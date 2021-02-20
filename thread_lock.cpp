#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

//一个线程对变量number进行加一100次，另外一个减一100次，每次操作加一或者减一之后，
//输出number的结果，要求：number最后的值为0

int number = 0;
mutex g_lock; 
//使用普通的互斥锁时，锁控制不好时，可能会造成死锁，最常见的比如在锁中间代码返回，或者在锁的范围内抛异常。
//因此：C++11采用RAII的方式对锁进行了封装，即lock_guard（守卫锁）和unique_lock（唯一锁）
int ThreadProc1()
{
    for (int i = 0; i < 100; i++)
    {
        //g_lock.lock();
        //lock_guard<mutex> lock(g_lock); //如果线程函数在中间退出，会调动lock对象的析构函数进行解锁。避免了加锁后函数在中间退出而没有进行解锁而产生死锁
        unique_lock<mutex> lock(g_lock);  //lock_guard功能太单一，用户没有办法对该锁进行控制，因此C++11又提供了unique_lock。

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
mutex m;  //定义互斥锁

unsigned long sum = 0;  //需要使用互斥锁
//atomic_long sum = 0;  //原子类型变量。本事具有互斥性
 
// 使用加锁可以解决，缺陷就是只要一个线程在对sum++时，其他线程就会被阻塞，
// 会影响程序运行的效率，而且锁如果控制不好，还容易造成死锁。
// 因此C++11中引入了原子操作。所谓原子操作：即不可被中断的一个或一系列操作，
// C++11引入的原子操作类型，使得线程间数据的同步变得非常高效。


void thread_fun(size_t num)
{
	for (int i = 0; i < num; ++i)
	{
		m.lock();   //加锁
		sum++;
		m.unlock(); //解锁
	}
}

int main()
{
	thread th1(thread_fun, 10000); //用线程函数创建线程，线程函数为函数指针
	thread th2(thread_fun, 10000);

    //th1.detach(); //该函数被调用后，子线程与主线程分离
    //th2.detach();

	th1.join(); //主线程等待子线程结束，也可使用detach
	th2.join();

	cout << sum << endl;

	return 0;
}
*/
