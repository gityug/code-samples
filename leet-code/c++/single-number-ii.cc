// https://leetcode.com/problems/single-number-ii
//
// Given an array of integers, every element appears three times except for one. Find that single one.
//
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nIntBits = sizeof(int) * 8;
        int n = nums.size();
        
        vector<int> vi(nIntBits, 0);
        
        for (int i : nums) {
            for (int j = 0; j < nIntBits; ++j) {
                if (i & (1 << j)) vi[j]++;
            }
        }
        int ret = 0;
        for (int i = 0; i < nIntBits; ++i) {
            if (vi[i] % 3 != 0) ret |= (1 << i);
        }
        return ret;
    }
};
