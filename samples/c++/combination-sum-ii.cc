// https://leetcode.com/problems/combination-sum-ii/
// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
// A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        combSum(nums, 0, target);
        return res;
    }
private:    
    void combSum(vector<int>& nums, int i, int target) {
        int j = i;
        while (j < nums.size()) {
            if (nums[j] <= target) {
                buf.push_back(nums[j]);

                if (nums[j] == target) res.push_back(buf);
                else combSum(nums, j + 1, target - nums[j]);

                buf.pop_back();
            }
            // ensure unique solutions by skipping starting with duplicates
            int prev = nums[j];
            while (++j < nums.size() && prev == nums[j]);
        }
    }

    vector<vector<int>> res;
    vector<int> buf;
    
};
