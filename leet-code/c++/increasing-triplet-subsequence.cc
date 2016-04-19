// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
// Examples:
// Given [1, 2, 3, 4, 5],
// return true.
//
// Given [5, 4, 3, 2, 1],
// return false.
//
//
// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int min(INT_MAX), mid(INT_MAX);
        
        for (int n : nums) {
            if (n < min) min = n;
            else if (n > mid) return true;
            else if (n < mid && n > min) mid = n;
        }
        return false;
    }
};
