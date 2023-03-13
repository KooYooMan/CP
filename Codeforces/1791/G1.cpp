#include <algorithm>
#include <iostream>

const int MAX_N = 2e5 + 10;

long long a[MAX_N];

void solve() {
  int n, c;
  std::cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[i] = 1ll * (x + i);
  }
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (a[mid] <= 1ll * c)
      l = mid;
    else
      r = mid - 1;
  }
  std::cout << l << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
