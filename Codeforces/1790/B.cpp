#include <iostream>

void solve() {
  int n, s, r;
  std::cin >> n >> s >> r;

  int maximum = s - r;

  for (int i = 1; i <= n; i++) {
    int remain = s - i * maximum;
    if (i == n) {
      for (int j = 1; j <= n; j++)
        std::cout << maximum << " ";
      std::cout << "\n";
      return;
    }

    if (remain / (n - i) < maximum) {
      int sl = remain % (n - i);
      for (int j = 1; j <= i; j++)
        std::cout << maximum << " ";
      for (int j = 1; j <= sl; j++)
        std::cout << remain / (n - i) + 1 << " ";
      for (int j = 1; j <= n - i - sl; j++)
        std::cout << remain / (n - i) << " ";
      std::cout << "\n";
      return;
    }
  }
}

int main() {

  int nTest;
  std::cin >> nTest;

  while (nTest--) {
    solve();
  }

  return 0;
}
