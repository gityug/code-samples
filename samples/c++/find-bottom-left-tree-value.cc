// https://leetcode.com/problems/find-bottom-left-tree-value/description/
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
    void findBottomLeftHelper(TreeNode* root, int d, int& hd, int& res) {
        if (!root) return;
        if (d > hd) { res = root->val; hd = d; }
        findBottomLeftHelper(root->left, d+1, hd, res);
        findBottomLeftHelper(root->right, d+1, hd, res);        
    }
    int findBottomLeftValue(TreeNode* root) {
        int res = root ? root->val : -1;
        int hd(0);        
        findBottomLeftHelper(root, 0, hd, res);
        return res;
    }
};
