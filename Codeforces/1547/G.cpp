#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 10;

vector<int> g[MAXN];
int f[MAXN];
bool processing[MAXN];
bool visit[MAXN];

void dfs(int u) {
	visit[u] = true;
	processing[u] = true;
	f[u] = max(f[u], 1);
	for (int v: g[u]) {
		if (processing[v]) {
			f[v] = max(f[v], 3);
		} else if (visit[v]) {
			f[v] = max(f[v], 2);
		} else {
			dfs(v);
		}
	}
	processing[u] = false;
}

void dfs_update(int u) {
	int value = f[u];
	for (int v: g[u]) {
		if (value > f[v]) {
			f[v] = value;
			dfs_update(v);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int nTest; cin >> nTest;

	while (nTest --) {
		int n, m; cin >> n >> m;

		for (int i = 0; i < m; i ++) {
			int u, v; cin >> u >> v;
			u --; v --;
			g[u].push_back(v);
		}

		dfs(0);
		for (int i = 0; i < n; i ++) {
			dfs_update(i);
		}
		for (int i = 0; i < n; i ++) {
			if (f[i] == 3) f[i] = -1;
			cout << f[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n; i ++) {
			g[i].clear();
			f[i] = 0;
			processing[i] = false;
			visit[i] = false;
		}
	}
 
	return 0;
}
