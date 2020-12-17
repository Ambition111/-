#include  <iostream>

using namespace std;

namespace mylist	//��ֹ��ϵͳ��ͻ��ʹ���Լ��������ռ�
{
	template<class T>
	class list;	//ǰ������
	template<class T>
	class ListIterator;

	template<class T>
	class ListNode	//�����ڵ�����
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
	class ListIterator	//����ĵ�������
	{
	public:
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> self;
	public:
		ListIterator(PNode _P) : _Ptr(_P)
		{}
		PNode mynode()		//�õ����������ָ��
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
		typedef ListNode<T>* PNode;		//�������ڵ�����
		typedef ListIterator<T> iterator;
	public:
		list()		//��ͨ���죬����
		{
			CreateHead();
		}
		list(int n, const T& v = T())	//����n����
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
			{
				push_back(v);
			}
		}
		template<class _It>
		list(_It first, _It last)	//����һ������
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}

		}
		list(initializer_list<T> il)	//���ó�ʼ���б�������
		{
			CreateHead();
			for (const auto& e : il)
			{
				push_back(e);
			}
		}
		list(list<T>& l)	//��������һ������
		{
			CreateHead();
			list tmp_list(l.begin(), l.end());
			swap(tmp_list);

			//CreateHead();
			//for (const auto& e : l)	//�����ַ������ܴ�����������ã��� list(list<T>& l)
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
			erase(--end());		// -- ����Ϊend()��ָ�����һ���ڵ���һ���ڵ�
		}
		void pop_front()
		{
			erase(begin());
		}
		void swap(list<T>& l)	//������������
		{
			std::swap(_pHead, l._pHead);	//����������ͷָ��
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
			PNode p = pos.mynode();		//����һ��ָ��ָ�������ָ��Ľڵ�

			s->next = p;
			s->prev = p->prev;
			s->next->prev = s;
			s->prev->next = s;

			return iterator(s);
		}
		void erase(iterator first, iterator last)	//ɾ��һ������Ľڵ�
		{
			while (first != last)
			{
				first = erase(first);	//ע��Ҫ����ɾ������һ���ڵ㣬���������ʧЧ
			}
		}
		iterator erase(iterator pos)	//
		{
			PNode p = pos.mynode();		//��ָ��������Ľڵ㴫��Ҫɾ���Ľڵ�
			PNode q = p->next;	//�ȱ���Ҫɾ���Ľڵ����һ���ڵ㡣
			p->prev->next = p->next;
			p->next->prev = p->prev;

			delete p;

			return iterator(q);		//����Ҫɾ���Ľڵ����һ���ڵ㡣��ֹ������ʧЧ��������ָ��Ľڵ㱻ɾ�����ٷ��ʸýڵ�������ͻ�ʧЧ��
		}
	protected:
		void CreateHead()	//����ͷ���
		{
			_pHead = new ListNode<T>;
			_pHead->next = _pHead->prev = _pHead;	//˫��ѭ������
		}
	private:
		PNode _pHead;
	};
};
