// https://leetcode.com/problems/palindromic-substrings/description/
class Solution {
public:
    bool palindrome(string s) {
        bool res(true);
        
        for (int i(0); i < s.size()/2; ++i) 
            if (s[i] != s[s.size()-i-1]) { res = false; break; }
        
        return res;
    }
    
    int countSubstrings(string s) {
        int sz = s.size();
        int c(0);
        
        for (int i(0); i < sz; ++i) {
            for (int j(i); j < sz; ++j) {
                string sub = s.substr(i, j-i+1);
                if (palindrome(sub)) ++c;
            }
        }
        return c;
    }
};
