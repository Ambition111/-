/*
	输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
	如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
	
	示例 1:
	给定二叉树 [3,9,20,null,null,15,7]
	
	    3
	   / \
	  9  20
	    /  \
	   15   7
	返回 true 。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeDepth(struct TreeNode* t)
{
    if (t == NULL)
        return 0;
    else
    {
        int left_depth = TreeDepth(t->left);
        int right_depth = TreeDepth(t->right);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL)
        return true;
    int left_depth = TreeDepth(root->left);
    int right_depth = TreeDepth(root->right);
    return abs(left_depth - right_depth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
