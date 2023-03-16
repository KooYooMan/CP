#include <iostream>
#include <queue>
#include <set>
#include <vector>

const int MAX_N = 2e5 + 10;

std::vector<int> g[MAX_N];
bool token[MAX_N];
bool bonus[MAX_N];
bool visit[MAX_N];
bool adj_bonus[MAX_N];
int distance[MAX_N];

void solve() {
  int n, m;
  std::cin >> n >> m;
  int p, b;
  std::cin >> p >> b;

  for (int i = 0; i < n; i++)
    g[i].clear();

  for (int i = 0; i < n; i++)
    token[i] = false;

  for (int i = 0; i < n; i++)
    bonus[i] = false;

  for (int i = 0; i < n; i++)
    visit[i] = false;

  for (int i = 0; i < n; i++)
    adj_bonus[i] = false;

  for (int i = 0; i < n; i++) {
    distance[i] = int(1e9); // infinity
  }

  for (int i = 0; i < p; i++) {
    int pos;
    std::cin >> pos;
    pos--;
    token[pos] = true;
  }

  for (int i = 0; i < b; i++) {
    int pos;
    std::cin >> pos;
    pos--;
    bonus[pos] = true;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    if (bonus[u])
      adj_bonus[v] = true;
    if (bonus[v])
      adj_bonus[u] = true;
  }

  std::set<int> good, not_so_good;
  for (int u = 0; u < n; u++) {
    if (!token[u])
      continue;
    if (adj_bonus[u]) {
      bool ok = false;
      for (int v : g[u]) {
        if (bonus[v] && adj_bonus[v]) {
          good.insert(u);
          ok = true;
          break;
        }
      }
      if (!ok) {
        not_so_good.insert(u);
      }
    }
  }

  std::queue<int> q;
  q.push(0);
  visit[0] = true;
  distance[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (visit[v])
        continue;
      distance[v] = distance[u] + 1;
      visit[v] = true;
      if (!bonus[v])
        continue;
      q.push(v);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!token[i])
      continue;
    if (distance[i] > n)
      continue;

    if (!good.empty() && (*good.begin() != i || *good.rbegin() != i)) {
      std::cout << "YES\n";
      return;
    }

    int x = (int)not_so_good.size() - not_so_good.count(i);
    int y = distance[i] - 1;

    if (x >= y) {
      std::cout << "YES\n";
      return;
    }
  }

  std::cout << "NO\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
