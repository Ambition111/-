/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

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
            t->left = rval;	//交换两子树的指向
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
