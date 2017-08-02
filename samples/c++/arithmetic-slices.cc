// https://leetcode.com/problems/arithmetic-slices/description/
class Solution {
public:
    bool isArithmeticSeries(int a, int b, int c) {
        return (b - a == c - b);    
    }
  
    
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> nSlices(A.size(), 0);
       
        if (A.size() < 3) return 0;
        
        int curSeriesLen(0);
        
        if (isArithmeticSeries(A[0], A[1], A[2])) {
            nSlices[2] = 1;        
            curSeriesLen = 3;
        }
        
        for (int i = 3; i < A.size(); ++i) {
            nSlices[i] = nSlices[i-1];
            if (curSeriesLen >= 3) {
                if (isArithmeticSeries(A[i-2], A[i-1], A[i])) {
                    nSlices[i] += curSeriesLen - 1;
                    curSeriesLen++;
                } else {
                    curSeriesLen = 0;
                }
            }
            else if (isArithmeticSeries(A[i-2], A[i-1], A[i])) {
                curSeriesLen = 3;
                nSlices[i]++;
            }                
        }        
        return nSlices[A.size() - 1];
    }
};
