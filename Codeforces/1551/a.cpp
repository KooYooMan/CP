#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

  int nTest; cin >> nTest;

  while (nTest --) {
    int n; cin >> n;
    cout << n/3 + (n%3 == 1) << " " << n/3 + (n%3 == 2) << "\n";
  }

  return 0;
}
