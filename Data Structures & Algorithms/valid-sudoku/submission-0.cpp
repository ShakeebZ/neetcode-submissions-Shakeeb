class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;
        std::unordered_map<int, std::unordered_set<char>> boxes;
        // row, column, box
        // 3 maps and each should have no duplicates
        int box = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') continue;
                box = (i / 3)*3 + (j/3);
                if (rows[i].contains(board[i][j])) return false;
                rows[i].insert(board[i][j]);
                if (cols[j].contains(board[i][j])) return false;
                cols[j].insert(board[i][j]);
                if (boxes[box].contains(board[i][j])) return false;
                boxes[box].insert(board[i][j]);
            }
        }
        return true;
    }
};
