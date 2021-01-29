/*
	���������ǿն����� s �� t������s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������
	s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL)     return true;
    if (p == NULL || q == NULL)     return false;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (t == NULL)      return true;    //����s�Ƿ�Ϊ�գ�t��Ϊ�գ���Զ��s������
    if (s == NULL)      return false;   //���������е����У�˵��t��Ϊ�գ�t��������s��Ϊ�գ�������

    if (isSameTree(s, t))   return true; //�������Ҳ��Ϊһ��������һ����������
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
