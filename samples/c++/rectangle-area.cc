// https://leetcode.com/problems/rectangle-area/
// Find the total area covered by two rectilinear rectangles in a 2D plane.
//
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int l1 = C - A;
        int w1 = D - B;

        int l2 = G - E;
        int w2 = H - F;
        
        int l3 = min(C, G) - max(A, E);
        int w3 = min(D, H) - max(B, F);
        
        int overlap = l3 * w3;
        
        if ((min(C, G) <= max(A, E)) || (min(D, H) <= max(B, F))) overlap = 0;

        return l1 * w1 + l2 * w2 - overlap;
    }
};
