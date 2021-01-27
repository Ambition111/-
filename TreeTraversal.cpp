/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
/*
 * ����������ĸ��ڵ� root ���������ڵ�ֵ��ǰ�����򡢺��������
*/
/*************************************************************/
//ǰ�� 
int Size(struct TreeNode* t)
{
    if (t == NULL)
        return 0;
    else
        return Size(t->left) + Size(t->right) + 1;
}

void _preorderTraversal(struct TreeNode* t, int* res, int* i)
{
    if (t != NULL)
    {
        res[*i] = t->val;
        (*i)++;
        _preorderTraversal(t->left, res, i);
        _preorderTraversal(t->right, res, i);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int n = Size(root);  //�������Ľڵ����
    int* res = (int*)malloc(sizeof(int) * n);
    if (res == NULL)    return NULL;
    *returnSize = n;
    int i = 0;
    _preorderTraversal(root, res, &i);
    return res;
}

/*************************************************************/
//����
int Size(struct TreeNode* t)
{
    if (t == 0)
        return 0;
    else
        return Size(t->left) + Size(t->right) + 1;
}

void _inorderTraversal(struct TreeNode* t, int* res, int* i)
{
    if (t == NULL)
        return;
    else
    {
        _inorderTraversal(t->left, res, i);
        res[*i] = t->val;
        (*i)++;
        _inorderTraversal(t->right, res, i);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int n = Size(root);
    int* res = (int*)malloc(sizeof(int) * n);
    if (res == NULL)    return NULL;
    *returnSize = n;

    int i = 0;
    _inorderTraversal(root, res, &i);
    return res;
}

/************************************************************/
//����
int Size(struct TreeNode* t)
{
    if (t == NULL)
        return 0;
    else
        return Size(t->left) + Size(t->right) + 1;
}

void _postorderTraversal(struct TreeNode* t, int* res, int* i)
{
    if (t != NULL)
    {
        _postorderTraversal(t->left, res, i);
        _postorderTraversal(t->right, res, i);
        res[*i] = t->val;
        (*i)++;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int size = Size(root);
    int* res = (int*)malloc(sizeof(int) * size);
    *returnSize = size;
    if (res == NULL)   return NULL;

    int i = 0;
    _postorderTraversal(root, res, &i);
    return res;
}
