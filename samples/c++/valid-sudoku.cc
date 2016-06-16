// https://leetcode.com/problems/valid-sudoku/
//
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//

class Solution {
public:

    bool checkGrid(vector<vector<char>>& board, int r , int c) {
        unordered_set<int> us;            
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[3*r+i][3*c+j] != '.') {
                    if (us.find(board[3*r+i][3*c+j]) != us.end()) return false;
                    else us.insert(board[3*r+i][3*c+j]);
                }
            }
        }
        return true;
    }

    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> us;            
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (us.find(board[i][j]) != us.end()) return false;
                    else us.insert(board[i][j]);
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<int> us;            
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (us.find(board[j][i]) != us.end()) return false;
                    else us.insert(board[j][i]);
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!checkGrid(board, i, j)) return false;
            }
        }
        return true;
    }
};
