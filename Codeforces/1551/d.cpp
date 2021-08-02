#include <bits/stdc++.h>
using namespace std;

char result[110][110];

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int nTest; cin >> nTest;

    while (nTest --) {
        int m, n, k; cin >> m >> n >> k;

        // TODO: Check special value such as 1
        // check valid 
        int remain = k;
        if (m % 2) {
            remain -= n / 2;
        }
        if (remain < 0 || remain % 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        if (m % 2) {
            for (int i = 0; i < n; i ++) {
                result[m - 1][i] = ((i % 4 < 2) ? 'a' : 'b');
            } 
        } 

        for (int i = 0; i < m/2; i ++) {
            for (int j = 0; j < n/2; j ++) {
                result[i][j];
            }
        }

    }    

    return 0;
}