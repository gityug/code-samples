// https://leetcode.com/problems/contains-duplicate-ii/
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
//
//

class Solution {
public:
    unordered_map<int, int> um;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) == um.end()) {
                um.insert(pair<int, int>(nums[i], i));
            } else {
                if (i - um.find(nums[i])->second <= k) return true;
                else um.find(nums[i])->second = i;
            }
        }
        return false;
    }
};
