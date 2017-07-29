// https://leetcode.com/problems/hamming-distance/description/

public class Solution {
    public int hammingDistance(int x, int y) {
        int xr = x ^ y;
        int c = 0;
        
        while (xr != 0) {
            c++;
            xr = xr & (xr - 1);
        }
        return c;
    }
}
