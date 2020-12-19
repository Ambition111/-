#include <iostream>
#include <cassert>
using namespace std;


//STL里string的模拟实现
namespace my_string
{
	class string
	{
		typedef char* iterator;		//声明迭代器
		static size_t npos;  //无符号的-1
		friend ostream& operator<<(ostream& out, const string& s);

	public:
		string(const char* str = "")
		{
			if (str == nullptr)		//预防用户用空指针构造对象
			{
				_str = new char[1];
				_str[0] = '\0';
				_capacity = _size = 0;
			}
			else
			{
				_capacity = _size = strlen(str);
				_str = new char[strlen(str) + 1];
				strcpy_s(_str, strlen(str) + 1, str);
			}
		}
		string(const string& s) : _str(nullptr), _capacity(0), _size(0)
		{
			string tmp_str(s._str);
			swap(tmp_str);
		}
		string& operator=(string s)	//不用引用传递，否则会变成交换两个对象
		{
			//而且string s会调用拷贝构造函数构造一个临时对象进行赋值，结束后释放临时对象的空间
			swap(s);
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = _size = 0;
			}
		}
	public:
		iterator begin() const
		{
			return _str;
		}
		iterator end() const
		{
			return _str + _size;
		}
	public:
		void push_back(char ch)
		{
			if (_size >= _capacity)
				reserve(_capacity * 2);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				//char* new_str = new char[_capacity * 2];
				reserve((_size + len) * 2);		
			}
			strcat_s(_str, (_size + len) * 2, str);
			_size += len;
			return *this;
		}
		void append(const char* str)
		{
			*this += str;
		}
		char& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < _size);
			return _str[pos];
		}
		bool operator<(const string& s)
		{
			return (strcmp(_str, s._str) < 0);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator>(const string& s)
		{
			return (strcmp(_str, s._str) > 0);
		}
		bool operator<=(const string& s)
		{
			return !(*this > s);
		}
		bool operator==(const string& s)
		{
			return (strcmp(_str, s._str) == 0);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	public:
		size_t lenght() const
		{
			return _size;
		}
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		bool empty() const
		{
			return _size == 0;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		const char* c_str() const
		{
			return _str;
		}
	public:
		void swap(string &s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
	public:
		//预留空间   针对capacity
		void reserve(size_t n = 0)	
		{
			//n为想要重新调整的大小
			if (n > _capacity)	//只有当要调整的容量大于当前容量时才会调整容量
			{
				char* new_str = new char[n + 1];	//申请新空间
				strcpy_s(new_str, n + 1, _str);		//将原空间的值拷贝到新空间
				delete[] _str;		//释放原来的空间
				_str = new_str;		//将指针指向新空间
				_capacity = n;		//将容量设为新空间的大小
			}
		}
		//调整元素的个数  针对size
		void resize(size_t n, char c = '\0')  //默认用'\0'填充
		{
			if (n > _size)
			{
				if (n > _capacity)
				{
					reserve(n * 2);
				}
				memset(_str + _size, c, n - _size);
			}
			_size = n;
			_str[n] = '\0';
		}
		//查找返回字符在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}
		//查找返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const  //模式匹配 这里用了BF算法
		{
			assert(s != nullptr);
			const char* str = _str + pos;
			while (*str != '\0')
			{
				const char* sub = s;	//子串
				const char* cur = str;	//当前主串的位置
				while (*sub != '\0' && *sub == *cur)
				{
					sub++;
					cur++;
				}
				if (*sub == '\0')
				{
					return str - _str;
				}
				else
					str++;
			}
			return npos;
		}
		//在pos位置插入字符c
		string& insert(size_t pos, char c)
		{
			assert(pos >= 0 && pos <= _size);
			if (_size + 1 >= _capacity)
				reserve(_capacity * 2);
			for (size_t i = _size; i >= pos; --i)
			{
				_str[i + 1] = _str[i];
			}
			_str[pos] = c;
			_size++;
			return *this;
		}
		//在pos位置插入字符串str， 并返回字符串第一个字符的位置
		string& insert(size_t pos, const char* str);
		//删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			if (pos + len >= _size)  //如果删除pos位置后面全部元素
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy_s(_str + len, _size - len, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
	private:
		char* _str;			//字符串空间
		size_t _capacity;	//容量
		size_t _size;		//字符串的有效长度
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str << endl;
		return out;
	}

	size_t string::npos = (size_t)-1;	//静态变量类外定义
}
