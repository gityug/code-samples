// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    void pathSumHelper(TreeNode* root, int sum, vector<int> &b, vector<vector<int>> &res) {
        if (!root) return;

        if (!root->left && !root->right && root->val == sum) {
             b.push_back(root->val);
             res.push_back(b);
             b.pop_back();
        }
        
        b.push_back(root->val);
        pathSumHelper(root->left, sum - root->val, b, res);
        pathSumHelper(root->right, sum - root->val, b, res);
        b.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> buf;
        pathSumHelper(root, sum, buf, res);
        return res;
    }
};
