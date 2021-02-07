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
		: data(d), leftChild(left), rightChild(right), parent(nullptr), color(RED)//每次都是以红色节点插入
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type>* leftChild;
	RBTreeNode<Type>* rightChild;
	RBTreeNode<Type>* parent;   //指向父节点的指针
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
		return size(root) - 1;  //减去结束节点
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
	RBTreeNode<Type>* NIL;   //所有的最后的叶子节点都指向这个真实的空节点
	RBTreeNode<Type>* end_node;  // 结束节点，用于迭代器
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type>*& t, const Type& x)
{
	// 1.按照BST的规则插入节点
	RBTreeNode<Type>* pr = NIL;  //父节点指针
	RBTreeNode<Type>* p = t;
	while (p != NIL)
	{
		if (x == p->data)
			return false;  //不能插入重复值

		pr = p;

		if (x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}

	RBTreeNode<Type>* newNode = _BuyNode(x);

	//链接节点
	if (pr == NIL)  //创建根节点
	{
		t = newNode;     //如果pr为空，就让新节点为根
		t->parent = NIL; //根的父节点为空
	}
	else if (x < pr->data)
		pr->leftChild = newNode;
	else
		pr->rightChild = newNode;
	newNode->parent = pr;

	// 2.平衡调整(颜色)
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
	while (x->parent->color == RED) //红红相连时，就需要调整
	{
		RBTreeNode<Type>* s;   //叔伯节点
		if (x->parent == x->parent->parent->leftChild) //左分支
		{
			s = x->parent->parent->rightChild;  //凡是不存在，都指向NIL(黑色)节点

			//状况三、四
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;

				x = x->parent->parent;  //向上回溯
				continue;
			}
			//状况二
			if (x == x->parent->rightChild)
			{
				x = x->parent;
				LeftRotate(t, x); //通过一次左单旋转变为状况一的情况
			}
			//状况一
			x->parent->color = BLACK;		//更改P
			x->parent->parent->color = RED;	//更改G

			RightRotate(t, x->parent->parent);
		}
		else   //右分支
		{
			s = x->parent->parent->leftChild;

			//状况三、四
			if (s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;

				x = x->parent->parent;
				continue;
			}
			//状况二
			if (x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			//状况一
			x->parent->color = BLACK;		//更改P
			x->parent->parent->color = RED;	//更改G
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






