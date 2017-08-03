// https://leetcode.com/problems/teemo-attacking/description/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        
        if (timeSeries.size() <= 0) return 0;
        
        int res = duration;
        
        for (int i = 1; i < timeSeries.size(); ++i) {
            res += duration;
            if (timeSeries[i] - timeSeries[i-1] < duration)
                res -= duration - (timeSeries[i] - timeSeries[i-1]);                
        }
        return res;        
    }
};
