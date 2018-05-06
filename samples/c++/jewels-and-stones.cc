// https://leetcode.com/problems/jewels-and-stones/description/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> us;
        
        for (auto c : J) us.insert(c);
        
        int ret(0);
        
        for (auto c: S) if (us.count(c) > 0) ++ret;

        return ret;
    }
};
