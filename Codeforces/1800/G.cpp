#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int MAX_N = 2e5 + 10;

std::vector<int> g[MAX_N];
std::map<std::vector<int>, int> f;
bool isSymmetrical[MAX_N];

int id;

int dfs(int u, int p) {
	std::vector<int> children;
	children.clear();

	for (int v: g[u]) {
		if (v == p) continue;
		children.push_back(dfs(v, u));
	}

	std::sort(children.begin(), children.end());

	if (f.find(children) == f.end()) {
		int bad = 0;
		bool ok = true;
		int count = 0;

		for (int i = 0, s = children.size(); i < s; i ++) {
			if (i == 0) {
				count ++;
				continue;
			}

			if (children[i] != children[i-1]) {
				if (count % 2) {
					bad ++;
					if (!isSymmetrical[children[i-1]]) {
						ok = false;
					}
					count = 1;
				}
			} else {
				count ++;
			}

		}

		if (count % 2) {
			bad ++;
			if (!isSymmetrical[children[children.size()-1]]) {
				ok = false;
			}
		}

		isSymmetrical[id] = ((bad < 2) && ok);
		f[children] = id ++;
	}

	return f[children];
}

void solve() {
	int n; std::cin >> n;

	f.clear();
	id = 0;
	for (int i = 0; i < n; i ++) g[i].clear();

	for (int i = 1; i < n; i ++) {
		int u, v; std::cin >> u >> v;
		u --; v --;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int final_id = dfs(0, -1);
	if (isSymmetrical[final_id]) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {

	int nTest; std::cin >> nTest;

	while (nTest --) {
		solve();
	}

	return 0;
}
