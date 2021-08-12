#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MOD = 1e9 + 7;
int n, k;
vector<int> g[MAXN];
long long num[MAXN][MAXN];
long long dp[MAXN][MAXN];

void dfs(int u, int dad) {
	for (int depth = 1; depth <= n; depth ++) {
		num[u][depth] = 0;
	}
	num[u][0] = 1;

	for (int v: g[u]) {
		if (v == dad) continue;
		dfs(v, u);
		for (int depth = 1; depth <= n; depth ++) {
			num[u][depth] += num[v][depth - 1];
			num[u][depth] %= MOD;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	
	int nTest; cin >> nTest;

	while (nTest --) {
		cin >> n >> k;

		long long ans = 0;

		for (int i = 0; i < n-1; i ++) {
			int u, v; cin >> u >> v;
			u --; v --;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if (k == 2) {
			cout << (n * (n-1) / 2) % MOD << "\n";
		} else {

			for (int u = 0; u < n; u ++) {
				dfs(u, -1);

				for (int dis = 0; dis <= n; dis ++) {
					dp[dis][0] = 1;
				}

				for (int v: g[u]) {
					for (int dis = 1; dis <= n; dis ++) {
						for (int node = k; node >= 1; node --) {
							dp[dis][node] += (dp[dis][node - 1] * num[v][dis - 1]) % MOD;
							dp[dis][node] %= MOD;
						}
					}
				}

				for (int dis = 1; dis <= n; dis ++) {
					ans += dp[dis][k];
					ans %= MOD;
				}

				for (int dis = 0; dis <= n; dis ++) {
					for (int node = 0; node <= k; node ++) {
						dp[dis][node] = 0;
					}
				}
			}
				
			cout << ans << "\n";
		}
		
		for (int i = 0; i < n; i ++) {
			g[i].clear();
			for (int j = 0; j <= n; j ++) {
				num[i][j] = 0;
			}
		}
	}

	return 0;
}
