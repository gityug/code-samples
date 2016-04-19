// https://leetcode.com/problems/symmetric-tree/
//
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3

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
    bool isSymmetricHelper(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        
        return (isSymmetricHelper(l->left, r->right) && isSymmetricHelper(l->right, r->left));
        
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return isSymmetricHelper(root->left, root->right);
    }
};
