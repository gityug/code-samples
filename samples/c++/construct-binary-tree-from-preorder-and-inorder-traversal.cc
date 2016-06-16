// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

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
    unordered_map<int, int> inm;
    
    TreeNode* buildTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pr - pl + 1 <= 0) return 0;
        int val = preorder[pl];
        TreeNode* root = new TreeNode(val);
        
        int iRoot = inm[val];
        int nl =  iRoot - il;
        
        root->left = buildTree(preorder, pl + 1, pl + nl, inorder, il, iRoot - 1);
        root->right = buildTree(preorder, pl + nl + 1, pr, inorder, iRoot + 1, ir);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ni = inorder.size();
        int np = preorder.size();

        if (ni != np || (!np)) return 0;
        
        for (int i = 0; i < ni; ++i) inm[inorder[i]] = i;

        return buildTree(preorder, 0, np-1, inorder, 0, ni-1);
    }
};
