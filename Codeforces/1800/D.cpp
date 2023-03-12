#include<iostream>
#include<string>

void solve() {
	int n; std::cin >> n;
	std::string s; std::cin >> s;
	int ans = n - 1;
	for (int i = 0; i < n - 2; i ++) {
		if (s[i] == s[i + 2]) ans --;
	}
	std::cout << ans << "\n";
}

int main() {

	int nTest; std::cin >> nTest;

	for (int i = 0; i < nTest; i ++) {
		solve();
	}

	return 0;
}
