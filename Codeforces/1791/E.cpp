#include <iostream>

const int MAX_N = 2e5 + 10;

long long a[MAX_N];

void solve() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  long long foo = a[0], bar = -a[0];

  for (int i = 1; i < n; i++) {
    long long x = std::max(foo + a[i], bar - a[i]);
    long long y = std::max(foo - a[i], bar + a[i]);
    foo = x;
    bar = y;
  }

  std::cout << foo << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
