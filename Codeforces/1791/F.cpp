#include <iostream>
#include <set>
#include <vector>

const int MAX_N = 2e5 + 10;
int a[MAX_N];

int sum_digit(int value) {
  int sum = 0;
  while (value) {
    sum += value % 10;
    value /= 10;
  }
  return sum;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::set<int> s;

  for (int i = 0; i < n; i++) {
    s.insert(i);
  }

  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  while (q--) {
    int type;
    std::cin >> type;

    if (type == 1) {
      int l, r;
      std::cin >> l >> r;
      l--;
      r--;
      while (!s.empty()) {
        std::set<int>::iterator l_pointer = s.lower_bound(l);
        if (l_pointer == s.end() || *l_pointer > r)
          break;

        a[*l_pointer] = sum_digit(a[*l_pointer]);
        l = *l_pointer + 1;

        if (a[*l_pointer] < 10)
          s.erase(l_pointer);
      }
    } else {
      int x;
      std::cin >> x;
      x--;
      std::cout << a[x] << "\n";
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
