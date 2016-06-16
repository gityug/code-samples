// https://leetcode.com/problems/maximum-product-of-word-lengths/
// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
// Example 1:
// Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
// Return 16
// The two words can be "abcw", "xtfn".
//
// Example 2:
// Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
// Return 4
// The two words can be "ab", "cd".
//
// Example 3:
// Given ["a", "aa", "aaa", "aaaa"]
// Return 0
// No such pair of words.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxProd = 0;
        vector<int> vi(words.size(), 0);
        
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            for (int j = 0; j < s.size(); j++) {
                vi[i] |= (1 << (s[j] - 'a')); 
            }
        }
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); j++) {
                if ((vi[i] & vi[j]) == 0) {
                    int prod = words[i].size() * words[j].size();
                    maxProd = max(prod, maxProd);
                }
            }
        }
        return maxProd;
    }
};

