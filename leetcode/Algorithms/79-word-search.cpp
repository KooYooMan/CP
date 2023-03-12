//
// Created by Manh Cao on 26/01/2023.
//
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (trace(i, j, 1, word, board, visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    bool trace(int row, int col, int index, string &word, vector<vector<char> > &board, vector<vector<bool> > &visited) {
        int n_word = word.size();
        if (index >= n_word) {
            return true;
        }
        int m = visited.size();
        int n = visited[0].size();
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for(int i = 0; i < 4; i ++) {
            int new_row = row + dx[i], new_col = col + dy[i];
            if (new_row < 0 || new_row >= m) continue;
            if (new_col < 0 || new_col >= n) continue;
            if (visited[new_row][new_col]) continue;
            if (board[new_row][new_col] != word[index]) continue;
            visited[new_row][new_col] = true;
            if (trace(new_row, new_col, index + 1, word, board, visited)) {
                return true;
            }
            visited[new_row][new_col] = false;
        }
        return false;
    }
};

int main() {

    Solution solution = Solution();

    vector<vector<char> > board(3, vector<char>(4, 'A'));
    board[0][0] = 'A';
    board[0][1] = 'B';
    board[0][2] = 'C';
    board[0][3] = 'E';
    board[1][0] = 'S';
    board[1][1] = 'F';
    board[1][2] = 'C';
    board[1][3] = 'S';
    board[2][0] = 'A';
    board[2][1] = 'D';
    board[2][2] = 'E';
    board[2][3] = 'E';
    bool ans = solution.exist(board, "ABCCED");
    cout << ans << endl;

    return 0;
}
