#include <algorithm>
#include <iostream>
#include <vector>

int a[110][110];

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> heads;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      std::cin >> a[i][j];
    }
    if (i < 3) {
      heads.push_back(a[i][0]);
    }
  }
  std::sort(heads.begin(), heads.end());
  int first_value = (heads[0] == heads[1] ? heads[0] : heads[1]);
  for (int i = 0; i < n; i++) {
    if (a[i][0] != first_value) {
      std::cout << first_value << " ";
      for (int j = 0; j < n - 1; j++) {
        std::cout << a[i][j] << " ";
      }
      std::cout << "\n";
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
