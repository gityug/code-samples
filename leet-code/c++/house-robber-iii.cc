// https://leetcode.com/problems/house-robber-iii/
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
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
    int rob(TreeNode* root) {
        vector<int> v = robU(root);
        return v[0];
    }
    
    vector<int> robU(TreeNode* root) {
        vector<int> ret(3, 0);
        
        ret[0] = 0;
        ret[1] = 0;
        ret[2] = 0;
        
        if (!root) return ret;
        
        vector<int> l = robU(root->left);
        vector<int> r = robU(root->right);
        
        ret[0] = max(root->val + l[1] + l[2] + r[1] + r[2], l[0] + r[0]);
        ret[1] = l[0];
        ret[2] = r[0];
        
        return ret;
    }
};
