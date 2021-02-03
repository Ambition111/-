#include <iostream>
using namespace std;


template<class Type>
class BST;


//ʵ��һ�Ŷ���������
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
	//����������г�ʼ��
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
	bool Insert(const Type& x) //�����ṩ�Ľӿ�
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
	void Sort() //��BST��������������������ݽ���������
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
	//Ϊ�˴ﵽ��װ��������籩¶�����ڲ���Ϣ��������ʵ�ֹ��ܵķ���
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
	bool Remove(BSTNode<Type>*& t, const Type& key) //�Ż���
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
				//������������
				p = t->leftChild;
				while (p->rightChild != nullptr)
					p = p->rightChild;
				t->data = p->data;
				Remove(t->leftChild, p->data);
			}
			else
			{
				//������һ����Ů�ڵ�
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
					//ɾ��Ҷ�ӽڵ�
					delete t;
					t = nullptr;
				}
				else if (t->leftChild != nullptr && t->rightChild == nullptr)
				{
					//����������
					p = t;
					t = p->leftChild;
					delete p;
				}
				else if (t->leftChild == nullptr && t->rightChild != nullptr)
				{
					//����������
					p = t;
					t = p->rightChild;
					delete p;
				}
				else
				{
					//������������
					p = t->leftChild;
					while (p->rightChild != nullptr)
					{
						p = p->rightChild; //�ҵ�t��ֱ��ǰ������t���������е����ֵ��Ҳ�����ҵ�ֱ�Ӻ�̣�
					}
					t->data = p->data; //�滻
					Remove(t->leftChild, p->data); //�ݹ�ɾ��
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
			cout << t->data << " ";  //�������
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
	BSTNode<Type>* root; //����
};


//���Դ��� 
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
	//��������������״���������ݵ�˳���кܴ�Ĺ�ϵ��Ӧ�������������γ�(��)�ҵ�֧
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
