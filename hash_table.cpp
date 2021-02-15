#include <iostream>
using namespace std;


/*
	迅雷面试题：现在有一个用来存放整数的Hash表，Hash表的存储单位为桶，每个桶能放3个整数，
	当一个桶中要放的元素超过3个时，则要将新的元素放在溢出桶中，每个溢出桶也能放3个元素，
	多个溢出桶使用链表串起来，此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。代码定义如下：
*/
#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node* next;
}hash_table[P];

/*
	现在假设hash_table已经初始化好了，insert_new_element()函数目的是把一个新的值插入hash_table中，
	元素插入成功时，函数返回0，否则返回-1，完成函数。
*/

void Init_bucket_node()
{
	for (int i = 0; i < P; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			hash_table[i].data[j] = NULL_DATA;
		}
		hash_table->next = nullptr;
	}
}

int Insert_new_element(int new_element)
{
	int index = new_element % P;
	bucket_node* node = &hash_table[index];
	bucket_node* prev_node = nullptr;
	
	while (node != nullptr)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (node->data[i] == NULL_DATA)
			{
				node->data[i] = new_element;
				return 0;
			}
		}

		prev_node = node;
		node = node->next;
	}

	node = (bucket_node*)malloc(sizeof(bucket_node)); //申请溢出桶
	if (node == nullptr)
		return -1;  //申请失败
	for (int i = 0; i < 3; ++i)
		node->data[i] = NULL_DATA; //初始化溢出桶数据域
	node->next = nullptr; //初始化溢出桶指针域

	node->data[0] = new_element; 
	prev_node->next = node;
	return 0;
}

int main()
{
	int array[] = { 15,14,21,87,96,293,35,24,149,19,63,16,103,77,5,153,145,356,51,68,705,453 };
	Init_bucket_node();

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	{
		Insert_new_element(array[i]);
	}

	return 0;
}
