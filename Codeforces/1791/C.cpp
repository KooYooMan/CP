#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  if (n == 0) {
    std::cout << 0 << "\n";
    return;
  }
  int l = 0, r = n - 1;
  int ans = 0;
  while (l < r) {
    if (s[l] != s[r]) {
      l++;
      r--;
      ans++;
    } else {
      break;
    }
  }
  std::cout << n - 2 * ans << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
