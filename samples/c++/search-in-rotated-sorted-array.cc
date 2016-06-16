// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// 
// You may assume no duplicate exists in the array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l(0), r(nums.size() - 1);
        int m(l + (r - l) / 2);
        
        while (l <= r) {
            if (target == nums[m]) return m;
            if (target == nums[l]) return l;
            if (target == nums[r]) return r;
            
            // One of subarrays nums[l..m] or nums[m..r] will be completely ascending. Find it.
            if (nums[l] < nums[m]) { // nums[l..m] is completely ascending
                if (target > nums[l] && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else { // nums[m..r] is completely ascending
                if (target > nums[m] && target < nums[r]) l = m + 1;
                else r = m - 1;
            }

            m = l + (r - l) / 2;
        }
        
        return -1;
    }
};
