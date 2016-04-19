// https://leetcode.com/problems/generate-parentheses/
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//

class Solution {
public:
    void genP(vector<string>& vs, string buf, int l, int r) {
        if (l == 0 && r == 0)  { vs.push_back(buf); return; }
        if (l > 0)
            genP(vs, buf+"(", l-1, r);
        if (r > l)
            genP(vs, buf+")", l, r-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string buf;
        genP(vs, buf, n, n);
        return vs;
    }
};
