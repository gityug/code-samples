// https://leetcode.com/problems/majority-element-ii/
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

// Based on Moore’s Voting Algorithm
// Central idea of the algorithm is if we cancel out each occurrence of an element e with all the other elements
// that are different from e then e will exist till end if it is a majority element.
// Ref: http://www.geeksforgeeks.org/majority-element/ 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> r;
        if (nums.empty()) return r;
        
        int maj1(nums[0]), maj2(nums[0]), c1(0), c2(0);
        
        for (auto i : nums) {
            if (maj1 == i) c1++;
            else if (maj2 == i) c2++;
            else if (c1 == 0) { maj1 = i; c1 = 1; }
            else if (c2 == 0) { maj2 = i; c2 = 1; }
            else { c1--; c2--; }
        }

        c1 = c2 = 0;
        for (auto i : nums) {
            if (i == maj1) c1++;
            else if (i == maj2) c2++; 
        }

        if (c1 > nums.size()/3) r.push_back(maj1);
        if (c2 > nums.size()/3) r.push_back(maj2);
        
        return r;
    }
};
