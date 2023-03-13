#include <iostream>
#include <vector>

void solve() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<int> num(26, 0);
  std::vector<int> current(26, 0);

  for (char c : s) {
    num[c - 'a']++;
  }

  int ans = 0;
  int count = 0;

  for (int i = 0; i < 26; i++) {
    if (num[i] > 0)
      count++;
  }

  // std::cout << ans << " " << count << "\n";

  for (char c : s) {
    if (current[c - 'a'] == 0)
      count++;

    current[c - 'a']++;

    if (current[c - 'a'] == num[c - 'a'])
      count--;

    ans = std::max(ans, count);
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
