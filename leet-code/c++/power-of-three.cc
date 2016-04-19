// https://leetcode.com/problems/power-of-three/
//
// Given an integer, write a function to determine if it is a power of three.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log10(n)/log10(3);
        return (x - (int) x) == 0;
    }
};
