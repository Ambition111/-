#include <iostream>
#include <cassert>
using namespace std;


//STL��string��ģ��ʵ��
namespace my_string
{
	class string
	{
		typedef char* iterator;		//����������
		static size_t npos;  //�޷��ŵ�-1
		friend ostream& operator<<(ostream& out, const string& s);

	public:
		string(const char* str = "")
		{
			if (str == nullptr)		//Ԥ���û��ÿ�ָ�빹�����
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
		string& operator=(string s)	//�������ô��ݣ�������ɽ�����������
		{
			//����string s����ÿ������캯������һ����ʱ������и�ֵ���������ͷ���ʱ����Ŀռ�
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
		//Ԥ���ռ�   ���capacity
		void reserve(size_t n = 0)	
		{
			//nΪ��Ҫ���µ����Ĵ�С
			if (n > _capacity)	//ֻ�е�Ҫ�������������ڵ�ǰ����ʱ�Ż��������
			{
				char* new_str = new char[n + 1];	//�����¿ռ�
				strcpy_s(new_str, n + 1, _str);		//��ԭ�ռ��ֵ�������¿ռ�
				delete[] _str;		//�ͷ�ԭ���Ŀռ�
				_str = new_str;		//��ָ��ָ���¿ռ�
				_capacity = n;		//��������Ϊ�¿ռ�Ĵ�С
			}
		}
		//����Ԫ�صĸ���  ���size
		void resize(size_t n, char c = '\0')  //Ĭ����'\0'���
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
		//���ҷ����ַ���string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = 0; i < _size; ++i)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}
		//���ҷ����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const  //ģʽƥ�� ��������BF�㷨
		{
			assert(s != nullptr);
			const char* str = _str + pos;
			while (*str != '\0')
			{
				const char* sub = s;	//�Ӵ�
				const char* cur = str;	//��ǰ������λ��
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
		//��posλ�ò����ַ�c
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
		//��posλ�ò����ַ���str�� �������ַ�����һ���ַ���λ��
		string& insert(size_t pos, const char* str);
		//ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len)
		{
			if (pos + len >= _size)  //���ɾ��posλ�ú���ȫ��Ԫ��
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
		char* _str;			//�ַ����ռ�
		size_t _capacity;	//����
		size_t _size;		//�ַ�������Ч����
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		out << s._str << endl;
		return out;
	}

	size_t string::npos = (size_t)-1;	//��̬�������ⶨ��
}
