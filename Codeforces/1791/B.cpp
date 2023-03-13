#include <iostream>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int x = 0, y = 0;
  for (char c : s) {
    // if (c == 'L') {
    //   x--;
    // } else if (c == 'R') {
    //   x++;
    // } else if (c == 'U') {
    //   y++;
    // } else if (c == 'D') {
    //   y--;
    // }

    switch (c) {
    case 'L':
      x--;
      break;
    case 'R':
      x++;
      break;
    case 'U':
      y++;
      break;
    case 'D':
      y--;
      break;
    }

    if (x == 1 && y == 1) {
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
