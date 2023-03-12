//
// Created by Manh Cao on 24/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool Col[10];
    bool LeftRight[20];
    bool RightLeft[20];

    vector<vector<string> > solveNQueens(int n) {
        vector<string> current;
        vector<vector<string> > ans;
        trace(0, n, current, ans);
        return ans;
    }

    void trace(int row, int n, vector<string> &current, vector<vector<string> > &ans) {
        if (row == n) {
            ans.push_back(current);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (Col[col] || LeftRight[row + col] || RightLeft[row - col + 10]) {
                continue;
            }
            Col[col] = true;
            LeftRight[row + col] = true;
            RightLeft[row - col + 10] = true;
            string state = "";
            for (int i = 0; i < n; i++) {
                state.push_back((i == col ? 'Q' : '.'));
            }
            current.push_back(state);
            trace(row + 1, n, current, ans);
            current.pop_back();
            Col[col] = false;
            LeftRight[row + col] = false;
            RightLeft[row - col + 10] = false;
        }
    }
};

int main() {
    Solution solution = Solution();

    auto ans = solution.solveNQueens(4);

    for (auto x: ans) {
        for (string y: x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
