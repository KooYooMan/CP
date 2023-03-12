//
// Created by Manh Cao on 30/01/2023.
//

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> currentRow;

        currentRow.push_back(1);
        ans.push_back(currentRow);
        if (numRows == 1) return ans;

        currentRow.push_back(1);
        ans.push_back(currentRow);
        if (numRows == 2) return ans;

        for (int i = 3; i <= numRows; i ++) {
            int temp = currentRow[0];
            currentRow[0] = 1;
            for (int j = 1; j < i - 1; j ++) {
                int sum = temp + currentRow[j];
                temp = currentRow[j];
                currentRow[j] = sum;
            }
            currentRow.push_back(1);
            ans.push_back(currentRow);
        }

        return ans;
    }
};

int main() {
    
    Solution solution = Solution();

    auto ans = solution.generate(3);

    for (vector<int> l: ans) {
        for (int item: l) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}