// https://leetcode.com/problems/combination-sum-iii/

// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.


// Example 1:
//
// Input: k = 3, n = 7
// 
// Output:
//
// [[1,2,4]]

// Example 2:
//
// Input: k = 3, n = 9
//
// Output:
// 
// [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:

    vector<vector<int>> r;
    vector<int> buf;

    void combSum(int k, int n, int i) {
        if ((k == 0) && (n == 0)) { r.push_back(buf); return; }
        for (int j = i; j < 10; ++j) {
            if ((n - j) >= 0 && k > 0) {
                buf.push_back(j);
                combSum(k-1, n-j, j+1);
                buf.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        combSum(k, n, 1);
        return r;
    }
};
