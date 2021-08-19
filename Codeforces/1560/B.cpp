#include<bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int a, b, c; cin >> a >> b >> c;
		int diff = max(a, b) - min(a, b);
		if (max(a, max(b, c)) > 2 * diff) {
			cout << -1 << "\n";
			continue;
		}
		cout << ((c - diff >= 1) ? (c - diff) : (c + diff)) << "\n";
	}

	return 0;
}
