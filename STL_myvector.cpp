#include <iostream>
#include <cassert>

using namespace std;

namespace myvector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{}
		vector(initializer_list <T> il) : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(il.size());
			for (auto& e : il)
			{
				push_back(e);
			}
		}
		vector(vector<T> &v)
		{
			reserve(v.size());
			for (auto& e : v)
			{
				push_back(e);
			}
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(v);	//bug
			return *this;
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
			
		}
	public:
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty() const
		{
			return _start == _finish;
		}
		T& operator[](size_t pos)
		{
			assert(pos >= 0 && pos < size());
			return _start[pos];
		}
	public:
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
	public:
		iterator insert(iterator pos, const T& x)
		{
			if (size() >= capacity())
			{
				//扩容
				size_t offset = pos - _start;
				size_t new_capavity = (capacity()) == 0 ? 1 : capacity() * 2;
				reserve(new_capavity);
				//更新失效的pos迭代器
				pos = _start + offset;

			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			erase(end() - 1);
		}
		iterator erase(iterator pos)
		{
			iterator p = pos;
			while (p < _finish - 1)
			{
				*p = *(p + 1);
				p++;
			}
			_finish--;
			return pos;
		}
	public:
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* new_start = new T[n];
				for (size_t i = 0; i < old_size; ++i)
				{
					new_start[i] = _start[i];
				}
				delete[] _start;
				_start = new_start;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n, const T& x = T())
		{
			if (n == size())	return;
			if (n < size())
			{
				_finish = _start + n;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			iterator it = _finish;
			_finish = _start + n;
			while (it != _finish)
			{
				*it = x;
				++it;
			}
		}
		void swap(vector <T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
	private:
		iterator _start;		//指向数据块的开始
		iterator _finish;		//指向有效数据的尾(最后一个元素的下一个空间)
		iterator _end_of_storage;	//指向存储容量的尾
	};
};

