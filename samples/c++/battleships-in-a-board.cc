// https://leetcode.com/problems/battleships-in-a-board/description/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res(0);
        int r = board.size();
        if (r <= 0) return 0;
        
        int c = board[0].size();                    
        
        for (int i(0); i < r; ++i) {
            for (int j(0); j < c; ++j) {
                if (board[i][j] == 'X') {
                    res++;
                    if (j > 0) if (board[i][j-1] == 'X') res--;
                    if (i > 0) if (board[i-1][j] == 'X') res--;
                }
            }
        }
        
        return res;
    }
};
