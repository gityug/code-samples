// https://leetcode.com/problems/shuffle-an-array/description/
class Solution {
public:
    Solution(vector<int> nums) : _nums(nums), _res(nums) {
        srand(time(0));        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        //_res = _nums;
        return _nums;        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        _res = _nums;

        
        for (int i = 0; i < _res.size(); ++i) {
            int id = rand() % _res.size() - i;
            swap(_res[i], _res[i + id]);
        }
        
        return _res;
    }
private:
    vector<int> _nums;
    vector<int> _res;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
