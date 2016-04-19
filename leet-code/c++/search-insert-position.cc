// https://leetcode.com/problems/search-insert-position/
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l(0), r(n-1);
        
        while (l < r) {
            int m = l + (r-l) /2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (l >= n) return n;
        else if (r < 0) return 0;
        else if (nums[l] < target) return l + 1;
        else return l;
    }
};
