//
// Created by Manh Cao on 29/01/2023.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        string s1_sort = s1, s2_sort = s2;
        sort(s1_sort.begin(), s1_sort.end());
        sort(s2_sort.begin(), s2_sort.end());
        if (s1_sort != s2_sort) return false;

        int len = s1.size();

        return check(s1, s2, 0, len - 1, 0, len - 1);
    }

    bool check(string& s1, string &s2, int l1, int r1, int l2, int r2) {
        if (r1 < l1) return true;
        if (l1 == r1) {
            return s1[l1] == s2[l2];
        }

        vector<bool> choose(r1 - l1 + 1, false);
        int max_pos = -1;
        for (int i = l1; i <= r1; i ++) {
            char c = s1[i];
            for (int j = l2; j <= r2; j ++) {
                if (s2[j] == c && !choose[j - l2]) {
                    choose[j - l2] = true;
                    max_pos = max(max_pos, j);
                    break;
                }
            }
            if (max_pos - l2 == i - l1) {
                if (i < r1) {
                    if (check(s1, s2, l1, i, l2, max_pos) && check(s1, s2, i+1, r1, max_pos+1, r2)) {
                        return true;
                    }
                }
            }
        }

        for (int i = 0; i <= r1 - l1; i ++) choose[i] = false;

        int min_pos = r2 + 1;
        for (int i = l1; i <= r1; i ++) {
            char c = s1[i];
            for (int j = r2; j >= l2; j --) {
                if (s2[j] == c && !choose[j - l2]) {
                    choose[j - l2] = true;
                    min_pos = min(min_pos, j);
                    break;
                }
            }
            if (r2 - min_pos == i - l1) {
                if (i < r1) {
                    if (check(s1, s2, l1, i, min_pos, r2) && check(s1, s2, i+1, r1, l2, min_pos-1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {

    Solution solution = Solution();

    bool ans = solution.isScramble("eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd");
    cout << ans << endl;

    return 0;
}
