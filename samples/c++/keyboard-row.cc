// https://leetcode.com/problems/keyboard-row/description/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int a[26];
        for (auto c : {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'})
            a[c-'A'] = 0;
        for (auto c : {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'})
            a[c-'A'] = 1;
        for (auto c : {'Z', 'X', 'C', 'V', 'B', 'N', 'M'})
            a[c-'A'] = 2;
        
        vector<string> r;
        
        for (auto w : words) {
            int v = a[toupper(w[0]) - 'A'];
            bool good(true);
            
            for (auto c : w) {
                if (a[toupper(c) - 'A'] != v) { good = false; break; }    
            }
            
            if (good) r.push_back(w);
            
        }
        return r;
    }
};
