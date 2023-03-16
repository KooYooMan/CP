#include <cmath>
#include <iostream>

void solve() {
  std::string p =
      "31415926535897932384626433832795028841971693993751058209749445923078164";
  std::string s;
  std::cin >> s;

  int ans = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == p[i]) {
      ans++;
    } else {
      break;
    }
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
