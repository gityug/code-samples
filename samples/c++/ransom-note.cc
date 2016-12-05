// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cR(26, 0);
        vector<int> cM(26, 0);
        
        for (c : ransomNote) cR[c - 'a']++;
        for (c : magazine) cM[c - 'a']++;

        for (int i = 0; i < 26; ++i) if (cM[i] < cR[i]) return false;
        
        return true;
        
    }
};
