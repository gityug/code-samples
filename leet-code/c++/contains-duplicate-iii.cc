// https://leetcode.com/problems/contains-duplicate-iii/
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

class Solution {
public:
    static bool cmp(pair<long, int>& l, pair<long, int>& r) {
        return l.first < r.first;
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long, int>> nps;
        for (int i = 0; i < nums.size(); ++i) nps.push_back(make_pair((long)nums[i], i));
        
        sort(nps.begin(), nps.end(), cmp);
        
        for (int i = 0; i < nps.size(); ++i) {
            for (int j = i + 1; j < nps.size() && abs(nps[i].first - nps[j].first) <= t; ++j) {
                if (abs(nps[i].second - nps[j].second) <= k) return true;
            }
        }
        return false;
    }
};
