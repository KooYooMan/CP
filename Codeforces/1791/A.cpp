#include <iostream>

int main() {

  int nTest;
  std::cin >> nTest;

  std::string s = "codeforces";

  while (nTest--) {
    char c;
    std::cin >> c;
    bool found = false;

    for (char c_s : s) {
      if (c == c_s) {
        found = true;
      }
    }
    if (found) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }

  return 0;
}
