#include<iostream>
#include<string>
#include<vector>

std::vector<int> upper, lower;

void solve() {
	int n, k; std::cin >> n >> k;
	std::string s; std::cin >> s;
	
	// be careful resize only assign value to the value added not the original
	upper.resize(26, 0);
	lower.resize(26, 0);

	for (int i = 0; i < 26; i ++) {
		upper[i] = 0;
		lower[i] = 0;
	}

	for (int i = 0; i < n; i ++) {
		if (s[i] >= 'a' && s[i] <= 'z') upper[s[i] - 'a'] ++;
		else if (s[i] >= 'A' && s[i] <= 'Z') lower[s[i] - 'A'] ++;
	}

	int ans = 0; int backup = 0;

	for (int i = 0; i < 26; i ++) {
		int mi = std::min(upper[i], lower[i]);
		int ma = std::max(upper[i], lower[i]);

		ans += mi;
		backup += (ma - mi) / 2;
	}

	std::cout << ans + std::min(backup, k) << std::endl;
}

int main() {

	int nTest; std::cin >> nTest;

	for (int i = 0; i < nTest; i ++) {
		solve();
	}

	return 0;
}
