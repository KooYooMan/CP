#include<bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int nTest; cin >> nTest;

	while (nTest --) {
		int k; cin >> k;
		for (int i = 1; ; i ++) {
			if (i % 10 == 3 || i % 3 == 0) continue;
			k --;
			if (k == 0) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}
