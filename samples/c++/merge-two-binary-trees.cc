// https://leetcode.com/problems/merge-two-binary-trees/description/
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        if (!(t1 || t2)) return 0;
        
        TreeNode* root(0);
        TreeNode nullTree(0);
        
        if (!t1) t1 = &nullTree;
        if (!t2) t2 = &nullTree;
        
        root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        
        return root;
    }
};
