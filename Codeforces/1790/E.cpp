#include <iostream>

void solve() {
  int x;
  std::cin >> x;
  int a = 0, b = 0;
  for (int i = 30; i >= 0; i--) {
    if (!(x & (1 << i)))
      continue;
    i--;
    if (i < 0 || (x & (1 << i))) {
      std::cout << -1 << "\n";
      return;
    }
    a += (1 << i) + (1 << (i + 1));
    b += (1 << i);
  }
  std::cout << a << " " << b << "\n";
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
