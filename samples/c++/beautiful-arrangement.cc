// https://leetcode.com/problems/beautiful-arrangement/description/
class Solution {
    int res = 0;
    vector<int> v;    
    
    void countArrangementHelper(int id, int n) {
        if ((n + 1) == id) {
            res++; return;
        }
        
        for (int i = id; i <= n; ++i) {
            if (id % v[i] == 0 || v[i] % id == 0) {
                swap(v[i], v[id]);
                countArrangementHelper(id + 1, n);
                swap(v[i], v[id]);                
            }
        }
    }
    
public:
    int countArrangement(int N) {
        
        v.push_back(0);
        
        for (int i(1); i <= N; ++i)
            v.push_back(i);
        
        countArrangementHelper(1, N);
        
        return res;
    }
};
