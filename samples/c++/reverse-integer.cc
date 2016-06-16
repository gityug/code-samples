// https://leetcode.com/problems/reverse-integer/
//
// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x != 0) {
            int mod = x % 10;
            rev = 10 * rev + mod;
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN ) rev = 0;
        return (int) rev;
    }
};

