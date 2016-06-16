// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?

// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    long fact(int n) {
        if (n == 0) return 1;
        long r = 1;
        
        for (int i = 2; i <= n; ++i) r *= i;
        
        return r;
    }
    
    long mn(int m, int n) {
        long r = 1;
        
        for (int i = m + 1; i <= n; ++i) r *= i;
        
        return r;
    } 
    
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int r = 1;
        
        if (m > n) {
            r = mn(m, n+m)/fact(n);
        }
        else {
            r = mn(n, n+m)/fact(m);
        }
        
        return r;
    }
};
