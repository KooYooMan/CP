#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;
	
	while (nTest --) {
		long long n; cin >> n;
		if (n <= 6) {
			cout << 15 << "\n";
		} else {
			cout << 5 * ((n + 1) / 2) << "\n";
		}
	}

	return 0;
}
