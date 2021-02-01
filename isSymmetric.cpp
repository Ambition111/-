/*
	给定一个二叉树，检查它是否是镜像对称的。
	
	例如，二叉树?[1,2,2,3,4,4,3] 是对称的。
	    1
	   / \
	  2   2
	 / \ / \
	3  4 4  3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool _isSymmetric(struct TreeNode* t1, struct TreeNode* t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    return t1->val == t2->val && _isSymmetric(t1->left, t2->right) && _isSymmetric(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL)   return true;
    return _isSymmetric(root->left, root->right);
}
