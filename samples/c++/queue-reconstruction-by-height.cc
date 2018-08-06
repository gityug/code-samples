// https://leetcode.com/problems/queue-reconstruction-by-height/
// Hint: http://massivealgorithms.blogspot.com/2016/09/leetcode-406-queue-reconstruction-by.html
// Elegant idea: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89437/O(n2)-solution-with-O(n)-extra-space
// Hint: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89431/C++-another-O(n2)-approach-sorting-k-instead-of-h
class Solution {
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (a.second < b.second || (a.second == b.second && a.first < b.first));
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), cmp);
        
        list<pair<int, int>> pl;
        for (auto p : people) {
            int count = 0;
            auto itr = pl.begin();
            for (; itr != pl.end(); ++itr) {
                if (itr->first >= p.first) count++;
                if (count > p.second) {
                    break;
                }
            }
            pl.insert(itr, p);
        }
        
        for (auto n : pl) res.push_back(n);
        
        return res;
    }
};
