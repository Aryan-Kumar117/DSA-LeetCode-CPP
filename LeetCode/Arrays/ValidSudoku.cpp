#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> boxes[9];
        for(int row = 0; row < 9; row++){           
            for(int col = 0; col < 9; col++){
                char val = board[row][col];
                if(val == '.') continue;

                int boxIndex = (row / 3) * 3 + (col / 3);

                if(rows[row].count(val)) return false;
                else rows[row].insert(val);

                if(cols[col].count(val)) return false;
                else cols[col].insert(val);

                if(boxes[boxIndex].count(val)) return false;
                else boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};
/*
O(1) time complexity, since the board is always 9x9.
We use unordered sets to track the characters in each row, column, and box.
This ensures that we can check for duplicates efficiently.
*/
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '9', '.', '.', '5', '.', '7', '.'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool result = sol.isValidSudoku(board);
    cout << "Is the Sudoku board valid? " << (result ? "Yes" : "No") << endl;
    return 0;
}