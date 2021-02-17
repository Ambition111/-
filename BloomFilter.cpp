#include <iostream>
#include <bitset>
#include <string>
#include <vector>

/*
    布隆过滤器是由布隆（Burton Howard Bloom）在1970年提出的 一种紧凑型的、比较巧妙的概率型数据结
    构，特点是高效地插入和查询，可以用来告诉你 “某样东西一定不存在或者可能存在”，它是用多个哈希函
    数，将一个数据映射到位图结构中。此种方式不仅可以提升查询效率，也可以节省大量的内存空间。
*/
using namespace std;

//三个字符串哈希算法
struct StrToInt1 
{
    size_t operator()(const string& s)
    {
        return BKDRHash(s.c_str());
    }
    //函数不能直接当作有效的模板类型，所以进行封装
    size_t BKDRHash(const char* str)
    {
        register size_t hash = 0;
        while (size_t ch = (size_t)*str++)
        {
            hash = hash * 131 + ch;        
        }
        return hash;
    }
};

struct StrToInt2
{
    size_t operator()(const string& s)
    {
        return SDBMHash(s.c_str());
    }
    size_t SDBMHash(const char* str)
    {
        register size_t hash = 0;
        while (size_t ch = (size_t)*str++)
        {
            hash = 65599 * hash + ch;
            //hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
        }
        return hash;
    }
};

struct StrToInt3
{
    size_t operator()(const string& s)
    {
        return RSHash(s.c_str());
    }
    size_t RSHash(const char* str)
    {
        register size_t hash = 0;
        size_t magic = 63689;
        while (size_t ch = (size_t)*str++)
        {
            hash = hash * magic + ch;
            magic *= 378551;
        }
        return hash;
    }
};
////////////////////////////////////////////////////////////////// 
#define _N 1000

template<class K, class HashFunc1 = StrToInt1,
				  class HashFunc2 = StrToInt2,
				  class HashFunc3 = StrToInt3>  //给出默认值
class BloomFilter
{
public:
	BloomFilter() : _size(0)
	{}
public:
    void Insert(const string& key)
    {
        size_t capacity = _bmp.size();  //位图的位数

        //通过不同的哈希函数将字符串映射到不同的下标
        //位图中三个index下标中对应的值若都为1，则可能存在(存在误判)，若有一个为0，则一定不存在
        size_t index1 = HashFunc1()(key) % capacity; //通过哈希函数1计算出str对应的索引号
        _bmp.set(index1); //置1
        size_t index2 = HashFunc2()(key) % capacity;
        _bmp.set(index2);
        size_t index3 = HashFunc3()(key) % capacity;
        _bmp.set(index3);

        _size++;
    }
    bool Test(const string& key)
    {
        size_t capacity = _bmp.size();
        size_t index1 = HashFunc1()(key) % capacity;
        if (_bmp.test(index1) == 0) //为0则不存在
            return false;

        size_t index2 = HashFunc2()(key) % capacity;
        if (_bmp.test(index2) == 0)
            return false;

        size_t index3 = HashFunc3()(key) % capacity;
        if (_bmp.test(index3) == 0)
            return false;

        return true;  //可能存在
    }
private:
	bitset<_N * 5> _bmp;  //底层需要一个位图
	size_t _size;
};

int main()
{
	string str = "www.baidu.com";
    string str1 = "www.baidu.com.";
	//BloomFilter<string, StrToInt1, StrToInt2, StrToInt3> bf;
    BloomFilter<string> bf;

    bf.Insert(str);  //插入str
    cout << bf.Test(str) << endl;   //查询str，返回1 
    cout << bf.Test(str1) << endl;  //查询str1，返回0 

	return 0;
}
