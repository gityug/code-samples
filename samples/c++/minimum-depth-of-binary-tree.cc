// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepthHelp(TreeNode* r, int md) {
        if (!r->left && !r->right) return md;
        
        if (!r->left) return minDepthHelp(r->right, md + 1);
        else if (!r->right) return minDepthHelp(r->left, md + 1);
        else 
        return min(minDepthHelp(r->left, md+1), minDepthHelp(r->right, md+1));
    }
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return minDepthHelp(root, 1);
    }
};

