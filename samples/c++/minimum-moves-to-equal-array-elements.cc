// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum(0);
        int min(INT_MAX);
        
        for (n : nums) {
            sum += n;
            if (n < min) min = n;
        }
        
        return sum - min * nums.size();
    }
};
