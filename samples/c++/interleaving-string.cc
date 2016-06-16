// https://leetcode.com/problems/interleaving-string/
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:

    // Backtracking is exponential 
    // DP decision problem -- Compute dp[i][j] based on dp[i-1][j] && dp[i][j-1]. Quadratic in complexity.
    bool isInterleave(string s1, string s2, string s3) {
        int ns1(s1.size()), ns2(s2.size()), ns3(s3.size());
        
        if (ns1 + ns2 != ns3) return false;

        vector<vector<bool>> tab(ns1 + 1, vector<bool>(ns2 + 1, false));
        tab[0][0] = true;
        
        for (int i = 1; i <= ns1; ++i) {
            if (s3[i - 1] == s1[i - 1] && tab[i - 1][0]) tab[i][0] = true;
        }
        
        for (int i = 1; i <= ns2; ++i) {
            if (s3[i - 1] == s2[i - 1] && tab[0][i - 1]) tab[0][i] = true;
        }
        
        for (int i = 1; i <= ns1; ++i) {
            for (int j = 1; j <= ns2; ++j) {
                if ((s3[i + j - 1] == s1[i - 1] && tab[i - 1][j]) || (s3[i + j - 1] == s2[j - 1] && tab[i][j - 1])) tab[i][j] = true;
            }
        }
        
        return tab[ns1][ns2];
    }
};
