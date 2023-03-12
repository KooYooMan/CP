#include<iostream>
#include<algorithm>

void solve() {
	int n, k; std::cin >> n >> k;
	std::string s, t; std::cin >> s >> t;

	std::string s_temp = s;
	std::string t_temp = t;
	std::sort(s_temp.begin(), s_temp.end());
	std::sort(t_temp.begin(), t_temp.end());

	if (s_temp != t_temp) {
		std::cout << "NO\n";
		return;
	}

	int l = 0, r = n - 1;

	if (k < n) {
		r = k - 1;
		l = n - k;
	}

	for (int i = l; i <= r; i ++) {
		if (s[i] != t[i]) {
			std::cout << "NO\n";
			return;
		}
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
