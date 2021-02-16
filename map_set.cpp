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
//size_t bucket_count()const        返回哈希桶中桶的总个数
//size_t bucket_size(size_t n)const 返回n号桶中有效元素的总个数
//size_t bucket(const K& key)       返回元素key所在的桶号

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

	//unordered_multimap<int, string> unmmap; // 可以重复插入
	unmap.insert(_v1);  //不会重复插入
	unmap.insert(v1);
	unmap.insert(v2);
	unmap.insert(v3);
	unmap.insert(v4);
	unmap.insert(v5);

	for (const auto& e : unmap)
	{
		// unordered_map没顺序
		// map会自动排序
		cout << e.first << " : " << e.second << endl;
	}
}
*/
