// https://leetcode.com/problems/word-pattern/
// Given a pattern and a string str, find if str follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//
//

class Solution {
public:
    bool wordPattern(string pat, string str) {
        vector<char> pv;
        
        for (int i = 0; i < pat.size(); i++) {
            pv.push_back(pat[i]);
        }
        char* s = strdup(str.c_str());
        char* t = strtok(s, " ");
        
        vector<string> sv;
        while (t) {
            sv.push_back(t);
            t = strtok(0, " ");
        }
        
        if (sv.size() != pv.size()) return false;
        
        unordered_map<char, string> umP;
        unordered_map<string, char> umS;
        
        for (int i = 0; i < pv.size(); ++i) {
            if (umP.find(pv[i]) != umP.end()) {
                if (umP[pv[i]] != sv[i]) return false;
            } else {
                umP.insert(pair<char, string>(pv[i], sv[i]));
            }
            
            if (umS.find(sv[i]) != umS.end()) {
                if (umS[sv[i]] != pv[i]) return false;
            } else {
                umS.insert(pair<string, char>(sv[i], pv[i]));
            }
        }
    }
};
