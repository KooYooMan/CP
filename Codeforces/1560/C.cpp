#include<bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int nTest; cin >> nTest;

	while (nTest --) {
		int k; cin >> k;
		int x = (int)sqrt(k);
		if (x * x >= k) x --;
		int remain = k - x * x;
		if (remain > x) {
			cout << x + 1 << " " << x + 1 - (remain - x - 1) << "\n";
		} else {
			cout << remain << " " << x + 1 << "\n";
		}
	}

	return 0;
}
