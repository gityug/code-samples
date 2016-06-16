// https://leetcode.com/problems/add-binary/
//
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//

class Solution {
public:
    string addBinary(string a, string b) {
        
        string retVal;
        
        if (a.empty() && b.empty()) return retVal;
    
        int aSz = a.size();
        int bSz = b.size();
        
        vector<char> retVec;
        
        char sum = 0;
        char carry = 0;

        for (int i = aSz - 1, j = bSz -1; (i >= 0) || (j >= 0); i--, j-- ) {
            
            char ai = i >= 0 ? a[i] - '0' : 0;
            char bi = j >= 0 ? b[j] - '0' : 0;
            
            sum = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) > 1 ? 1 : 0;
            
            retVec.push_back(sum);
        }
        
        if (carry != 0)
            retVec.push_back(carry);
        else {
            while (retVec.size() > 1 && retVec.back() == 0) retVec.pop_back();
        }
            
        for (int i = retVec.size() - 1; i >= 0; --i) {
            retVal += to_string(retVec[i]);
        }
        return retVal;
    }
};
