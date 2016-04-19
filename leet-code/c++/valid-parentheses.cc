// https://leetcode.com/problems/valid-parentheses/
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '}' :
                case ']' :
                case ')' : {
                    if (st.size() <= 0) return false;
                    if (st.back() != s[i]) return false;
                    else st.pop_back();
                    break;
                }
                case '(':
                    st.push_back(')');
                    break;
                case '{':
                    st.push_back('}');
                    break;
                case '[':
                    st.push_back(']');
                    break;
            }
        }
        if (st.size() > 0) return false;
        else return true;
    }
};
