// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i) {            
            if (i != nums[i]-1)
                while (nums[i] != nums[nums[i]-1])
                    swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> r;
        for (int i = 0; i < nums.size(); ++i) {
            if (i != (nums[i]-1)) r.push_back(i+1);
        }
        return r;
    }
};
