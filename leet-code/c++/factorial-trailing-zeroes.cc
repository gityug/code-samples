// https://leetcode.com/problems/factorial-trailing-zeroes/
//
// Given an integer n, return the number of trailing zeroes in n!.
//
// Note: Your solution should be in logarithmic time complexity.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int retVal = 0;
        while (n) {
            retVal += n/5;
            n /= 5;
        }
        return retVal;
    }
};
