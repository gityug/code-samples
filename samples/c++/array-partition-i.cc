// https://leetcode.com/problems/array-partition-i/description/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s(0);
        for (int i = 0; i < nums.size()/2; ++i) {
            s += nums[i*2];
        }
        return s;
    }
};
