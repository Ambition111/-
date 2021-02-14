#include <iostream>
#include <vector>
using namespace std;


template<class Type>
class HashNode
{
public:
	HashNode(Type d = Type()) : data(d), link(nullptr)
	{}
	~HashNode()
	{}
public:
	Type data;
	HashNode* link;
};

template<class Type, size_t _N = 13>
class HashTable
{
public:
	HashTable()
	{
		_size = 0;
		memset(_ht, 0, sizeof(HashNode<Type>*)*_N);
	}
	~HashTable()
	{
		clear();
	}
public:
	void Insert(const Type& x)
	{
		int index = Hash(x);  //利用Hash()函数求出的地址
		//头插法
		HashNode<Type>* newNode = _BuyNode(x);
		newNode->link = _ht[index];
		_ht[index] = newNode;
		_size++;
	}
	HashNode<Type>* Find(const Type key)
	{
		int index = Hash(key);
		HashNode<Type>* p = _ht[index];
		while (p != nullptr && p->data != key)
		{
			p = p->link;
		}
		return p;
	}
	void Remove(const Type& key)
	{
		HashNode<Type>* p = Find(key);
		if (p == nullptr)
			return;
		int index = Hash(key);
		HashNode<Type>* prev = _ht[index];
		if (prev == p)
			_ht[index] = p->link;
		else
		{
			while (prev->link != p)
			{
				prev = prev->link;
			}
			prev->link = prev->link->link;
		}
		delete p;
		_size--;
	}
	void clear()
	{
		for (int i = 0; i < _N; ++i)
		{
			HashNode<Type>* p = _ht[i];
			while (p != nullptr)
			{
				_ht[i] = p->link;
				delete p;
				p = _ht[i];
			}
		}
	}
	size_t size() const
	{
		return _size;
	}
public:
	void PrintHash() const
	{
		for (int i = 0; i < _N; ++i)
		{
			cout << i << " : ";
			HashNode<Type>* p = _ht[i];
			while (p != nullptr)
			{
				cout << p->data << "-->";
				p = p->link;
			}
			cout << "NIL" << endl;
		}
	}
protected:
	int Hash(const Type& key)
	{
		return key % _N;  //除留余数法
	}
	HashNode<Type>* _BuyNode(const Type& x)
	{
		HashNode<Type>* newNode = new HashNode<Type>(x);
		return newNode;
	}
private:
	HashNode<Type>* _ht[_N];
	size_t _size;
};

int main()
{
	vector<int> iv = { 1,3,14,27,40 };
	HashTable<int> ht;

	for (auto& e : iv)
	{
		ht.Insert(e);
	}

	//HashNode<int>* res = ht.Find(27);
	ht.PrintHash();
	cout << "---------------------------------" << endl;
	//ht.clear();
	//ht.Remove(40);
	
	ht.PrintHash();
	//cout << "size = " << ht.size() << endl;

	return 0;
}
