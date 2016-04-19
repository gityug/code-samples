// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//

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
    int kthSmallestHelper(TreeNode* r, int& k) {
        int s = 0;
        if (r->left) {
            s = kthSmallestHelper(r->left, k);
        }
        if (k == 0) return s;
        k--;
        if (k == 0) return r->val;
        else if (r->right) return kthSmallestHelper(r->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        return kthSmallestHelper(root, k);
    }
};
