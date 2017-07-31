// https://leetcode.com/problems/reshape-the-matrix/description/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() <= 0) return nums;
        if (nums.size() * nums[0].size() != r * c) return nums;
        
        vector<vector<int>> res;
        
        vector<int> tmp;
        
        for (auto row : nums) {
            for (auto num : row) {
                tmp.push_back(num);
                if (tmp.size() == c) { res.push_back(tmp); tmp.clear(); }
            }
        }
                
        return res;
    }
};
