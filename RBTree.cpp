#include <iostream>
//#include <stack>

using namespace std;

typedef enum { RED, BLACK } Color_Type;


template<class Type>
class RBTree;

//�������һͷһ�źڡ���ͬ�첻��
template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
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
class RBTree
{
public:
	RBTree() : NIL(_BuyNode()), root(NIL)
	{
		NIL->leftChild = NIL->rightChild = NIL->parent = nullptr;
		NIL->color = BLACK;
		root = NIL;
	}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type& key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(RBTreeNode<Type>*& t, const Type& x);
	bool Remove(RBTreeNode<Type>*& t, const Type& key);
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
bool RBTree<Type>::Remove(RBTreeNode<Type>*& t, const Type& key)
{
	// 1.����BST�Ĺ���ɾ���ڵ�

	// 2.����ƽ��
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

	return 0;
}


/*
	X���²���ڵ㡢P�����ڵ㡢S���岮�ڵ㡢G���游�ڵ㡢GG�����游�ڵ�
	����������4��״����
	״��1��SΪ����XΪ�����루�γ�һ��ֱ�ߣ����Դ�������ȶ�P��G��һ�ε���ת���ٸ���P��G��ɫ��
	״��2��SΪ����XΪ�ڲ���루�γ�һ�����ߣ����Դ�����������ȶ�P��X��һ�ε���ת������G��X��ɫ���ٽ������G��һ�ε���ת��
	״��3��SΪ����XΪ�����룬�Դ�������ȶ�P��G��һ�ε���ת�����ı�X����ɫ����ʱ���GGΪ�ڣ�һ�и㶨�������GGΪ�죬��״��4
			��Ҳ����ͨ���ı���ɫ��P��S��G���ķ�������״��3����������룬����Ҫע��������ַ����������ĺ������״�᲻һ����
	״��4��SΪ����XΪ�����룬�Դ�������ȶ�P��G��һ�ε���ת�����ı�
*/




