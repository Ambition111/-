#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>  
using namespace std;


int main()
{
	unordered_set<int> unset;

	for (int i = 1; i < 100; i += 3)
	{
		unset.insert(i);
	}
	for (const auto& e : unset)
	{
		cout << e << " ";
	}	

	return 0;
}

/*
//size_t bucket_count()const        ���ع�ϣͰ��Ͱ���ܸ���
//size_t bucket_size(size_t n)const ����n��Ͱ����ЧԪ�ص��ܸ���
//size_t bucket(const K& key)       ����Ԫ��key���ڵ�Ͱ��

int main()
{
	pair<int, string> v1 = { 1, "stu1" };
	pair<int, string> v2 = { 5, "stu5" };
	pair<int, string> v3 = { 3, "stu3" };
	pair<int, string> v4 = { 4, "stu4" };
	pair<int, string> v5 = { 53, "stu53" };

	unordered_map<int, string> unmap;

	cout << "bucket count = " << unmap.bucket_count() << endl;


	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);
	for (int i = 0; i < unmap.bucket_count(); ++i)
	{
		cout << unmap.bucket_size(i) << endl;
	}

	cout << "index:" << unmap.bucket(53) << endl;

	return 0;
}
/*
int main()
{
	pair<int, string> v1 = { 1, "stu1" };
	pair<int, string> v2 = { 5, "stu5" };
	pair<int, string> v3 = { 3, "stu3" };
	pair<int, string> v4 = { 4, "stu4" };
	pair<int, string> v5 = { 53, "stu53" };
	pair<int, string> _v1 = { 1, "stu1" };
	unordered_map<int, string> unmap;

	//unordered_multimap<int, string> unmmap; // �����ظ�����
	unmap.insert(_v1);  //�����ظ�����
	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);

	for (const auto& e : unmap)
	{
		// unordered_mapû˳��
		// map���Զ�����
		cout << e.first << " : " << e.second << endl;
	}
}
*/
