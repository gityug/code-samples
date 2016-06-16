// https://leetcode.com/problems/largest-number/
// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// 
// Note: The result may be very large, so you need to return a string instead of an integer.

class Solution {
public:
    static bool cmp(string l, string r) {
        return l + r < r + l;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> numStrs;
        
        for (auto n : nums) numStrs.push_back(to_string(n));
        
        sort(numStrs.begin(), numStrs.end(), cmp);
        
        string res;
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            res += numStrs[i];
        }
        
        if (cmp("0", res)) return res;
        else return "0";
    }
};
