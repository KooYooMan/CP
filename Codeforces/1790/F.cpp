#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 10;

std::vector<int> g[MAX_N];
int d[MAX_N];
bool isBlack[MAX_N];
int vertex[MAX_N];

void dfs(int u, int p, int &ans) {
  if (d[u] >= ans)
    return;
  for (int v : g[u]) {
    if (v == p)
      continue;
    ans = std::min(ans, d[u] + d[v] + 1);
    if (d[v] > d[u] + 1) {
      d[v] = d[u] + 1;
      dfs(v, u, ans);
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  // reset data
  for (int i = 0; i < n; i++)
    d[i] = int(1e9); // inifinity
  for (int i = 0; i < n; i++)
    isBlack[i] = false;
  for (int i = 0; i < n; i++)
    g[i].clear();

  int initial_black;
  std::cin >> initial_black;
  initial_black--;

  for (int i = 0; i < n - 1; i++) {
    std::cin >> vertex[i];
    vertex[i]--;
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  isBlack[initial_black] = true;
  d[initial_black] = 0;
  int ans = (int)1e9; // inifinity
  dfs(initial_black, -1, ans);

  for (int i = 0; i < n - 1; i++) {
    int v = vertex[i];
    if (isBlack[v]) {
      std::cout << ans << "\n";
    }
    isBlack[v] = true;
    d[v] = 0;
    dfs(v, -1, ans);
    std::cout << ans << " ";
  }

  std::cout << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
