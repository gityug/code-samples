// https://leetcode.com/problems/count-and-say/
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        
        string s = "11";
        for (int i = 3; i <= n; ++i) {
            string t;
            char prev = s[0];
            int count = 1;
            for (int j = 1; j < s.size(); ++j) {
                if (prev == s[j]) {
                    count++;
                }
                else {
                    t = t + to_string(count) + to_string(prev-'0');
                    count = 1;
                    prev = s[j];
                }
            }
            s = t + to_string(count) + to_string(prev-'0');
        }
        return s;
    }
};
