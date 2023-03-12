#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 4e5 + 10;

vector<int> g[MAXN];
vector<int> g_rev[MAXN];
vector< pair<int, int> > edges;
vector<int> order;

bool visited[MAXN];

void dfs(int u) {
	visited[u] = true;
	for (int v: g[u]) {
		if (visited[v]) continue;
		dfs(v);
	}
	order.push_back(u);
}

void dfs_rev(int u, vector<int>&component) {
	visited[u] = true;
	component.push_back(u);
	for (int v: g_rev[u]) {
		if (visited[v]) continue;
		dfs_rev(v, component);
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i ++) {
		int u, v; cin >> u >> v;
		u --; v --;
		g[u].push_back(v);
		g_rev[v].push_back(u);
	}

	for (int i = 0; i < n; i ++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i ++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	for (int i = 0; i < n; i ++) {
		visited[i] = false;
	}
	reverse(order.begin(), order.end());

	for (int i: order) {
		if (!visited[i]) {
			vector<int> component{};
			dfs_rev(i, component);
			cout << "Found Component: \n";
			for (int u: component) {
				cout << u << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}

/* 
 * Sample Data
6 7
1 4
3 1
4 3
4 5
2 1
5 5
5 6
*/
