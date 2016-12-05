// https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        
        for (n : nums1) s.insert(n);
        
        unordered_set<int> u;
        
        for (n : nums2) {
            if (s.count(n) != 0) u.insert(n);
        }
        
        vector<int> r;
        for (n : u) r.push_back(n);
        
        return r;
        
    }
};
