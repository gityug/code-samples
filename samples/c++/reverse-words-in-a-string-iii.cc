// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
class Solution {
public:
    string reverseWords(string s) {
        char d[s.size() + 1];
        char r[s.size() + 1];
        
        int i(0), j(0);
        
        for (auto c : s) {
            if (c == ' ') {
                for (int k = 0; k < i; ++k) {
                    r[j++] = d[i-k-1];
                }
                r[j++] = ' ';
                i = 0;
            } else {
                d[i++] = c;
            }
        }
        
        if (i != 0) {
                for (int k = 0; k < i; ++k) {
                    r[j++] = d[i-k-1];
                }
                r[j++] = '\0';            
        }
        return string(r); 
    }
};
