#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
const int MAXQ = 5e5 + 10;

struct Query {
	int u;
	int v;
	int id;
	int w;
	Query(): u(0), v(0), id(0), w(0) {}
	Query(int _id, int _u, int _v, int _w): u(_u), v(_v), id(_id), w(_w) {}
} listQuery[MAXQ];

int n, q;
int nQuery = 0;
vector<pair<int, int>> g[MAXN];
bool result[MAXQ];

int dsu[MAXN];

int getDsu(int u) {
	if (!dsu[u]) return u;
	return dsu[u] = getDsu(dsu[u]);
}

int dad[20][MAXN];
int level[MAXN];
int tin[MAXN], tout[MAXN], tick;
int Xor[MAXN];

void dfs(int u, int da) {
	tin[u] = ++ tick;
	for (auto edge: g[u]) {
		int v = edge.first, w = edge.second;
		if (v == da) {
			continue;
		}
		Xor[v] = Xor[u] ^ w;
		dad[0][v] = u;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
	tout[u] = ++ tick;
}

void buildLCA() {
	for (int i = 1; i <= n; i ++) {
		if (dad[0][i]) continue;
		dfs(i, 0);
	}

	for (int i = 1; i < 20; i ++) {
		for (int u = 1; u <= n; u ++) {
			dad[i][u] = dad[i - 1][dad[i - 1][u]];
		}
	}
}

int getLCA(int u, int v) {
	if (level[u] < level[v]) {
		swap(u, v);
	}
	for (int i = 19; i >= 0; i --) {
		if (level[u] - (1 << i) >= level[v]) {
			u = dad[i][u];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; i --) {
		if (dad[i][u] != dad[i][v]) {
			u = dad[i][u];
			v = dad[i][v];
		}
	}
	return dad[0][u];
}

int f[2 * MAXN];

void update(int pos, int value) {
	while (pos <= 2 * n) {
		f[pos] += value;
		pos += pos & (-pos);
	}
}

int get(int pos) {
	int ans = 0;
	while (pos) {
		ans += f[pos];
		pos -= pos & (-pos);
	}
	return ans;
}

void fill(int u, int da) {
	while (u != da) {
		update(tin[u], 1);
		update(tout[u], -1);
		u = dad[0][u];
	}
}

int main() {
	freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
	
	cin >> n >> q;

	for (int i = 0; i < q; i ++) {
		int u, v, w; cin >> u >> v >> w;
		int dadu = getDsu(u), dadv = getDsu(v);
		if (dadu == dadv) {
			Query newQuery = Query(i, u, v, w);
			listQuery[nQuery ++] = newQuery;
		} else {
			result[i] = true;
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
			dsu[dadv] = dadu;
		}
	}

	buildLCA();
	
	for (int i = 0; i < nQuery; i ++) {
		int u = listQuery[i].u, v = listQuery[i].v, w = listQuery[i].w, id = listQuery[i].id;
		result[id] = false;
		int lca = getLCA(u, v);
		int sum_path = get(tin[u]) + get(tin[v]) - 2 * get(tin[lca]);
		if (sum_path > 0) continue;
		int xor_path = Xor[u] ^ Xor[v];
		if ((xor_path ^ w) != 1) continue;
		result[id] = true;
		fill(u, lca);
		fill(v, lca);
	}

	for (int i = 0; i < q; i ++) {
		if (result[i]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
 
	return 0;
}
