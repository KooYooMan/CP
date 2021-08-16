#include<bits/stdc++.h>
using namespace std;

const int INF = (int)2e9;
const int MAXN = 1e5 + 10;
int sum[MAXN];

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int m; cin >> m;
		for (int i = 1; i <= m; i ++) {
			int x; cin >> x;
			sum[i] = sum[i - 1] + x;
		}
		int culmulative_sum = 0;
		int ans = INF;
		for (int i = 1; i <= m; i ++) {
			int x; cin >> x;
			ans = min(ans, max(culmulative_sum, sum[m] - sum[i]));
			culmulative_sum = culmulative_sum + x;
		}
		cout << ans << "\n";	
	}

	return 0;
}
