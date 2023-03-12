#include<iostream>
#include<string>

char chars[] = {'m', 'M', 'e', 'E', 'o', 'O', 'w', 'W'};

void solve() {
	int n; std::string s;
	std::cin >> n >> s;
	if (s[0] != 'm' && s[0] != 'M') {
		std::cout << "NO\n";
		return;
	}

	int state = 0;
	for (int i = 1; i < n; i ++) {
		if (s[i] == chars[2*state] || s[i] == chars[2*state+1]) {
			continue;
		}
		if (state < 3 && (s[i] == chars[2*state+2] || s[i] == chars[2*state+3])) {
			state ++;
			continue;
		}
		std::cout << "NO\n";
		return;
	}
	if (state < 3) {
		std::cout << "NO\n";
		return;
	}

	std::cout << "YES\n";
}

int main() {

	int nTest; std::cin >> nTest;

	for (int i = 0; i < nTest; i ++) {
		solve();
	}

	return 0;
}
