#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int a[MAXN];
int dp[MAXN][MAXN];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int n, k; cin >> n >> k;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				dp[i][j] = 0;
			}
		}

		if (a[0] == 1) {
			dp[0][0] = 1;
		}
		
		for (int pos = 1; pos < n; pos ++) {
			for (int num_del = 0; num_del <= pos; num_del ++) {
				dp[pos][num_del] = dp[pos-1][num_del-1]; 
				if (num_del <= pos) {
					dp[pos][num_del] = max(dp[pos][num_del], dp[pos-1][num_del] + (a[pos] == pos + 1 - num_del));
				}
			}
		}

		int ans = -1;

		for (int i = 0; i < n; i ++) {
			if (dp[n-1][i] >= k) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}
