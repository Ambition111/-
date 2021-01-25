/*
	����һ�ö������ĸ��ڵ㣬���������ȡ�
	�Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
	���磺
	���������� [3,9,20,null,null,15,7]
				3
			   / \
			  9  20
			    /  \
			   15   7
   �������������� 3 ��
*/ 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        else
        {
            int left_h = maxDepth(root->left);
            int right_h = maxDepth(root->right);

            return (left_h > right_h ? left_h : right_h) + 1;
        }
    }
};
