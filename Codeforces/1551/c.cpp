#include <bits/stdc++.h>
using namespace std;

int num[5];

vector<int> Candidate[5];

int main() {
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int nTest; cin >> nTest;

    while (nTest --) {
        int n; cin >> n;
        for (int i = 0; i < n; ++ i) {
            string s; cin >> s;
            
            for (int j = 0; j < 5; ++ j) {
                num[j] = 0;
            }

            for (char c: s) {
                num[c - 'a'] ++;
            }

            for (int j = 0; j < 5; ++ j) {
                Candidate[j].push_back(2*num[j] - (int)s.size());
            }
        }

        int ans = 0;

        for (int i = 0; i < 5; ++ i) {
           sort(Candidate[i].begin(), Candidate[i].end());
           reverse(Candidate[i].begin(), Candidate[i].end());
           
           int sum = 0;
           for (int j = 0; j < (int)Candidate[i].size(); ++ j) {
                sum += Candidate[i][j];
                if (sum <= 0) {
                    ans = max(ans, j);
                    break;
                }
           }
           if (sum > 0) {
               ans = max(ans, (int)Candidate[i].size());
           }
        }
        for (int i = 0; i < 5; ++ i) {
            Candidate[i].clear();
        }

        cout << ans << "\n";
    }

    return 0;
}