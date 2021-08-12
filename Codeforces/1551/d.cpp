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
            remain -= n/2;
        }
        if (remain < 0 || remain % 2) {
            cout << "NO\n";
            continue;
        }
				if (m * (n/2) < k) {
					cout << "NO\n";
					continue;
				}

        cout << "YES\n";

				for (int i = 0; i < m; i ++) {
					for (int j = 0; j < n; j ++) {
						result[i][j] = 'z';
					}
				}

        if (m % 2) {
            for (int i = 0; i < n; i ++) {
                result[m - 1][i] = ((i % 4 < 2) ? 'a' : 'b');
            } 
						k -= n/2;
        } 

        for (int i = 0; i < m/2; i ++) {
						if (k == 0) break;
						vector<char> color_list{'e', 'f', 'g', 'h'};
						if (i % 2) {
							color_list = vector<char>{'i', 'j', 'k', 'l'};
						}
            for (int j = 0; j < n/2; j ++) {
							if (k == 0) break;
							char primary = color_list[0], secondary = color_list[1];
							if (j % 2) {
								primary = color_list[2]; secondary = color_list[3];
							}
							result[2*i][2*j] = primary;
							result[2*i][2*j+1] = primary;
							result[2*i+1][2*j] = secondary;
							result[2*i+1][2*j+1] = secondary;
							k -= 2;
            }
        }
				for (int i = 0; i < m/2; i ++) {
					char primary = 'c', secondary = 'd';
					if (i % 2) {
						primary = 'm'; secondary = 'n';
					}
					for (int j = 0; j < n; j ++) {
						if (result[2*i][j] != 'z') continue; 
						char selected = (j % 2 == 0) ? primary : secondary;
						result[2*i][j] = selected;
						result[2*i+1][j] = selected;
					}
				}
				for (int i = 0; i < m; i ++) {
					for (int j = 0; j < n; j ++) {
						cout << result[i][j];
					}
					cout << "\n";
				}
    }    

    return 0;
}
