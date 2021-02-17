#include <iostream>
#include <bitset>
#include <string>
#include <vector>

/*
    ��¡���������ɲ�¡��Burton Howard Bloom����1970������� һ�ֽ����͵ġ��Ƚ�����ĸ��������ݽ�
    �����ص��Ǹ�Ч�ز���Ͳ�ѯ���������������� ��ĳ������һ�������ڻ��߿��ܴ��ڡ��������ö����ϣ��
    ������һ������ӳ�䵽λͼ�ṹ�С����ַ�ʽ��������������ѯЧ�ʣ�Ҳ���Խ�ʡ�������ڴ�ռ䡣
*/
using namespace std;

//�����ַ�����ϣ�㷨
struct StrToInt1 
{
    size_t operator()(const string& s)
    {
        return BKDRHash(s.c_str());
    }
    //��������ֱ�ӵ�����Ч��ģ�����ͣ����Խ��з�װ
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
				  class HashFunc3 = StrToInt3>  //����Ĭ��ֵ
class BloomFilter
{
public:
	BloomFilter() : _size(0)
	{}
public:
    void Insert(const string& key)
    {
        size_t capacity = _bmp.size();  //λͼ��λ��

        //ͨ����ͬ�Ĺ�ϣ�������ַ���ӳ�䵽��ͬ���±�
        //λͼ������index�±��ж�Ӧ��ֵ����Ϊ1������ܴ���(��������)������һ��Ϊ0����һ��������
        size_t index1 = HashFunc1()(key) % capacity; //ͨ����ϣ����1�����str��Ӧ��������
        _bmp.set(index1); //��1
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
        if (_bmp.test(index1) == 0) //Ϊ0�򲻴���
            return false;

        size_t index2 = HashFunc2()(key) % capacity;
        if (_bmp.test(index2) == 0)
            return false;

        size_t index3 = HashFunc3()(key) % capacity;
        if (_bmp.test(index3) == 0)
            return false;

        return true;  //���ܴ���
    }
private:
	bitset<_N * 5> _bmp;  //�ײ���Ҫһ��λͼ
	size_t _size;
};

int main()
{
	string str = "www.baidu.com";
    string str1 = "www.baidu.com.";
	//BloomFilter<string, StrToInt1, StrToInt2, StrToInt3> bf;
    BloomFilter<string> bf;

    bf.Insert(str);  //����str
    cout << bf.Test(str) << endl;   //��ѯstr������1 
    cout << bf.Test(str1) << endl;  //��ѯstr1������0 

	return 0;
}
