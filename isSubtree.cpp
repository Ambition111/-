/*
	给定两个非空二叉树 s 和 t，检验s 中是否包含和 t 具有相同结构和节点值的子树。
	s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

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
    if (t == NULL)      return true;    //不论s是否为空，t（为空）永远是s的子树
    if (s == NULL)      return false;   //程序能运行到这行，说明t不为空，t不可能是s（为空）的子树

    if (isSameTree(s, t))   return true; //两树相等也视为一个树是另一个树的子树
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
