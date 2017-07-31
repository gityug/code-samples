// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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

private:
    vector<pair<double, double>> avg;
    void avgLevels(TreeNode* root, int l) {
        if (!root) return;
        
        if (avg.size() <= l) {
            avg.push_back(make_pair<double, double>(root->val, 1.0));
        } else {
            avg[l].first += root->val;
            avg[l].second++;
        }
        avgLevels(root->left, l+1);
        avgLevels(root->right, l+1);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
                
        avgLevels(root, 0);
        
        vector<double> res;
        
        for (auto p : avg) {
            res.push_back(p.first/p.second);
        }
        return res;
    }
};
