// https://leetcode.com/problems/pascals-triangle/
//

// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
// Return
//

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows < 1) return v;
        vector<int> one;
        one.push_back(1);
        v.push_back(one);
        for (int i = 2; i <= numRows; i++) {
            vector<int> r;
            r.push_back(1);
            for (int j = 0; j < i - 2; ++j) {
                r.push_back(v.back()[j] + v.back()[j + 1]);
            }
            r.push_back(1);
            v.push_back(r);
        }
        return v;
    }
};

