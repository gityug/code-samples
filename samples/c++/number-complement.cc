// https://leetcode.com/problems/number-complement/discuss/
class Solution {
public:
    int findComplement(int num) {
        int mask(0);
        int tmp = num;
        while (tmp) { mask <<= 1; mask |= 0x1; tmp >>= 1; }
        return ~num & mask;        
    }
};
