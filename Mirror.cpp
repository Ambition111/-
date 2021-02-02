/*
�����һ������������һ�����������ú���������ľ���

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
class Solution {
public:
    TreeNode* _Mirror(TreeNode* t)
    {
        if (t == nullptr)
            return t;
        else
        {
            TreeNode* lval = _Mirror(t->left);
            TreeNode* rval = _Mirror(t->right);
            t->left = rval;	//������������ָ��
            t->right = lval;
            return t;
        }
    }
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
        else
            _Mirror(pRoot);
    }
};
