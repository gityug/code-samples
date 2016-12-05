// https://leetcode.com/problems/island-perimeter/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p(0);
        
        int rows(grid.size());
        if (rows < 1) return p;
        
        int cols(grid[0].size());
        if (cols < 1) return p;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    p +=4;
                    if (i-1 >= 0 && grid[i-1][j]) --p;
                    if (i+1 < rows && grid[i+1][j]) --p;
                
                    if (j-1 >= 0 && grid[i][j-1]) --p;
                    if (j+1 < cols && grid[i][j+1]) --p;
                }
            }
        }
        return p;
    }
};
