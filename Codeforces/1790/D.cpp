#include <algorithm>
#include <iostream>

const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a, a + n);
  int lastCount = 0;
  int count = 1;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      count++;
    } else {
      ans += std::max(0, count - lastCount);
      if (a[i - 1] + 1 == a[i])
        lastCount = count;
      else
        lastCount = 0;
      count = 1;
    }
  }
  ans += std::max(0, count - lastCount);
  std::cout << ans << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
