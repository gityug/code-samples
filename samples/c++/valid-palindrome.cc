// https://leetcode.com/problems/valid-palindrome/
//
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
//
// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.
//
// For the purpose of this problem, we define empty string as valid palindrome.
//

class Solution {
public:
    bool isPalindrome(string r) {
        string s;
        for (int i = 0; i < r.size(); i++) {
            if (isalpha(r[i])) s += tolower(r[i]);
            if (isdigit(r[i])) s += r[i];
        }
        
        for (int i = 0; i <= s.size()/2; i++) {
            if (s[i] != s[s.size() -1 -i]) return false;
        }
        return true;
    }
};
