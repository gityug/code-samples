// https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> nextMap;
        int sz = nums.size();
                
        for (int i(0); i < sz; ++i) {
            nextMap.insert(make_pair(nums[i], -1));
            for (int j(i+1); j < sz; ++j) {
                if (nums[i] < nums[j]) {
                    nextMap[nums[i]] = nums[j];
                    break;
                }
            }
        }
        
        vector<int> res;
        
        for (auto n : findNums) {
            res.push_back(nextMap[n]);
        }
        return res;
    }
};
