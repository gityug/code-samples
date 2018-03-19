// https://leetcode.com/problems/4sum-ii/description/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res(0);
        unordered_map<int, int> first;
        unordered_map<int, int> second;
        for (auto a: A) for (auto b: B) first[a+b]++;
        for (auto c: C) for (auto d: D) second[c+d]++;

        for (auto p : first) if (second.count(-p.first) > 0) res += p.second * second[-p.first];
        
        return res;
    }
};
