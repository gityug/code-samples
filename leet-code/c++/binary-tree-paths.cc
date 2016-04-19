// https://leetcode.com/problems/binary-tree-paths/
// Given a binary tree, return all root-to-leaf paths.
//
// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

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
    void binaryTreePathsHelper(TreeNode* root, vector<string>& bPaths, string buf) {
        if (!root) return;
        buf = buf.empty() ? to_string(root->val) : buf + "->" + to_string(root->val);
        if (root->left || root->right) {
            binaryTreePathsHelper(root->left, bPaths, buf);
            binaryTreePathsHelper(root->right, bPaths, buf);
        } else {
            bPaths.push_back(buf);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> bPaths;
        string buf;
        binaryTreePathsHelper(root, bPaths, buf);
        return bPaths;
    }
};

