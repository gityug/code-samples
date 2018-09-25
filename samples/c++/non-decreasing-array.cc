class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt(0);
        int lmax(INT_MIN);
        int rmin(INT_MAX);
        
        for (int i(1); i < nums.size(); ++i) {
            if (nums[i-1] > nums[i]) {                
                if ((i-2) >= 0)
                    lmax = nums[i-2];
                if (i+1 < nums.size())
                    rmin = nums[i+1];
                
                if (lmax > rmin || (nums[i-1] > rmin && nums[i] < lmax)) return false;
                
                cnt++;
            }            
            
            if (cnt > 1) return false;
        }
        
        return true;
    }
};
