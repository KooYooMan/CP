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

    int totalNQueens(int n) {
        return trace(0, n);
    }

    int trace(int row, int n) {
        if (row == n) {
            return 1;
        }
        int ans = 0;
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
            ans += trace(row + 1, n);
            Col[col] = false;
            LeftRight[row + col] = false;
            RightLeft[row - col + 10] = false;
        }
        return ans;
    }
};

int main() {
    Solution solution = Solution();

    int ans = solution.totalNQueens(4);
    cout << ans << endl;

    ans = solution.totalNQueens(1);
    cout << ans << endl;

    return 0;
}
