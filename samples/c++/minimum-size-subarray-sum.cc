// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.
// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0;
        int r = -1;
        int minLen = INT_MAX;
        int sum = 0;
        int sz = nums.size();
        
        while ((r < sz) && (l < sz)) {
            if (sum >= s) {
                int len = r - l + 1;
                minLen = min(minLen, len);
                sum -= nums[l++];
                
            } else {
                r++;
                if (r < sz) sum += nums[r];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
