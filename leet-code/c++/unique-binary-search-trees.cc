// https://leetcode.com/problems/unique-binary-search-trees/
// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

class Solution {
public:
    int numTrees(int l, int r, vector<int>& m) {
        if (l > r) return 0;
        if (l == r) return 1;
        if (m[r-l] != 0) return m[r - l];
        int c = 0;
        for (int i = l; i <= r; ++i) {
            int ln = numTrees(l, i-1, m);
            int rn = numTrees(i+1, r, m);
            int p = 1;
            if (ln > 0) p *= ln;
            if (rn > 0) p *= rn;
            c += p;
        }
        m[r-l] = c;
        return c;
    }
    int numTrees(int n) {
        vector<int> m(n, 0);
        return numTrees(1, n, m);
    }
};

