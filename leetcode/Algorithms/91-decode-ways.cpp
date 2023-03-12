//
// Created by Manh Cao on 27/01/2023.
//

#include<iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n_2 = 1, n_1 = (s[0] != '0');
        for (int i = 1, n_s = s.size(); i < n_s; i ++) {
            char a = s[i - 1], b = s[i];
            int n = 0;
            bool ok = false;
            if (a == '1') ok = true;
            if (a == '2' && b >= '0' && b <= '6') ok = true;
            if (b != '0') n += n_1;
            if (ok) n += n_2;
            n_2 = n_1;
            n_1 = n;
        }
        return n_1;
    }
};

int main() {

    Solution solution = Solution();

    int ans = solution.numDecodings("06");
    cout << ans << endl;

    return 0;
}
