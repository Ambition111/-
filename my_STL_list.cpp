#include  <iostream>

using namespace std;

namespace mylist	//防止跟系统冲突，使用自己的命名空间
{
	template<class T>
	class list;	//前向声明
	template<class T>
	class ListIterator;

	template<class T>
	class ListNode	//声明节点类型
	{
		friend class list<T>;
		friend class ListIterator<T>;
	public:
		ListNode(T data = T()) : next(nullptr), prev(nullptr), value(data)
		{}
		~ListNode()
		{}
	private:
		ListNode* next;
		ListNode* prev;
		T         value;
	};

	template<class T>
	class ListIterator	//链表的迭代器类
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> self;
	public:
		ListIterator(PNode _P) : _Ptr(_P)
		{}
		PNode mynode()		//拿到迭代器里的指针
		{
			return _Ptr;
		}
	public:
		T operator*() const
		{
			return _Ptr->value;
		}
		self& operator++()
		{
			_Ptr = _Ptr->next;
			return *this;
		}
		self& operator--()
		{
			_Ptr = _Ptr->prev;
			return *this;
		}
		bool operator!=(const self& lt)
		{
			return _Ptr != lt._Ptr;
		}
		bool operator==(const self& lt)
		{
			return _Ptr == lt._Ptr;
		}

	private:
		PNode _Ptr;
	};

	template<class T>
	class list
	{
	public:
		typedef ListNode<T>* PNode;		//重命名节点类型
		typedef ListIterator<T> iterator;
	public:
		list()		//普通构造，空链
		{
			CreateHead();
		}
		list(int n, const T& v = T())	//构造n个数
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(v);
			}
		}
		template<class _It>
		list(_It first, _It last)	//构造一个区间
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}

		}
		list(initializer_list<T> il)	//利用初始化列表构造链表
		{
			CreateHead();
			for (const auto& e : il)
			{
				push_back(e);
			}
		}
		list(list<T>& l)	//拷贝构造一个链表
		{
			CreateHead();
			list tmp_list(l.begin(), l.end());
			swap(tmp_list);

			//CreateHead();
			//for (const auto& e : l)	//这两种方法不能传常对象的引用，需 list(list<T>& l)
			//{
			//	push_back(e);
			//}
		}
		~list()
		{
			clear();
			delete _pHead;
			_pHead = nullptr;
		}
	public:
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_back()
		{
			erase(--end());		// -- 是因为end()是指向最后一个节点下一个节点
		}
		void pop_front()
		{
			erase(begin());
		}
		void swap(list<T>& l)	//交换两个链表
		{
			std::swap(_pHead, l._pHead);	//即交换两个头指针
		}
		void clear()
		{
			erase(begin(), end());
		}
	public:
		iterator begin()
		{
			return iterator(_pHead->next);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
	public:
		iterator insert(iterator pos, const T & x)
		{
			PNode s = new ListNode<T>(x);
			PNode p = pos.mynode();		//定义一个指针指向迭代器指向的节点

			s->next = p;
			s->prev = p->prev;
			s->next->prev = s;
			s->prev->next = s;

			return iterator(s);
		}
		void erase(iterator first, iterator last)	//删除一个区间的节点
		{
			while (first != last)
			{
				first = erase(first);	//注意要接收删除的下一个节点，否则迭代器失效
			}
		}
		iterator erase(iterator pos)	//
		{
			PNode p = pos.mynode();		//将指向迭代器的节点传给要删除的节点
			PNode q = p->next;	//先保留要删除的节点的下一个节点。
			p->prev->next = p->next;
			p->next->prev = p->prev;

			delete p;

			return iterator(q);		//返回要删除的节点的下一个节点。防止迭代器失效（迭代器指向的节点被删除后再访问该节点迭代器就会失效）
		}
	protected:
		void CreateHead()	//创建头结点
		{
			_pHead = new ListNode<T>;
			_pHead->next = _pHead->prev = _pHead;	//双向循环链表
		}
	private:
		PNode _pHead;
	};
};
