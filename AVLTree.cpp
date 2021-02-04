#include <iostream>
#include <stack>

using namespace std;

template<class Type>
class AVLTree;

//AVL node
template<class Type>
class AVLNode
{
	friend AVLTree<Type>;
public:
	AVLNode(Type d = Type(), AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr)
		: data(d), leftChild(left), rightChild(right), bf(0)
	{}

	~AVLNode()
	{}

private:
	Type			data;
	AVLNode<Type>*	leftChild;
	AVLNode<Type>*	rightChild;
	int				bf;  //ƽ������
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
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
	bool Insert(AVLNode<Type>*& t, const Type& x);
	void Rotate_R(AVLNode<Type>*& ptr); //ptrָ��ƽ��Ľڵ�
	void Rotate_L(AVLNode<Type>*& ptr);
	void Rotate_LR(AVLNode<Type>*& ptr);
	void Rotate_RL(AVLNode<Type>*& ptr);
private:
	AVLNode<Type>* root;
};

//1.����ƽ�� 2.����bf
template<class Type>
void AVLTree<Type>::Rotate_R(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subR = ptr; //��ת֮���������
	ptr = subR->leftChild;     //ptrΪ�����¸�
	subR->leftChild = ptr->rightChild; //������ת���subR֮ǰ�Ƚ�ptr���������ӵ�subR��������
	ptr->rightChild = subR;

	ptr->bf = subR->bf = 0;		//����bf
}
template<class Type>
void AVLTree<Type>::Rotate_L(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL = ptr; //��ת֮���������
	ptr = subL->rightChild;
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	ptr->bf = subL->bf = 0;
}
template<class Type>
void AVLTree<Type>::Rotate_LR(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL = ptr->leftChild;
	AVLNode<Type>* subR = ptr;
	ptr = subL->rightChild;

	//������ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	//����subL->bf       //��ͼ������Ƶ�
	if (ptr->bf <= 0)
		subL->bf = 0;
	else
		subL->bf = -1;

	//������ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;

	//����subR->bf
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	ptr->bf = 0;
}
template<class Type>
void AVLTree<Type>::Rotate_RL(AVLNode<Type>*& ptr)
{
	AVLNode<Type>* subL = ptr;
	AVLNode<Type>* subR = ptr->rightChild;;
	ptr = subR->leftChild;

	//������ת
	subR->leftChild = ptr->rightChild;
	ptr->rightChild = subR;

	//����subR->bf
	if (ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;

	//������ת
	subL->rightChild = ptr->leftChild;
	ptr->leftChild = subL;

	//����subL->bf
	if (ptr->bf == 1)
		subL->bf = -1;
	else
		subL->bf = 0;

	ptr->bf = 0;
}

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type>*& t, const Type& x)
{
	// 1.����BST�Ĺ������ڵ�
	AVLNode<Type>* pr = nullptr; //Ҫ����ڵ�ĸ��ڵ�
	AVLNode<Type>* p = t;  //�����һ������ʱtָ���

	stack<AVLNode<Type>*> st;

	while (p != nullptr) //���ڲ���x�Ĳ���λ��
	{
		if (x == p->data) //�������ظ�����
			return false;

		pr = p; //׷��Ҫ����ڵ�ĸ��ڵ�
		st.push(pr);  //���������Ľڵ�

		if (x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);
	if (pr == nullptr)
	{
		t = p;
		return true;
	}

	//�����½��ڵ�
	if (x < pr->data)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	// 2.���������ƽ�⣬��Ҫ����ƽ��
	while (!st.empty())
	{
		pr = st.top();
		st.pop();

		if (p == pr->leftChild) 
			pr->bf--;  //�����pr���������룬pr��bf��1��bf=r_h - l_h��;
		else
			pr->bf++;

		if (pr->bf == 0)
			break;  //�������ڵ��pr->bf==0,������ƽ�⣬����Ҫ�ٻ�����ȥ����bf
		if (pr->bf == 1 || pr->bf == -1) //|bf|=1
			p = pr;	//���ϻ���
		else
		{
			// pr->|bf| == 2 ������ƽ�⣬��Ҫ����ƽ��
			if (p == pr->leftChild) //���֧
			{
				if (p->bf < 0)   /*   / -->  �ҵ���    */
					Rotate_R(pr);
				else			 /*   < -->  �������  */
					Rotate_LR(pr);
			}
			else   //�ҷ�֧
			{  
				if (p->bf > 0)   /*   \ -->  ����    */
					Rotate_L(pr);
				else			 /*   > -->  ���Һ���  */
					Rotate_RL(pr);
			}
			break;
		}
	}

	//��������
	if (st.empty())
		t = pr;
	else
	{
		AVLNode<Type>* ppr = st.top();  //���ڵ�ĸ��ڵ�
		if (ppr->data > pr->data)
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}
	return true;
}


int main()
{
	int ar[] = { 16,3,7,11,9,26,18,14,15 };
	int n = sizeof(ar) / sizeof(ar[0]);

	AVLTree<int> avl;
	for (int i = 0; i < n; ++i)
	{
		avl.Insert(ar[i]);
	}

	return 0;
}
