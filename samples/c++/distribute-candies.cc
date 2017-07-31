// https://leetcode.com/problems/distribute-candies/description/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> u;
        
        for (auto i : candies) u.insert(i);
        
        if (u.size() > candies.size()/2)
            return candies.size()/2;
        else 
            return u.size();        
    }
};
