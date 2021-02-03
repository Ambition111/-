#include <iostream>
using namespace std;


template<class Type>
class BST;


//实现一颗二叉搜索树
template<class Type>
class BSTNode
{
	friend class BST<Type>;
public:
	BSTNode(Type d = Type(), BSTNode<Type>* left = nullptr, BSTNode<Type>* right = nullptr)
		: data(d), leftChild(left), rightChild(right) {}
	~BSTNode()
	{}
private:
	Type data;
	BSTNode<Type>* leftChild;
	BSTNode<Type>* rightChild;
};

template<class Type>
class BST
{
public:
	BST() : root(nullptr)
	{}
	//利用数组进行初始化
	BST(Type ar[], int n) : root(nullptr)
	{
		for (int i = 0; i < n; ++i)
		{
			Insert(ar[i]);
		}
	}
	~BST()
	{
		DestroyTree(root);
		root = nullptr;
	}
public:
	bool Insert(const Type& x) //对外提供的接口
	{
		return Insert(root, x);
	}
	bool Remove(const Type& key)
	{
		return Remove(root, key);
	}
	BSTNode<Type>* Search(const Type& key)
	{
		return Search(root, key);
	}
	void Sort() //对BST树进行中序遍历即对数据进行了排序
	{
		Sort(root);
	}
	Type Min()
	{
		return Min(root);
	}
	Type Max()
	{
		return Max(root);
	}
	void DestroyTree()
	{
		return Destroy(root);
	}
protected:
	//为了达到封装，不向外界暴露树的内部信息，是真正实现功能的方法
	bool Insert(BSTNode<Type>*& t, const Type& x)
	{
		if (t == nullptr)
		{
			t = new BSTNode<Type>(x);
			return true;
		}
		else if (x < t->data)
			Insert(t->leftChild, x);
		else if (x > t->data)
			Insert(t->rightChild, x);
		else
			return false;
	}
	bool Remove(BSTNode<Type>*& t, const Type& key) //优化后
	{
		BSTNode<Type>* p = nullptr;
		if (t != nullptr)
		{
			if (key < t->data)
				Remove(t->leftChild, key);
			else if (key > t->data)
				Remove(t->rightChild, key);
			else if (t->leftChild != nullptr && t->rightChild != nullptr)
			{
				//具有左右子树
				p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
			else
			{
				//最多具有一个子女节点
				p = t;
				if (t->leftChild != nullptr)
					t = p->leftChild;
				else
					t = p->rightChild;
				delete p;

				return true;
			}
		}
		return false;
	}
	/*
	bool Remove(BSTNode<Type>*& t, const Type& key)
	{
		if (t != nullptr)
		{
			if (key < t->data)
				Remove(t->leftChild, key);
			else if (key > t->data)
				Remove(t->rightChild, key);
			else
			{
				BSTNode<Type>* p = nullptr;
				if (t->leftChild == nullptr && t->rightChild == nullptr)
				{
					//删除叶子节点
					delete t;
					t = nullptr;
				}
				else if (t->leftChild != nullptr && t->rightChild == nullptr)
				{
					//具有左子树
					p = t;
					t = p->leftChild;
					delete p;
				}
				else if (t->leftChild == nullptr && t->rightChild != nullptr)
				{
					//具有右子树
					p = t;
					t = p->rightChild;
					delete p;
				}
				else
				{
					//具有左右子树
					p = t->leftChild;
					while (p->rightChild != nullptr)
					{
						p = p->rightChild; //找到t的直接前驱，即t的左子树中的最大值（也可以找到直接后继）
					}
					t->data = p->data; //替换
					Remove(t->leftChild, p->data); //递归删除
				}
				return true;
			}
		}
		return false;
	}
	*/
	BSTNode<Type>* Search(BSTNode<Type>* t, const Type& key)
	{
		if (t == nullptr)
			return nullptr;
		if (t->data == key)
			return t;
		else if (key < t->data)
			return Search(t->leftChild, key);
		else if (key > t->data)
			return Search(t->rightChild, key);
	}
	void Sort(BSTNode<Type>* t)
	{
		if (t != nullptr)
		{
			Sort(t->leftChild);
			cout << t->data << " ";  //中序遍历
			Sort(t->rightChild);
		}
	}
	Type& Min(BSTNode<Type>* t)
	{
		while (t->leftChild != nullptr)
		{
			t = t->leftChild;
		}
		return t->data;
	}
	Type& Max(BSTNode<Type>* t)
	{
		while (t->rightChild != nullptr)
		{
			t = t->rightChild;
		}
		return t->data;
	}
	void DestroyTree(BSTNode<Type>*& t)
	{
		if (t != nullptr)
		{
			DestroyTree(t->leftChild);
			DestroyTree(t->rightChild);
			delete t;
		}
	}
private:
	BSTNode<Type>* root; //树根
};


//测试代码 
int main()
{
	int arr[] = { 53,78,65,17,87,9,81,10,45,23 };
	int n = sizeof(arr) / sizeof(arr[0]);

	BST<int> bst(arr, n);
	bst.Sort();
	cout << endl;

	cout << "Min = " << bst.Min() << endl;
	cout << "Max = " << bst.Max() << endl;

	bst.Remove(53);
	return 0;
}
/*
int main()
{
	//二叉搜索树的形状和输入数据的顺序有很大的关系。应避免有序输入形成(左)右单支
	int arr[] = { 53,78,65,17,87,9,81,45,23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BST<int> bst;

	for (int i = 0; i < n; ++i)
	{
		bst.Insert(arr[i]);
	}

	bst.Sort();

	cout << endl;
	return 0;
}
*/
