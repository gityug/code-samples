// https://leetcode.com/problems/single-number-iii/
// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
// For example:
//
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
// Note:
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> r;
        int xr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            xr ^= nums[i];
        }
        int l = xr & ~(xr-1);
        int x(0), y(0);
        for (int n : nums) {
            if (n & l) x ^= n;
            else y ^= n;
        }
        r.push_back(x);
        r.push_back(y);
        return r;
    }
};
