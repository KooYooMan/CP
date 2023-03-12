//
// Created by Manh Cao on 26/01/2023.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n_s = s.size();
        int l = -1, r = n_s - 1;

        vector<int> num(52, 0);
        vector<int> in_t(52, 0);

        for (char c: t) {
            in_t[convertCharToInt(c)] ++;
        }

        int n_distinct_in_t = 0;
        for (int i = 0; i < 52; i ++) {
            if (in_t[i]) n_distinct_in_t ++;
        }

        int current_distinct = 0;

        int p1 = 0, p2 = 0;
        while (p1 < n_s) {
            int c1 = convertCharToInt(s[p1]);
            if (in_t[c1]) {
                num[c1] ++;
                if (num[c1] == in_t[c1]) current_distinct ++;
            }
            if (current_distinct == n_distinct_in_t) {
                while (p2 < n_s) {
                    int c2 = convertCharToInt(s[p2]);
                    if (in_t[c2]) {
                        if (num[c2] == in_t[c2]) break;
                        num[c2] --;
                    }
                    p2 ++;
                }
                if (p1 - p2 < r - l) {
                    l = p2;
                    r = p1;
                }
            }
            p1 ++;
        }
        if (l == -1) {
            return "";
        }
        string ans = "";
        for (int i = l; i <= r; i ++) {
            ans.push_back(s[i]);
        }
        return ans;
    }

    int convertCharToInt(char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    string ans = solution.minWindow("ADOBECODEBANC", "ABC");
    cout << ans << endl;

    ans = solution.minWindow("ab", "a");
    cout << ans << endl;

    return 0;
}