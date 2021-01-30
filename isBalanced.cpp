/*
	����һ�ö������ĸ��ڵ㣬�жϸ����ǲ���ƽ���������
	���ĳ������������ڵ���������������������1����ô������һ��ƽ���������
	
	ʾ�� 1:
	���������� [3,9,20,null,null,15,7]
	
	    3
	   / \
	  9  20
	    /  \
	   15   7
	���� true ��


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
