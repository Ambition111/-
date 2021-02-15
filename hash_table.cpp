#include <iostream>
using namespace std;


/*
	Ѹ�������⣺������һ���������������Hash��Hash��Ĵ洢��λΪͰ��ÿ��Ͱ�ܷ�3��������
	��һ��Ͱ��Ҫ�ŵ�Ԫ�س���3��ʱ����Ҫ���µ�Ԫ�ط������Ͱ�У�ÿ�����ͰҲ�ܷ�3��Ԫ�أ�
	������Ͱʹ��������������Hash��Ļ�Ͱ��ĿΪ����P��Hash���hash������Pȡģ�����붨�����£�
*/
#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node* next;
}hash_table[P];

/*
	���ڼ���hash_table�Ѿ���ʼ�����ˣ�insert_new_element()����Ŀ���ǰ�һ���µ�ֵ����hash_table�У�
	Ԫ�ز���ɹ�ʱ����������0�����򷵻�-1����ɺ�����
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

	node = (bucket_node*)malloc(sizeof(bucket_node)); //�������Ͱ
	if (node == nullptr)
		return -1;  //����ʧ��
	for (int i = 0; i < 3; ++i)
		node->data[i] = NULL_DATA; //��ʼ�����Ͱ������
	node->next = nullptr; //��ʼ�����Ͱָ����

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
