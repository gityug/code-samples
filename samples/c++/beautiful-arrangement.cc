// https://leetcode.com/problems/beautiful-arrangement/description/
class Solution {
    
    int countArrangementHelper(int n, vector<int>& v) {
        if (n <= 0) return 1;

        int res(0);
        
        for (int i = 1; i <= n; ++i) {
            if (n % v[i] == 0 || v[i] % n == 0) {
                swap(v[n], v[i]);
                res += countArrangementHelper(n-1, v);
                swap(v[n], v[i]);                
            }
        }
        return res;
    }
    
public:
    int countArrangement(int N) {
        int res(0);
        vector<int> v;            
        
        for (int i(0); i <= N; ++i)
            v.push_back(i);
        
        return countArrangementHelper(N, v);                
    }
};
