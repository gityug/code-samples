// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i) {            
            if (nums[i]-1 != i)
                while (nums[i] != nums[nums[i]-1])
                    swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> r;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]-1 != i) r.push_back(i+1);
        }
        return r;
    }
};
