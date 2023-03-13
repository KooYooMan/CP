#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_N = 2e5 + 10;

int a[MAX_N];
long long candidates[MAX_N];
long long sum[MAX_N];

void solve() {
  int n, c;
  std::cin >> n >> c;

  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    candidates[i] = 1ll * std::min(i + a[i], n + 1 - i + a[i]);
  }
  std::sort(candidates + 1, candidates + n + 1);

  // for (int i = 1; i <= n; i++)
  //   std::cout << candidates[i] << " ";
  // std::cout << "\n";

  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + candidates[i];
  }

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int f = i + a[i];
    if (f > c)
      continue;
    long long new_c = 1ll * (c - f);

    long long v = 1ll * std::min(i + a[i], n + 1 - i + a[i]);

    int l = 0, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (sum[mid] <= new_c)
        l = mid;
      else
        r = mid - 1;
    }

    // if (i == 5) {
    //   std::cout << "l is " << l << std::endl;
    // }

    if (v <= candidates[l]) {
      if (l == n || sum[l] - v + candidates[l + 1] > new_c)
        l--;
    }

    // std::cout << i << " " << l + 1 << "\n";

    ans = std::max(ans, l + 1);
  }

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
