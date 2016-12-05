// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (c : s) {
            cnt[c - 'a']++;
        }
        for (c : t) {
            cnt[c - 'a']--;
        }
        int i(0);
        while (i < 26) {
            if (cnt[i]) break;
            i++;
        }
        
        return i + 'a';
    }
};
