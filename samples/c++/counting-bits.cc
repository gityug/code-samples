// https://leetcode.com/problems/counting-bits/
//
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
//
// Follow up:
//
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        int e = 1;
        while (v.size() < num + 1) {
            for (int id = 0; id < e && v.size() < num + 1; id++) {
                v.push_back(1 + v[id]);
            }
            e = e << 1;
        }
        return v;
    }
};

