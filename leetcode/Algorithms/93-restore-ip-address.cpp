//
// Created by Manh Cao on 27/01/2023.
//

#include <string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> checkpoint;
        checkpoint.push_back(-1);
        trace(checkpoint, s, ans);
        return ans;
    }

    void trace(vector<int>& checkpoint, string& s, vector<string>& ans) {
        int n_checkpoint = checkpoint.size();
        if (n_checkpoint == 4) {
            if (checkValid(s, checkpoint[n_checkpoint - 1] + 1, int(s.size()) - 1)) {
                checkpoint.push_back(int(s.size()) - 1);
                string result = "";
                for (int i = 1; i <= 4; i ++) {
                    for (int j = checkpoint[i - 1] + 1; j <= checkpoint[i]; j ++) {
                        result.push_back(s[j]);
                    }
                    if (i != 4) {
                        result.push_back('.');
                    }
                }
                ans.push_back(result);
                checkpoint.pop_back();
            }
            return;
        }
        for (int i = checkpoint[n_checkpoint - 1] + 1; i >= 0 && i <= int(s.size()) - (4 - n_checkpoint); i ++) {
            if (!checkValid(s, checkpoint[n_checkpoint - 1] + 1, i)) continue;
            checkpoint.push_back(i);
            trace(checkpoint, s, ans);
            checkpoint.pop_back();
        }
    }

    bool checkValid(string& s, int left, int right) {
        if (left > right) return false;
        if (right - left > 2) return false;
        if (s[left] == '0') {
            if (left == right) return true;
            return false;
        }
        if (right - left < 2) return true;
        if (s[left] == '1') return true;
        if (s[left] > '2') return false;
        if (s[left + 1] < '5') return true;
        if (s[left + 1] > '5') return false;
        if (s[left + 2] <= '5') return true;
        return false;
    }
};

int main() {

    Solution solution = Solution();

    auto ans = solution.restoreIpAddresses("66212274");

    for (string item: ans) cout << item << " ";

    return 0;
}
