#include <iostream>

using namespace std;

typedef enum { RED, BLACK } Color_Type;


template<class Type>
class RBTree;
template<class Type>
class rb_iterator;


template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
	RBTreeNode(Type d = Type(), RBTreeNode<Type>* left = nullptr, RBTreeNode<Type>* right = nullptr)
		: data(d), leftChild(left), rightChild(right), parent(nullptr), color(RED)//ÿ�ζ����Ժ�ɫ�ڵ����
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type>* leftChild;
	RBTreeNode<Type>* rightChild;
	RBTreeNode<Type>* parent;   //ָ�򸸽ڵ��ָ��
	Color_Type		  color;
};

template<class Type>
class rb_iterator
{
	typedef rb_iterator<Type> self;
public:
	rb_iterator(RBTreeNode<Type>* p, RBTreeNode<Type>* nil)
		: node(p), NIL(nil)
	{}
public:
	bool operator!=(const self& it) const
	{
		return node != it.node;
	}
	bool operator==(const self& it) const
	{
		return node == it.node;
	}
	Type& operator*()const
	{
		return node->data;
	}
	self& operator++()
	{
		if (node->rightChild != NIL)
		{
			node = node->rightChild;
			while (node->leftChild != NIL)
				node = node->leftChild;
		}
		else
		{
			RBTreeNode<Type>* p = node->parent;
			while (node == p->rightChild)
			{
				node = p;
				p = p->parent;
			}
			node = p;
		}
		return *this;
	}
private:
	RBTreeNode<Type>* node;
	RBTreeNode<Type>* NIL;
};

template<class Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;
public:
	void set_end_node()
	{
		RBTreeNode<Type>* p = root;
		while (p != NIL && p->rightChild != NIL)
		{
			p = p->rightChild;
		}
		p->rightChild = end_node;
	}
public:
	iterator begin()
	{
		RBTreeNode<Type>* p = root;
		while (p != NIL && p->leftChild != NIL)
		{
			p = p->leftChild;
		}
		return iterator(p, NIL);
	}
	iterator end()
	{
		return iterator(end_node, NIL);
	}
	size_t size() const
	{
		return size(root) - 1;  //��ȥ�����ڵ�
	}
protected:
	size_t size(RBTreeNode<Type>* t) const
	{
		if (t == NIL)
			return 0;
		else
			return size(t->leftChild) + size(t->rightChild) + 1;
	}
public:
	RBTree() : NIL(_BuyNode()), root(NIL), end_node(_BuyNode())
	{
		NIL->leftChild = NIL->rightChild = NIL->parent = nullptr;
		NIL->color = BLACK;

		end_node->leftChild = end_node->rightChild = end_node->parent = NIL;

		root = NIL;
	}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}

protected:
	bool Insert(RBTreeNode<Type>*& t, const Type& x);
	void RightRotate(RBTreeNode<Type>*& t, RBTreeNode<Type>* p);
	void LeftRotate(RBTreeNode<Type>*& t, RBTreeNode<Type>* p);
	void Insert_Fixup(RBTreeNode<Type>*& t, RBTreeNode<Type>* x);
protected:
	RBTreeNode<Type>* _BuyNode(const Type& x = Type())
	{
		RBTreeNode<Type>* s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = s->parent = NIL;
		return s;
	}
private:
	RBTreeNode<Type>* root;
	RBTreeNode<Type>* NIL;   //���е�����Ҷ�ӽڵ㶼ָ�������ʵ�Ŀսڵ�
	RBTreeNode<Type>* end_node;  // �����ڵ㣬���ڵ�����
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type>*& t, const Type& x)
{
	// 1.����BST�Ĺ������ڵ�
	RBTreeNode<Type>* pr = NIL;  //���ڵ�ָ��
	RBTreeNode<Type>* p = t;
	while (p != NIL)
	{
		if (x == p->data)
			return false;  //���ܲ����ظ�ֵ

		pr = p;

		if (x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}

	RBTreeNode<Type>* newNode = _BuyNode(x);

	//���ӽڵ�
	if (pr == NIL)  //�������ڵ�
	{
		t = newNode;     //���prΪ�գ������½ڵ�Ϊ��
		t->parent = NIL; //���ĸ��ڵ�Ϊ��
	}
	else if (x < pr->data)
		pr->leftChild = newNode;
	else
		pr->rightChild = newNode;
	newNode->parent = pr;

	// 2.ƽ�����(��ɫ)
	Insert_Fixup(t, newNode);

	return true;
}

template<class Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type>*& t, RBTreeNode<Type>* p)
{
	RBTreeNode<Type>* q = p->leftChild;
	p->leftChild = q->rightChild;

	if (q->rightChild != NIL)
		q->rightChild->parent = p;
	q->parent = p->parent;

	if (p->parent == NIL)
		t = q;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = q;
	else
		p->parent->rightChild = q;

	q->rightChild = p;
	p->parent = q;
}
template<class Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type>*& t, RBTreeNode<Type>* p)
{
	RBTreeNode<Type>* q = p->rightChild;
	p->rightChild = q->leftChild;
	if (q->leftChild != NIL)
		q->leftChild->parent = p;
	q->parent = p->parent;

	if (p->parent == NIL)
		t = q;
	else if (p == p->parent->leftChild)
		p->parent->leftChild = q;
	else
		p->parent->rightChild = q;

	q->leftChild = p;
	p->parent = q;

}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBTreeNode<Type>*& t, RBTreeNode<Type>* x)
{
	while (x->parent->color == RED) //�������ʱ������Ҫ����
	{
		RBTreeNode<Type>* s;   //�岮�ڵ�
		if (x->parent == x->parent->parent->leftChild) //���֧
		{
			s = x->parent->parent->rightChild;  //���ǲ����ڣ���ָ��NIL(��ɫ)�ڵ�

			//״��������
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;

				x = x->parent->parent;  //���ϻ���
				continue;
			}
			//״����
			if (x == x->parent->rightChild)
			{
				x = x->parent;
				LeftRotate(t, x); //ͨ��һ������ת��Ϊ״��һ�����
			}
			//״��һ
			x->parent->color = BLACK;		//����P
			x->parent->parent->color = RED;	//����G

			RightRotate(t, x->parent->parent);
		}
		else   //�ҷ�֧
		{
			s = x->parent->parent->leftChild;

			//״��������
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;

				x = x->parent->parent;
				continue;
			}
			//״����
			if (x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			//״��һ
			x->parent->color = BLACK;		//����P
			x->parent->parent->color = RED;	//����G
			LeftRotate(t, x->parent->parent);
		}
	}
	t->color = BLACK;
}

int main()
{
	int ar[] = { 10,7,8,15,5,6,11,13,12 };
	int n = sizeof(ar) / sizeof(ar[0]);
	RBTree<int> rb;
	for (int i = 0; i < n; ++i)
	{
		rb.Insert(ar[i]);
	}

	rb.set_end_node();

	auto it = rb.begin();
	while (it != rb.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << "size = " << rb.size();

	return 0;
}






