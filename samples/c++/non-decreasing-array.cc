// https://leetcode.com/problems/non-decreasing-array/description/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt(0);
        int lmax(INT_MIN);
        int rmin(INT_MAX);
        
        for (int i(1); i < nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                cnt++;
                if ((i-2) >= 0)
                    lmax = nums[i-2];
                if (i+1 < nums.size())
                    rmin = nums[i+1];                                                
            }            
            if (cnt > 1 || (nums[i-1] > rmin && nums[i] < lmax)) return false;
        }
        
        return true;
    }
};
